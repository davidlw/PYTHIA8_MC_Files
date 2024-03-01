void draw3()
{
  gStyle->SetOptStat(0);

  TFile* f = new TFile("pytree_mup_muic.root");
  TFile* f1 = new TFile("pytree_ep_eic_ycut001.root");
  TFile* f2 = new TFile("pytree_ep_lhec_ycut001.root");

  TH2D* hpetahadhist = (TH2D*)f->Get("petahadhist");
  TH2D* hpetahadhist1 = (TH2D*)f1->Get("petahadhist");
  TH2D* hpetahadhist2 = (TH2D*)f2->Get("petahadhist");
  
  TH1D* hetahadhist = (TH1D*)hpetahadhist->ProjectionX("etahadhist",-1,-1,"e");
  
  TCanvas* cc = new TCanvas("cc","cc",700,500);  
  hetahadhist->Draw();

  TCanvas* c = new TCanvas("c","c",700,500);
  c->SetLogy();
  c->SetLogz();
  hpetahadhist->SetAxisRange(0.5,200,"Y");
  hpetahadhist->GetXaxis()->CenterTitle();
  hpetahadhist->GetYaxis()->CenterTitle();
  hpetahadhist->Draw("colz");

  TLatex* latex = new TLatex();
  latex->SetNDC();
  latex->SetTextFont(42);
  latex->SetTextSize(0.045);
  latex->DrawLatex(0.1,0.93,"MuIC: #mu^{-} (960) + p (275), final-state hadrons from PYTHIA 8");

  TCanvas* c1 = new TCanvas("c1","c1",700,500);
  c1->SetLogy();
  c1->SetLogz();
  hpetahadhist1->SetAxisRange(0.5,200,"Y");
  hpetahadhist1->GetXaxis()->CenterTitle();
  hpetahadhist1->GetYaxis()->CenterTitle();
  hpetahadhist1->Draw("colz");

  TLatex* latex1 = new TLatex();
  latex1->SetNDC();
  latex1->SetTextFont(42);
  latex1->SetTextSize(0.045);
  latex1->DrawLatex(0.1,0.93,"EIC: #it{e}^{-} (18) + p (275), final-state hadrons from PYTHIA 8");

  TCanvas* c2 = new TCanvas("c2","c2",700,500);
  c2->SetLogy();
  c2->SetLogz();
  hpetahadhist2->SetAxisRange(0.5,200,"Y");
  hpetahadhist2->GetXaxis()->CenterTitle();
  hpetahadhist2->GetYaxis()->CenterTitle();
  hpetahadhist2->Draw("colz");

  TLatex* latex2 = new TLatex();
  latex2->SetNDC();
  latex2->SetTextFont(42);
  latex2->SetTextSize(0.045);
  latex2->DrawLatex(0.1,0.93,"LHeC: #it{e}^{-} (50) + p (7000), final-state hadrons from PYTHIA 8");

  c->Print("hadrons_muic.pdf");
  c->Print("hadrons_muic.png");

  c1->Print("hadrons_eic.pdf");
  c1->Print("hadrons_eic.png");

  c2->Print("hadrons_lhec.pdf");
  c2->Print("hadrons_lhec.png");
}
