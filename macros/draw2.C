void draw2()
{
  gStyle->SetOptStat(0);

  TFile* f = new TFile("pytree_mup_ycut001.root");
  TFile* f1 = new TFile("pytree_ep_eic_ycut001.root");
  TFile* f2 = new TFile("pytree_ep_lhec_ycut001.root");

  TH2D* h = (TH2D*)f->Get("petahadhist");
  TH2D* h1 = (TH2D*)f1->Get("petahadhist");
  TH2D* h2 = (TH2D*)f2->Get("petahadhist");

  TH2D* hQ2xhist = (TH2D*)f->Get("Q2xhist");
  TH2D* hQ2xhist1 = (TH2D*)f1->Get("Qxhist");
  TH2D* hQ2xhist2 = (TH2D*)f2->Get("Qxhist");
  
  TCanvas* c = new TCanvas("c","c",550,500);
  c->SetLogy();
  c->SetLogz();
  h->SetAxisRange(-8,8,"X");
  h->SetAxisRange(0.5,200,"Y");
  h->Draw("colz");

  TCanvas* c1 = new TCanvas("c1","c1",550,500);
  c1->SetLogy();
  c1->SetLogz();
  h1->SetAxisRange(-8,8,"X");
  h1->SetAxisRange(0.5,200,"Y");
  h1->Draw("colz");

  TCanvas* c2 = new TCanvas("c2","c2",550,500);
  c2->SetLogy();
  c2->SetLogz();
  h2->SetAxisRange(-8,8,"X");
  h2->SetAxisRange(0.5,200,"Y");
  h2->Draw("colz");

return;
  TCanvas* c3 = new TCanvas("c3","c3",550,500);
  c3->SetLogy();
  c3->SetLogz();
  c3->SetLogx();
  hQ2xhist->Draw("colz");

  TCanvas* c4 = new TCanvas("c4","c4",550,500);
  c4->SetLogy();
  c4->SetLogz();
  c4->SetLogx();
  hQ2xhist1->Draw("colz");

  TCanvas* c5 = new TCanvas("c5","c5",550,500);
  c5->SetLogy();
  c5->SetLogz();
  c5->SetLogx();
  hQ2xhist2->Draw("colz");
}
