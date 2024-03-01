#include "fastjet/ClusterSequence.hh"
#include "fastjet/PseudoJet.hh"
#include "Pythia8/Pythia.h"
#include "TMath.h"
#include "TTree.h"
#include "TBranch.h"
#include "TFile.h"
#include "TSystem.h"
#include "TInterpreter.h"
#include <vector>

using namespace Pythia8;
using namespace fastjet;
#include <iostream>

int main() {
  gInterpreter->GenerateDictionary("vector<vector<float> >", "vector");
  gInterpreter->GenerateDictionary("vector<vector<int> >", "vector");

  //*********************************************** PYTHIA SETTINGS **************************************************
  Pythia pythia;
  Event& event = pythia.event;

  pythia.readString("Beams:frameType = 2");
  //proton
  pythia.readString("Beams:idA = 2212");
  //electron
//  pythia.readString("Beams:idB = 11");
  //muon
  pythia.readString("Beams:idB = 13");

  //specify the beam energies
  //electron: 5-30 GeV for EIC
  //proton:   50-250 GeV for EIC
  //muon ion collider: 960 GeV muon, 275 GeV proton
  pythia.readString("Beams:eA = 275");
//  pythia.readString("Beams:eB = 18");
  pythia.readString("Beams:eB = 960");
  
  //neutral current
  pythia.readString("WeakBosonExchange:ff2ff(t:gmZ) = on");
  //charged current
//  pythia.readString("WeakBosonExchange:ff2ff(t:W) = on");
  pythia.readString("HiggsSM:ff2Hff(t:WW) = on");  
//  pythia.readString("PartonLevel:all = off");

  //minimum Q2 cut
  pythia.settings.parm("PhaseSpace:Q2Min", 50000.0);

//  pythia.settings.parm("PhaseSpace:pTHatMin", 500.0);

  //needed setting for DIS + showering
  pythia.readString("SpaceShower:dipoleRecoil = on");

  // Allow emissions up to the kinematical limit,
  // since rate known to match well to matrix elements everywhere.
  pythia.readString("SpaceShower:pTmaxMatch = 2");

  // QED radiation off lepton not handled yet by the new procedure.
  pythia.readString("PDF:lepton = off");
  pythia.readString("TimeShower:QEDshowerByL = off");
  pythia.init();

  
  //*********************************************** ROOT SETUP  **************************************************

  float Q2,W2,x,y;  
  float thrust, ptthr, etathr, phithr;
  float genLeptonEta, genLeptonPt, genLeptonPhi;

  std::vector< float > genJetPt;
  std::vector< float > genJetEta;
  std::vector< float > genJetPhi;
  std::vector< int >   genJetChargedMultiplicity;
  std::vector< std::vector<int> > gendau_chg;
  std::vector< std::vector<int> > gendau_pid;
  std::vector< std::vector<float> > gendau_pt;
  std::vector< std::vector<float> > gendau_eta;
  std::vector< std::vector<float> > gendau_phi;
  std::vector< int > genpar_chg;
  std::vector< int > genpar_pid;
  std::vector< float > genpar_pt;
  std::vector< float > genpar_eta;
  std::vector< float > genpar_phi;

//  TFile * f = TFile::Open("EIC_mu18_p275_Q21000_ak10.root","recreate");
//  TFile * f = TFile::Open("MuIC_mu960_p275_Q21000_ak10.root","recreate");
  TFile * f = TFile::Open("MuIC_mu960_p275_Q250000_higgs.root","recreate");
  TTree * trackTree = new TTree("trackTree","v1");
 
  trackTree->Branch("Q2",&Q2);
  trackTree->Branch("W2",&W2);
  trackTree->Branch("x",&x);
  trackTree->Branch("y",&y);

  trackTree->Branch("thrust",&thrust);
  trackTree->Branch("ptthr",&ptthr);
  trackTree->Branch("etathr",&etathr);
  trackTree->Branch("phithr",&phithr);

  trackTree->Branch("genLeptonEta",&genLeptonEta);
  trackTree->Branch("genLeptonPt",&genLeptonPt);
  trackTree->Branch("genLeptonPhi",&genLeptonPhi);

  trackTree->Branch("genJetEta",&genJetEta);
  trackTree->Branch("genJetPt",&genJetPt);
  trackTree->Branch("genJetPhi",&genJetPhi);
  trackTree->Branch("genJetChargedMultiplicity",&genJetChargedMultiplicity);

  trackTree->Branch("genDau_chg",		&gendau_chg); 
  trackTree->Branch("genDau_pid",		&gendau_pid);	 
  trackTree->Branch("genDau_pt",		&gendau_pt);
  trackTree->Branch("genDau_eta",		&gendau_eta);	 
  trackTree->Branch("genDau_phi",		&gendau_phi );

  trackTree->Branch("genPar_chg",               &genpar_chg);
  trackTree->Branch("genPar_pid",               &genpar_pid);
  trackTree->Branch("genPar_pt",                &genpar_pt);
  trackTree->Branch("genPar_eta",               &genpar_eta);
  trackTree->Branch("genPar_phi",               &genpar_phi);

  //******************************************** ANALYZER ********************************************************

  //jet clustering
  // choose a jet definition
  double R = 1.0;
  JetDefinition jet_def(antikt_algorithm, R);

  Thrust thr;

  // Begin event loop.
  int nEvent = 50000;
  for (int iEvent = 0; iEvent < nEvent; ++iEvent) {
    if (!pythia.next()) continue;

    // Four-momenta of proton, electron, virtual photon/Z^0/W^+-.
    Vec4 pProton = event[1].p();
    Vec4 peIn    = event[4].p();
    Vec4 peOut   = event[6].p();
    Vec4 pPhoton = peIn - peOut;

    genLeptonEta = peOut.eta();
    genLeptonPt = peOut.pT();
    genLeptonPhi = peOut.phi();  

    // Q2, W2, Bjorken x, y.
    Q2    = - pPhoton.m2Calc();
    W2    = (pProton + pPhoton).m2Calc();
    x     = Q2 / (2. * pProton * pPhoton);
    y     = (pProton * pPhoton) / (pProton * peIn);
    if(y<0.001 || y>0.99) continue;

    //getting pythia particle info
    vector<PseudoJet> particles;
    int multiplicity = 0;

    // Find and histogram thrust.
    if (thr.analyze( pythia.event )) {
      if (iEvent < 3) thr.list();
      thrust = thr.thrust();
      ptthr = thr.eventAxis(1).pT();
      etathr = thr.eventAxis(1).eta();
      phithr = thr.eventAxis(1).phi();
    }

    //start loop at i=7 because we want to exclude the scattered lepton (which is i=6 index)
    for (int i = 7; i < pythia.event.size(); ++i){
if(fabs((pythia.event[i]).id())==25) cout<<"Found a Higgs!"<<endl;

      if (pythia.event[i].isFinal()){
        //basic kinematic cuts

        if( TMath::Abs( pythia.event[i].eta() ) > 10 || pythia.event[i].pT() < 0.001) continue;
        PseudoJet pj = PseudoJet(   pythia.event[i].px(),  pythia.event[i].py(),  pythia.event[i].pz(), pythia.event[i].e() );
        pj.set_user_index(i);
        particles.push_back( pj );

        genpar_pt.push_back((pythia.event[i]).pT());
        genpar_eta.push_back((pythia.event[i]).eta());
        genpar_phi.push_back((pythia.event[i]).phi());
        genpar_chg.push_back((pythia.event[i]).charge());
        genpar_pid.push_back((pythia.event[i]).id());

        if( pythia.event[i].isCharged() ) multiplicity++;
      }
    }

    // run the clustering, extract the jets
    ClusterSequence cs(particles, jet_def);
    vector<PseudoJet> jets = sorted_by_pt(cs.inclusive_jets());

    //loop over jets
    for (unsigned i = 0; i < jets.size(); i++) {
      if(jets[i].pt() < 1) continue;
      genJetPt.push_back(jets[i].pt());
      genJetEta.push_back(jets[i].eta());
      genJetPhi.push_back(jets[i].phi());

      //loop over constituents
      std::vector< float > tmp_pt;
      std::vector< float > tmp_eta;
      std::vector< float > tmp_phi;
      std::vector< int > tmp_chg;
      std::vector< int > tmp_pid;
      vector<PseudoJet> constituents = jets[i].constituents();
      int chMult = 0;
      for (unsigned j = 0; j < constituents.size(); j++) {
        if( ( pythia.event[ constituents[j].user_index() ] ).isCharged()){
          chMult++;
        }
        tmp_pt.push_back(constituents[j].pt());
        tmp_eta.push_back(constituents[j].eta());
        tmp_phi.push_back(constituents[j].phi());
        tmp_chg.push_back( (pythia.event[constituents[j].user_index()]).charge() );
        tmp_pid.push_back( (pythia.event[constituents[j].user_index()]).id() );
      }
      genJetChargedMultiplicity.push_back(chMult);
      gendau_pt.push_back(tmp_pt);
      gendau_eta.push_back(tmp_eta);
      gendau_phi.push_back(tmp_phi);
      gendau_chg.push_back(tmp_chg);
      gendau_pid.push_back(tmp_pid);
    }

    //fill and clear branches
    trackTree->Fill();
    x=0;
    y=0;
    Q2=0;
    W2=0;
    thrust=0;
    ptthr=0;
    etathr=0;
    phithr=0;
    genLeptonEta=0;
    genLeptonPt=0;
    genLeptonPhi=0;
    genJetPt.clear();
    genJetEta.clear();
    genJetPhi.clear();
    genJetChargedMultiplicity.clear();
    gendau_chg.clear();
    gendau_pid.clear();
    gendau_pt.clear();
    gendau_eta.clear();
    gendau_phi.clear();
    genpar_chg.clear();
    genpar_pid.clear();
    genpar_pt.clear();
    genpar_eta.clear();
    genpar_phi.clear();
  }

  trackTree->Write();
  f->Close();
  return 0;
}
