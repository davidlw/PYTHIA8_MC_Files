// main36.cc is a part of the PYTHIA event generator.
// Copyright (C) 2020 Torbjorn Sjostrand.
// PYTHIA is licenced under the GNU GPL v2 or later, see COPYING for details.
// Please respect the MCnet Guidelines, see GUIDELINES for details.

// Keywords: basic usage; DIS;

// Basic setup for Deeply Inelastic Scattering at HERA.

// Header file to access Pythia 8 program elements.
#include "Pythia8/Pythia.h"

// ROOT, for saving Pythia events as trees in a file.
#include "TTree.h"
#include "TFile.h"

// ROOT, for histogramming.
#include "TH1.h"
#include "TH2.h"

using namespace Pythia8;

int main() {

  // Beam energies, minimal Q2, number of events to generate.

  double eProton   = 275.;
  double eElectron = 18.;
/*
  double eProton   = 7000.;
  double eElectron = 50.;
*/
  double Q2min     = 1.;
  int    nEvent    = 500000;

  // Generator. Shorthand for event.
  Pythia pythia;
  Event& event = pythia.event;

  // Set up incoming beams, for frame with unequal beam energies.
  pythia.readString("Beams:frameType = 2");
  // BeamA = proton.
  pythia.readString("Beams:idA = 2212");
  pythia.settings.parm("Beams:eA", eProton);
  // BeamB = electron.
  pythia.readString("Beams:idB = 11");
  pythia.settings.parm("Beams:eB", eElectron);

  // Set up DIS process within some phase space.
  // Neutral current (with gamma/Z interference).
  pythia.readString("WeakBosonExchange:ff2ff(t:gmZ) = on");
  // Uncomment to allow charged current.
  //pythia.readString("WeakBosonExchange:ff2ff(t:W) = on");
  // Phase-space cut: minimal Q2 of process.
  pythia.settings.parm("PhaseSpace:Q2Min", Q2min);

  // Set dipole recoil on. Necessary for DIS + shower.
  pythia.readString("SpaceShower:dipoleRecoil = on");

  // Allow emissions up to the kinematical limit,
  // since rate known to match well to matrix elements everywhere.
  pythia.readString("SpaceShower:pTmaxMatch = 2");

  // QED radiation off lepton not handled yet by the new procedure.
  pythia.readString("PDF:lepton = off");
  pythia.readString("TimeShower:QEDshowerByL = off");

  // Initialize.
  pythia.init();

  // Histograms.
  double Wmax = sqrt(4.* eProton * eElectron);
  TH1D* Nchhist = new TH1D("Nch","N_{ch}", 500, 0., 500.);
  TH1D* Qhist = new TH1D("Qhist","Q [GeV]", 2000, 0., 1000.);
  TH1D* Whist = new TH1D("Whist","W [GeV]", 1000, 0., Wmax);
  TH1D* xhist = new TH1D("xhist","x", 1000000, 0., 1.);
  TH1D* yhist = new TH1D("yhist","y", 1000, 0., 1.);
  TH1D* pTehist = new TH1D("pTehist","pT of scattered muon [GeV]", 1000, 0., 500.);
  TH1D* pTrhist = new TH1D("pTrhist","pT of radiated parton [GeV]", 1000, 0., 500.);
  TH1D* pTdhist = new TH1D("pTdhist","ratio pT_parton/pT_muon", 100, 0., 5.);
  TH2D* Q2xhist = new TH2D("Q2xhist",";x;Q^{2} [GeV]", 100000, 0.000005, 1., 200, 1., 200.);
  TH2D* Q2xhist_eta = new TH2D("Q2xhist_eta",";x;Q^{2} [GeV]", 100000, 0.000005, 1., 200, 1., 200.);

  TH2D* petahadhist = new TH2D("petahadhist",";#eta;p [GeV]", 80, -8., 8., 800, 0., 200.);
  TH2D* petamuhist = new TH2D("petamuhist",";#eta;p [GeV]", 80, -8., 8., 1000, 0., 1000.);

  // Set up the ROOT TFile and TTree.
  TFile *file = TFile::Open("pytree_ep_eic_ycut001.root","recreate");
//  Event *event = &pythia.event;
  TTree *T = new TTree("T","ev1 Tree");
  T->Branch("event",&event);

  // Begin event loop.
  for (int iEvent = 0; iEvent < nEvent; ++iEvent) {
    if (!pythia.next()) continue;

    // Four-momenta of proton, electron, virtual photon/Z^0/W^+-.
    Vec4 pProton = event[1].p();
    Vec4 peIn    = event[4].p();
    Vec4 peOut   = event[6].p();
    Vec4 pPhoton = peIn - peOut;

    // Q2, W2, Bjorken x, y.
    double Q2    = - pPhoton.m2Calc();
    double W2    = (pProton + pPhoton).m2Calc();
    double x     = Q2 / (2. * pProton * pPhoton);
    double y     = (pProton * pPhoton) / (pProton * peIn);

    // Fill kinematics histograms.
    Qhist->Fill( sqrt(Q2) );
    Whist->Fill( sqrt(W2) );
    xhist->Fill( x );
    yhist->Fill( y );
    pTehist->Fill( event[6].pT() );
    Q2xhist->Fill( x, Q2 );
    if(fabs(event[6].eta())<4) Q2xhist_eta->Fill( x, Q2 );

    if(y>0.95 || y<0.01) continue;

    petamuhist->Fill( event[6].eta(), event[6].pT()*cosh(event[6].eta()) );

    // pT spectrum of partons being radiated in shower.
    for (int i = 0; i < event.size(); ++i)
    {
      if (event[i].statusAbs() == 43) {
        pTrhist->Fill( event[i].pT() );
        pTdhist->Fill( event[i].pT() / event[6].pT() );
      }
      if (event[i].statusAbs() <=89 && event[i].statusAbs() >=81) {
        petahadhist->Fill( event[i].eta(), event[i].pT()*cosh(event[i].eta()) );
      }
    }

    T->Fill();

  // End of event loop. Statistics and histograms.
  }
  pythia.stat();
  cout << Qhist << Whist << xhist << yhist << pTehist << pTrhist << pTdhist;

  //  Write tree.
  T->Print();
  T->Write();
  Qhist->Write();
  Whist->Write();
  xhist->Write();
  yhist->Write();
  pTehist->Write();
  pTrhist->Write();
  pTdhist->Write();
  Q2xhist->Write();
  Q2xhist_eta->Write();
  petahadhist->Write();
  petamuhist->Write();

  delete file;

  // Done.
  return 0;
}
