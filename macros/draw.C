void draw()
{
  gStyle->SetOptStat(0);

//  TFile* f = new TFile("pytree_mup_1tev275gev.root");
  TFile* f = new TFile("pytree_mup_ycut01.root");
  TFile* f1 = new TFile("pytree_ep_eic.root");
  TFile* f2 = new TFile("pytree_ep_lhec.root");

  TTree* tr = (TTree*) f->Get("T");
  TTree* tr1 = (TTree*) f1->Get("T");
  TTree* tr2 = (TTree*) f2->Get("T");

  TH2D* h = new TH2D("h",";#eta;p (GeV)",100,-6,6,400,0.5,100);
  TH2D* h1 = new TH2D("h1",";#eta;p (GeV)",100,-6,6,400,0.5,100);
  TH2D* h2 = new TH2D("h2",";#eta;p (GeV)",100,-6,6,400,0.5,100);

  tr->Draw("sqrt(entry.pSave.xx*entry.pSave.xx+entry.pSave.yy*entry.pSave.yy+entry.pSave.zz*entry.pSave.zz):-log(tan(0.5*acos(entry.pSave.zz/sqrt(entry.pSave.zz*entry.pSave.zz+entry.pSave.xx*entry.pSave.xx+entry.pSave.yy*entry.pSave.yy))))>>h","entry.statusSave<=89 && entry.statusSave>=81 && sqrt(entry.pSave.xx*entry.pSave.xx+entry.pSave.yy*entry.pSave.yy+entry.pSave.zz*entry.pSave.zz)<100","colz");
  tr1->Draw("sqrt(entry.pSave.xx*entry.pSave.xx+entry.pSave.yy*entry.pSave.yy+entry.pSave.zz*entry.pSave.zz):-log(tan(0.5*acos(entry.pSave.zz/sqrt(entry.pSave.zz*entry.pSave.zz+entry.pSave.xx*entry.pSave.xx+entry.pSave.yy*entry.pSave.yy))))>>h1","entry.statusSave<=89 && entry.statusSave>=81 && sqrt(entry.pSave.xx*entry.pSave.xx+entry.pSave.yy*entry.pSave.yy+entry.pSave.zz*entry.pSave.zz)<100","colz");
  tr2->Draw("sqrt(entry.pSave.xx*entry.pSave.xx+entry.pSave.yy*entry.pSave.yy+entry.pSave.zz*entry.pSave.zz):-log(tan(0.5*acos(entry.pSave.zz/sqrt(entry.pSave.zz*entry.pSave.zz+entry.pSave.xx*entry.pSave.xx+entry.pSave.yy*entry.pSave.yy))))>>h2","entry.statusSave<=89 && entry.statusSave>=81 && sqrt(entry.pSave.xx*entry.pSave.xx+entry.pSave.yy*entry.pSave.yy+entry.pSave.zz*entry.pSave.zz)<100","colz");

  TCanvas* c = new TCanvas("c","c",550,500);
  c->SetLogy();
  c->SetLogz();
  h->Draw("colz");

  TCanvas* c1 = new TCanvas("c1","c1",550,500);
  c1->SetLogy();
  c1->SetLogz();
  h1->Draw("colz");

  TCanvas* c2 = new TCanvas("c2","c2",550,500);
  c2->SetLogy();
  c2->SetLogz();
  h2->Draw("colz");

  TH2D* Q2xhist = (TH2D*)f->Get("Q2xhist");
  
  TCanvas* c3 = new TCanvas("c3","c3",550,500);
  c3->SetLogy();
  c3->SetLogz();
  c3->SetLogx();

  Q2xhist->Draw("colz");
}
