void draw_resolution()
{
//  gStyle->SetPalette(kTemperatureMap);
  gStyle->SetPalette(1);
  gStyle->SetOptStat(0);

  TFile* f = new TFile("pytree_mup_muic_dp05_dang2_Q2all.root");
//  TFile* f = new TFile("pytree_mup_muic.root");

  TH3D* hQ2resVsQ2x = (TH3D*)f->Get("hQ2resVsQ2x");
  TH3D* hxresVsQ2x = (TH3D*)f->Get("hxresVsQ2x");
  TH3D* hyresVsQ2x = (TH3D*)f->Get("hyresVsQ2x");

  TH3D* hQ2resVsQ2xJB5 = (TH3D*)f->Get("hQ2resVsQ2xJB5");
  TH3D* hxresVsQ2xJB5 = (TH3D*)f->Get("hxresVsQ2xJB5");
  TH3D* hyresVsQ2xJB5 = (TH3D*)f->Get("hyresVsQ2xJB5");

  TH3D* hQ2resVsQ2xDA5 = (TH3D*)f->Get("hQ2resVsQ2xDA5");
  TH3D* hxresVsQ2xDA5 = (TH3D*)f->Get("hxresVsQ2xDA5");
  TH3D* hyresVsQ2xDA5 = (TH3D*)f->Get("hyresVsQ2xDA5");

  TProfile2D* hQ2resVsQ2xProjMean = (TProfile2D*)hQ2resVsQ2x->Project3DProfile("yx");
  TProfile2D* hxresVsQ2xProjMean = (TProfile2D*)hxresVsQ2x->Project3DProfile("yx");
  TProfile2D* hyresVsQ2xProjMean = (TProfile2D*)hyresVsQ2x->Project3DProfile("yx");

  TProfile2D* hQ2resVsQ2xJB5ProjMean = (TProfile2D*)hQ2resVsQ2xJB5->Project3DProfile("yx");
  TProfile2D* hxresVsQ2xJB5ProjMean = (TProfile2D*)hxresVsQ2xJB5->Project3DProfile("yx");
  TProfile2D* hyresVsQ2xJB5ProjMean = (TProfile2D*)hyresVsQ2xJB5->Project3DProfile("yx");

  TProfile2D* hQ2resVsQ2xDA5ProjMean = (TProfile2D*)hQ2resVsQ2xDA5->Project3DProfile("yx");
  TProfile2D* hxresVsQ2xDA5ProjMean = (TProfile2D*)hxresVsQ2xDA5->Project3DProfile("yx");
  TProfile2D* hyresVsQ2xDA5ProjMean = (TProfile2D*)hyresVsQ2xDA5->Project3DProfile("yx");

  hQ2resVsQ2xProjMean->SetAxisRange(-1,1,"Z");
  hxresVsQ2xProjMean->SetAxisRange(-1,1,"Z");
  hyresVsQ2xProjMean->SetAxisRange(-1,1,"Z");

  hQ2resVsQ2xJB5ProjMean->SetAxisRange(-1,1,"Z");
  hxresVsQ2xJB5ProjMean->SetAxisRange(-1,1,"Z");
  hyresVsQ2xJB5ProjMean->SetAxisRange(-1,1,"Z");

  hQ2resVsQ2xDA5ProjMean->SetAxisRange(-1,1,"Z");
  hxresVsQ2xDA5ProjMean->SetAxisRange(-1,1,"Z");
  hyresVsQ2xDA5ProjMean->SetAxisRange(-1,1,"Z");

  TH2D* hQ2resVsQ2xProj = (TH2D*)hQ2resVsQ2x->Project3D("yx");
  TH2D* hxresVsQ2xProj = (TH2D*)hxresVsQ2x->Project3D("yx");
  TH2D* hyresVsQ2xProj = (TH2D*)hyresVsQ2x->Project3D("yx");

  TH2D* hQ2resVsQ2xJB5Proj = (TH2D*)hQ2resVsQ2xJB5->Project3D("yx");
  TH2D* hxresVsQ2xJB5Proj = (TH2D*)hxresVsQ2xJB5->Project3D("yx");
  TH2D* hyresVsQ2xJB5Proj = (TH2D*)hyresVsQ2xJB5->Project3D("yx");

  TH2D* hQ2resVsQ2xDA5Proj = (TH2D*)hQ2resVsQ2xDA5->Project3D("yx");
  TH2D* hxresVsQ2xDA5Proj = (TH2D*)hxresVsQ2xDA5->Project3D("yx");
  TH2D* hyresVsQ2xDA5Proj = (TH2D*)hyresVsQ2xDA5->Project3D("yx");

  hQ2resVsQ2xProj->Reset();
  hxresVsQ2xProj->Reset();
  hyresVsQ2xProj->Reset();

  hQ2resVsQ2xJB5Proj->Reset();
  hxresVsQ2xJB5Proj->Reset();
  hyresVsQ2xJB5Proj->Reset();

  hQ2resVsQ2xDA5Proj->Reset();
  hxresVsQ2xDA5Proj->Reset();
  hyresVsQ2xDA5Proj->Reset();

  hQ2resVsQ2xProj->SetAxisRange(0.,1,"Z");
  hxresVsQ2xProj->SetAxisRange(0.,1,"Z");
  hyresVsQ2xProj->SetAxisRange(0.,1,"Z");
  
  hQ2resVsQ2xJB5Proj->SetAxisRange(0.,1,"Z");
  hxresVsQ2xJB5Proj->SetAxisRange(0.,1,"Z");
  hyresVsQ2xJB5Proj->SetAxisRange(0.,1,"Z");

  hQ2resVsQ2xDA5Proj->SetAxisRange(0.,1,"Z");
  hxresVsQ2xDA5Proj->SetAxisRange(0.,1,"Z");
  hyresVsQ2xDA5Proj->SetAxisRange(0.,1,"Z");

/*
  for(int i=1;i<=hQ2resVsQ2xProj->GetNbinsX();i++)
    for(int j=1;j<=hQ2resVsQ2xProj->GetNbinsY();j++)
    {
      hQ2resVsQ2xProj->SetBinContent(i,j,hQ2resVsQ2xProj->GetBinError(i,j));
      hxresVsQ2xProj->SetBinContent(i,j,hxresVsQ2xProj->GetBinError(i,j));
      hyresVsQ2xProj->SetBinContent(i,j,hyresVsQ2xProj->GetBinError(i,j));

      hQ2resVsQ2xJB5Proj->SetBinContent(i,j,hQ2resVsQ2xJB5Proj->GetBinError(i,j));
      hxresVsQ2xJB5Proj->SetBinContent(i,j,hxresVsQ2xJB5Proj->GetBinError(i,j));
      hyresVsQ2xJB5Proj->SetBinContent(i,j,hyresVsQ2xJB5Proj->GetBinError(i,j));

      hQ2resVsQ2xDA5Proj->SetBinContent(i,j,hQ2resVsQ2xDA5Proj->GetBinError(i,j));
      hxresVsQ2xDA5Proj->SetBinContent(i,j,hxresVsQ2xDA5Proj->GetBinError(i,j));
      hyresVsQ2xDA5Proj->SetBinContent(i,j,hyresVsQ2xDA5Proj->GetBinError(i,j));
    }
*/
  for(int i=1;i<=hQ2resVsQ2x->GetNbinsX();i++)
    for(int j=1;j<=hQ2resVsQ2x->GetNbinsY();j++)
    {
      TH1D* htmp1 = (TH1D*)hQ2resVsQ2x->ProjectionZ("hproj1",i,i,j,j,"e");
      hQ2resVsQ2xProj->SetBinContent(i,j,htmp1->GetRMS());

      TH1D* htmp2 = (TH1D*)hxresVsQ2x->ProjectionZ("hproj2",i,i,j,j,"e");
      hxresVsQ2xProj->SetBinContent(i,j,htmp2->GetRMS());

      TH1D* htmp3 = (TH1D*)hyresVsQ2x->ProjectionZ("hproj3",i,i,j,j,"e");
      hyresVsQ2xProj->SetBinContent(i,j,htmp3->GetRMS());

      TH1D* htmp4 = (TH1D*)hQ2resVsQ2xJB5->ProjectionZ("hproj4",i,i,j,j,"e");
      hQ2resVsQ2xJB5Proj->SetBinContent(i,j,htmp4->GetRMS());

      TH1D* htmp5 = (TH1D*)hxresVsQ2xJB5->ProjectionZ("hproj5",i,i,j,j,"e");
      hxresVsQ2xJB5Proj->SetBinContent(i,j,htmp5->GetRMS());

      TH1D* htmp6 = (TH1D*)hyresVsQ2xJB5->ProjectionZ("hproj6",i,i,j,j,"e");
      hyresVsQ2xJB5Proj->SetBinContent(i,j,htmp6->GetRMS());

      TH1D* htmp7 = (TH1D*)hQ2resVsQ2xDA5->ProjectionZ("hproj7",i,i,j,j,"e");
      hQ2resVsQ2xDA5Proj->SetBinContent(i,j,htmp7->GetRMS());

      TH1D* htmp8 = (TH1D*)hxresVsQ2xDA5->ProjectionZ("hproj8",i,i,j,j,"e");
      hxresVsQ2xDA5Proj->SetBinContent(i,j,htmp8->GetRMS());

      TH1D* htmp9 = (TH1D*)hyresVsQ2xDA5->ProjectionZ("hproj9",i,i,j,j,"e");
      hyresVsQ2xDA5Proj->SetBinContent(i,j,htmp9->GetRMS());
    }

  hQ2resVsQ2xProj->SetTitle(";x;Q^{2} [GeV^{2}]");
  hxresVsQ2xProj->SetTitle(";x;Q^{2} [GeV^{2}]");
  hyresVsQ2xProj->SetTitle(";x;Q^{2} [GeV^{2}]");
  hQ2resVsQ2xJB5Proj->SetTitle(";x;Q^{2} [GeV^{2}]");
  hxresVsQ2xJB5Proj->SetTitle(";x;Q^{2} [GeV^{2}]");
  hyresVsQ2xJB5Proj->SetTitle(";x;Q^{2} [GeV^{2}]");
  hQ2resVsQ2xDA5Proj->SetTitle(";x;Q^{2} [GeV^{2}]");
  hxresVsQ2xDA5Proj->SetTitle(";x;Q^{2} [GeV^{2}]");
  hyresVsQ2xDA5Proj->SetTitle(";x;Q^{2} [GeV^{2}]");

  hQ2resVsQ2xProj->GetXaxis()->CenterTitle();
  hxresVsQ2xProj->GetXaxis()->CenterTitle();
  hyresVsQ2xProj->GetXaxis()->CenterTitle();
  hQ2resVsQ2xJB5Proj->GetXaxis()->CenterTitle();
  hxresVsQ2xJB5Proj->GetXaxis()->CenterTitle();
  hyresVsQ2xJB5Proj->GetXaxis()->CenterTitle();
  hQ2resVsQ2xDA5Proj->GetXaxis()->CenterTitle();
  hxresVsQ2xDA5Proj->GetXaxis()->CenterTitle();
  hyresVsQ2xDA5Proj->GetXaxis()->CenterTitle();
  hQ2resVsQ2xProj->GetYaxis()->CenterTitle();
  hxresVsQ2xProj->GetYaxis()->CenterTitle();
  hyresVsQ2xProj->GetYaxis()->CenterTitle();
  hQ2resVsQ2xJB5Proj->GetYaxis()->CenterTitle();
  hxresVsQ2xJB5Proj->GetYaxis()->CenterTitle();
  hyresVsQ2xJB5Proj->GetYaxis()->CenterTitle();
  hQ2resVsQ2xDA5Proj->GetYaxis()->CenterTitle();
  hxresVsQ2xDA5Proj->GetYaxis()->CenterTitle();
  hyresVsQ2xDA5Proj->GetYaxis()->CenterTitle();

  hQ2resVsQ2xProj->GetXaxis()->SetTitleSize(1.8*hQ2resVsQ2xProj->GetXaxis()->GetTitleSize());
  hxresVsQ2xProj->GetXaxis()->SetTitleSize(2.*hxresVsQ2xProj->GetXaxis()->GetTitleSize());
  hyresVsQ2xProj->GetXaxis()->SetTitleSize(2.*hyresVsQ2xProj->GetXaxis()->GetTitleSize());
  hQ2resVsQ2xJB5Proj->GetXaxis()->SetTitleSize(1.8*hQ2resVsQ2xJB5Proj->GetXaxis()->GetTitleSize());
  hxresVsQ2xJB5Proj->GetXaxis()->SetTitleSize(2.*hxresVsQ2xJB5Proj->GetXaxis()->GetTitleSize());
  hyresVsQ2xJB5Proj->GetXaxis()->SetTitleSize(2.*hyresVsQ2xJB5Proj->GetXaxis()->GetTitleSize());
  hQ2resVsQ2xDA5Proj->GetXaxis()->SetTitleSize(1.8*hQ2resVsQ2xDA5Proj->GetXaxis()->GetTitleSize());
  hxresVsQ2xDA5Proj->GetXaxis()->SetTitleSize(2.*hxresVsQ2xDA5Proj->GetXaxis()->GetTitleSize());
  hyresVsQ2xDA5Proj->GetXaxis()->SetTitleSize(2.*hyresVsQ2xDA5Proj->GetXaxis()->GetTitleSize());

  hQ2resVsQ2xProj->GetYaxis()->SetTitleSize(1.8*hQ2resVsQ2xProj->GetYaxis()->GetTitleSize());
  hxresVsQ2xProj->GetYaxis()->SetTitleSize(2.*hxresVsQ2xProj->GetYaxis()->GetTitleSize());
  hyresVsQ2xProj->GetYaxis()->SetTitleSize(2.*hyresVsQ2xProj->GetYaxis()->GetTitleSize());
  hQ2resVsQ2xJB5Proj->GetYaxis()->SetTitleSize(1.8*hQ2resVsQ2xJB5Proj->GetYaxis()->GetTitleSize());
  hxresVsQ2xJB5Proj->GetYaxis()->SetTitleSize(2.*hxresVsQ2xJB5Proj->GetYaxis()->GetTitleSize());
  hyresVsQ2xJB5Proj->GetYaxis()->SetTitleSize(2.*hyresVsQ2xJB5Proj->GetYaxis()->GetTitleSize());
  hQ2resVsQ2xDA5Proj->GetYaxis()->SetTitleSize(1.8*hQ2resVsQ2xDA5Proj->GetYaxis()->GetTitleSize());
  hxresVsQ2xDA5Proj->GetYaxis()->SetTitleSize(2.*hxresVsQ2xDA5Proj->GetYaxis()->GetTitleSize());
  hyresVsQ2xDA5Proj->GetYaxis()->SetTitleSize(2.*hyresVsQ2xDA5Proj->GetYaxis()->GetTitleSize());

  hQ2resVsQ2xProj->GetXaxis()->SetTitleOffset(0.7*hQ2resVsQ2xProj->GetXaxis()->GetTitleOffset());
  hxresVsQ2xProj->GetXaxis()->SetTitleOffset(0.7*hxresVsQ2xProj->GetXaxis()->GetTitleOffset());
  hyresVsQ2xProj->GetXaxis()->SetTitleOffset(0.7*hyresVsQ2xProj->GetXaxis()->GetTitleOffset());
  hQ2resVsQ2xJB5Proj->GetXaxis()->SetTitleOffset(0.7*hQ2resVsQ2xJB5Proj->GetXaxis()->GetTitleOffset());
  hxresVsQ2xJB5Proj->GetXaxis()->SetTitleOffset(0.7*hxresVsQ2xJB5Proj->GetXaxis()->GetTitleOffset());
  hyresVsQ2xJB5Proj->GetXaxis()->SetTitleOffset(0.7*hyresVsQ2xJB5Proj->GetXaxis()->GetTitleOffset());
  hQ2resVsQ2xDA5Proj->GetXaxis()->SetTitleOffset(0.7*hQ2resVsQ2xDA5Proj->GetXaxis()->GetTitleOffset());
  hxresVsQ2xDA5Proj->GetXaxis()->SetTitleOffset(0.7*hxresVsQ2xDA5Proj->GetXaxis()->GetTitleOffset());
  hyresVsQ2xDA5Proj->GetXaxis()->SetTitleOffset(0.7*hyresVsQ2xDA5Proj->GetXaxis()->GetTitleOffset());

  hQ2resVsQ2xProj->GetYaxis()->SetTitleOffset(0.75);
  hxresVsQ2xProj->GetYaxis()->SetTitleOffset(0.65);
  hyresVsQ2xProj->GetYaxis()->SetTitleOffset(0.65);
  hQ2resVsQ2xJB5Proj->GetYaxis()->SetTitleOffset(0.75);
  hxresVsQ2xJB5Proj->GetYaxis()->SetTitleOffset(0.65);
  hyresVsQ2xJB5Proj->GetYaxis()->SetTitleOffset(0.65);
  hQ2resVsQ2xDA5Proj->GetYaxis()->SetTitleOffset(0.75);
  hxresVsQ2xDA5Proj->GetYaxis()->SetTitleOffset(0.65);
  hyresVsQ2xDA5Proj->GetYaxis()->SetTitleOffset(0.65);

  TH2D* hQ2resVsQ2 = (TH2D*)f->Get("hQ2resVsQ2");
  TH2D* hQ2resVsx = (TH2D*)f->Get("hQ2resVsx"); 
  TH2D* hQ2resVsy = (TH2D*)f->Get("hQ2resVsy"); 
  TH2D* hxresVsQ2 = (TH2D*)f->Get("hxresVsQ2");
  TH2D* hxresVsx = (TH2D*)f->Get("hxresVsx"); 
  TH2D* hxresVsy = (TH2D*)f->Get("hxresVsy"); 
  TH2D* hyresVsQ2 = (TH2D*)f->Get("hyresVsQ2"); 
  TH2D* hyresVsx = (TH2D*)f->Get("hyresVsx"); 
  TH2D* hyresVsy = (TH2D*)f->Get("hyresVsy"); 

  TH2D* hQ2resVsQ2JB = (TH2D*)f->Get("hQ2resVsQ2JB");
  TH2D* hQ2resVsxJB = (TH2D*)f->Get("hQ2resVsxJB");
  TH2D* hQ2resVsyJB = (TH2D*)f->Get("hQ2resVsyJB");
  TH2D* hxresVsQ2JB = (TH2D*)f->Get("hxresVsQ2JB");
  TH2D* hxresVsxJB = (TH2D*)f->Get("hxresVsxJB");
  TH2D* hxresVsyJB = (TH2D*)f->Get("hxresVsyJB");
  TH2D* hyresVsQ2JB = (TH2D*)f->Get("hyresVsQ2JB");
  TH2D* hyresVsxJB = (TH2D*)f->Get("hyresVsxJB");
  TH2D* hyresVsyJB = (TH2D*)f->Get("hyresVsyJB");

  TH2D* hQ2resVsQ2JB4 = (TH2D*)f->Get("hQ2resVsQ2JB4");
  TH2D* hQ2resVsxJB4 = (TH2D*)f->Get("hQ2resVsxJB4");
  TH2D* hQ2resVsyJB4 = (TH2D*)f->Get("hQ2resVsyJB4");
  TH2D* hxresVsQ2JB4 = (TH2D*)f->Get("hxresVsQ2JB4");
  TH2D* hxresVsxJB4 = (TH2D*)f->Get("hxresVsxJB4");
  TH2D* hxresVsyJB4 = (TH2D*)f->Get("hxresVsyJB4");
  TH2D* hyresVsQ2JB4 = (TH2D*)f->Get("hyresVsQ2JB4");
  TH2D* hyresVsxJB4 = (TH2D*)f->Get("hyresVsxJB4");
  TH2D* hyresVsyJB4 = (TH2D*)f->Get("hyresVsyJB4");

  TH2D* hQ2resVsQ2JB5 = (TH2D*)f->Get("hQ2resVsQ2JB5");
  TH2D* hQ2resVsxJB5 = (TH2D*)f->Get("hQ2resVsxJB5");
  TH2D* hQ2resVsyJB5 = (TH2D*)f->Get("hQ2resVsyJB5");
  TH2D* hxresVsQ2JB5 = (TH2D*)f->Get("hxresVsQ2JB5");
  TH2D* hxresVsxJB5 = (TH2D*)f->Get("hxresVsxJB5");
  TH2D* hxresVsyJB5 = (TH2D*)f->Get("hxresVsyJB5");
  TH2D* hyresVsQ2JB5 = (TH2D*)f->Get("hyresVsQ2JB5");
  TH2D* hyresVsxJB5 = (TH2D*)f->Get("hyresVsxJB5");
  TH2D* hyresVsyJB5 = (TH2D*)f->Get("hyresVsyJB5");

  TH2D* hQ2resVsQ2DA = (TH2D*)f->Get("hQ2resVsQ2DA");
  TH2D* hQ2resVsxDA = (TH2D*)f->Get("hQ2resVsxDA");
  TH2D* hQ2resVsyDA = (TH2D*)f->Get("hQ2resVsyDA");
  TH2D* hxresVsQ2DA = (TH2D*)f->Get("hxresVsQ2DA");
  TH2D* hxresVsxDA = (TH2D*)f->Get("hxresVsxDA");
  TH2D* hxresVsyDA = (TH2D*)f->Get("hxresVsyDA");
  TH2D* hyresVsQ2DA = (TH2D*)f->Get("hyresVsQ2DA");
  TH2D* hyresVsxDA = (TH2D*)f->Get("hyresVsxDA");
  TH2D* hyresVsyDA = (TH2D*)f->Get("hyresVsyDA");

  TH2D* hQ2resVsQ2DA4 = (TH2D*)f->Get("hQ2resVsQ2DA4");
  TH2D* hQ2resVsxDA4 = (TH2D*)f->Get("hQ2resVsxDA4");
  TH2D* hQ2resVsyDA4 = (TH2D*)f->Get("hQ2resVsyDA4");
  TH2D* hxresVsQ2DA4 = (TH2D*)f->Get("hxresVsQ2DA4");
  TH2D* hxresVsxDA4 = (TH2D*)f->Get("hxresVsxDA4");
  TH2D* hxresVsyDA4 = (TH2D*)f->Get("hxresVsyDA4");
  TH2D* hyresVsQ2DA4 = (TH2D*)f->Get("hyresVsQ2DA4");
  TH2D* hyresVsxDA4 = (TH2D*)f->Get("hyresVsxDA4");
  TH2D* hyresVsyDA4 = (TH2D*)f->Get("hyresVsyDA4");

  TH2D* hQ2resVsQ2DA5 = (TH2D*)f->Get("hQ2resVsQ2DA5");
  TH2D* hQ2resVsxDA5 = (TH2D*)f->Get("hQ2resVsxDA5");
  TH2D* hQ2resVsyDA5 = (TH2D*)f->Get("hQ2resVsyDA5");
  TH2D* hxresVsQ2DA5 = (TH2D*)f->Get("hxresVsQ2DA5");
  TH2D* hxresVsxDA5 = (TH2D*)f->Get("hxresVsxDA5");
  TH2D* hxresVsyDA5 = (TH2D*)f->Get("hxresVsyDA5");
  TH2D* hyresVsQ2DA5 = (TH2D*)f->Get("hyresVsQ2DA5");
  TH2D* hyresVsxDA5 = (TH2D*)f->Get("hyresVsxDA5");
  TH2D* hyresVsyDA5 = (TH2D*)f->Get("hyresVsyDA5");


  TH2D* hQ2resVsQ2A4 = (TH2D*)f->Get("hQ2resVsQ2A4");
  TH2D* hQ2resVsxA4 = (TH2D*)f->Get("hQ2resVsxA4");
  TH2D* hQ2resVsyA4 = (TH2D*)f->Get("hQ2resVsyA4");
  TH2D* hxresVsQ2A4 = (TH2D*)f->Get("hxresVsQ2A4");
  TH2D* hxresVsxA4 = (TH2D*)f->Get("hxresVsxA4");
  TH2D* hxresVsyA4 = (TH2D*)f->Get("hxresVsyA4");
  TH2D* hyresVsQ2A4 = (TH2D*)f->Get("hyresVsQ2A4");
  TH2D* hyresVsxA4 = (TH2D*)f->Get("hyresVsxA4");
  TH2D* hyresVsyA4 = (TH2D*)f->Get("hyresVsyA4");

  TH2D* hQ2resVsQ2A4Eta4 = (TH2D*)f->Get("hQ2resVsQ2A4Eta4");
  TH2D* hQ2resVsxA4Eta4 = (TH2D*)f->Get("hQ2resVsxA4Eta4");
  TH2D* hQ2resVsyA4Eta4 = (TH2D*)f->Get("hQ2resVsyA4Eta4");
  TH2D* hxresVsQ2A4Eta4 = (TH2D*)f->Get("hxresVsQ2A4Eta4");
  TH2D* hxresVsxA4Eta4 = (TH2D*)f->Get("hxresVsxA4Eta4");
  TH2D* hxresVsyA4Eta4 = (TH2D*)f->Get("hxresVsyA4Eta4");
  TH2D* hyresVsQ2A4Eta4 = (TH2D*)f->Get("hyresVsQ2A4Eta4");
  TH2D* hyresVsxA4Eta4 = (TH2D*)f->Get("hyresVsxA4Eta4");
  TH2D* hyresVsyA4Eta4 = (TH2D*)f->Get("hyresVsyA4Eta4");

  TH2D* hQ2resVsQ2A4Eta5 = (TH2D*)f->Get("hQ2resVsQ2A4Eta5");
  TH2D* hQ2resVsxA4Eta5 = (TH2D*)f->Get("hQ2resVsxA4Eta5");
  TH2D* hQ2resVsyA4Eta5 = (TH2D*)f->Get("hQ2resVsyA4Eta5");
  TH2D* hxresVsQ2A4Eta5 = (TH2D*)f->Get("hxresVsQ2A4Eta5");
  TH2D* hxresVsxA4Eta5 = (TH2D*)f->Get("hxresVsxA4Eta5");
  TH2D* hxresVsyA4Eta5 = (TH2D*)f->Get("hxresVsyA4Eta5");
  TH2D* hyresVsQ2A4Eta5 = (TH2D*)f->Get("hyresVsQ2A4Eta5");
  TH2D* hyresVsxA4Eta5 = (TH2D*)f->Get("hyresVsxA4Eta5");
  TH2D* hyresVsyA4Eta5 = (TH2D*)f->Get("hyresVsyA4Eta5");

  TProfile* hQ2resVsQ2_prof = (TProfile*)hQ2resVsQ2->ProfileX("hQ2resVsQ2_prof",1,-1,"s");
  TProfile* hQ2resVsx_prof = (TProfile*)hQ2resVsx->ProfileX("hQ2resVsx_prof",1,-1,"s");
  TProfile* hQ2resVsy_prof = (TProfile*)hQ2resVsy->ProfileX("hQ2resVsy_prof",1,-1,"s");
  TProfile* hxresVsQ2_prof = (TProfile*)hxresVsQ2->ProfileX("hxresVsQ2_prof",1,-1,"s");
  TProfile* hxresVsx_prof = (TProfile*)hxresVsx->ProfileX("hxresVsx_prof",1,-1,"s");
  TProfile* hxresVsy_prof = (TProfile*)hxresVsy->ProfileX("hxresVsy_prof",1,-1,"s");
  TProfile* hyresVsQ2_prof = (TProfile*)hyresVsQ2->ProfileX("hyresVsQ2_prof",1,-1,"s");
  TProfile* hyresVsx_prof = (TProfile*)hyresVsx->ProfileX("hyresVsx_prof",1,-1,"s");
  TProfile* hyresVsy_prof = (TProfile*)hyresVsy->ProfileX("hyresVsy_prof",1,-1,"s");

  TProfile* hQ2resVsQ2JB5_prof = (TProfile*)hQ2resVsQ2JB5->ProfileX("hQ2resVsQ2JB5_prof",1,-1,"s");
  TProfile* hQ2resVsxJB5_prof = (TProfile*)hQ2resVsxJB5->ProfileX("hQ2resVsxJB5_prof",1,-1,"s");
  TProfile* hQ2resVsyJB5_prof = (TProfile*)hQ2resVsyJB5->ProfileX("hQ2resVsyJB5_prof",1,-1,"s");
  TProfile* hxresVsQ2JB5_prof = (TProfile*)hxresVsQ2JB5->ProfileX("hxresVsQ2JB5_prof",1,-1,"s");
  TProfile* hxresVsxJB5_prof = (TProfile*)hxresVsxJB5->ProfileX("hxresVsxJB5_prof",1,-1,"s");
  TProfile* hxresVsyJB5_prof = (TProfile*)hxresVsyJB5->ProfileX("hxresVsyJB5_prof",1,-1,"s");
  TProfile* hyresVsQ2JB5_prof = (TProfile*)hyresVsQ2JB5->ProfileX("hyresVsQ2JB5_prof",1,-1,"s");
  TProfile* hyresVsxJB5_prof = (TProfile*)hyresVsxJB5->ProfileX("hyresVsxJB5_prof",1,-1,"s");
  TProfile* hyresVsyJB5_prof = (TProfile*)hyresVsyJB5->ProfileX("hyresVsyJB5_prof",1,-1,"s");

  TProfile* hQ2resVsQ2DA5_prof = (TProfile*)hQ2resVsQ2DA5->ProfileX("hQ2resVsQ2DA5_prof",1,-1,"s");
  TProfile* hQ2resVsxDA5_prof = (TProfile*)hQ2resVsxDA5->ProfileX("hQ2resVsxDA5_prof",1,-1,"s");
  TProfile* hQ2resVsyDA5_prof = (TProfile*)hQ2resVsyDA5->ProfileX("hQ2resVsyDA5_prof",1,-1,"s");
  TProfile* hxresVsQ2DA5_prof = (TProfile*)hxresVsQ2DA5->ProfileX("hxresVsQ2DA5_prof",1,-1,"s");
  TProfile* hxresVsxDA5_prof = (TProfile*)hxresVsxDA5->ProfileX("hxresVsxDA5_prof",1,-1,"s");
  TProfile* hxresVsyDA5_prof = (TProfile*)hxresVsyDA5->ProfileX("hxresVsyDA5_prof",1,-1,"s");
  TProfile* hyresVsQ2DA5_prof = (TProfile*)hyresVsQ2DA5->ProfileX("hyresVsQ2DA5_prof",1,-1,"s");
  TProfile* hyresVsxDA5_prof = (TProfile*)hyresVsxDA5->ProfileX("hyresVsxDA5_prof",1,-1,"s");
  TProfile* hyresVsyDA5_prof = (TProfile*)hyresVsyDA5->ProfileX("hyresVsyDA5_prof",1,-1,"s");

  TProfile* hQ2resVsQ2A4Eta5_prof = (TProfile*)hQ2resVsQ2A4Eta5->ProfileX("hQ2resVsQ2A4Eta5_prof",1,-1,"s");
  TProfile* hQ2resVsxA4Eta5_prof = (TProfile*)hQ2resVsxA4Eta5->ProfileX("hQ2resVsxA4Eta5_prof",1,-1,"s");
  TProfile* hQ2resVsyA4Eta5_prof = (TProfile*)hQ2resVsyA4Eta5->ProfileX("hQ2resVsyA4Eta5_prof",1,-1,"s");
  TProfile* hxresVsQ2A4Eta5_prof = (TProfile*)hxresVsQ2A4Eta5->ProfileX("hxresVsQ2A4Eta5_prof",1,-1,"s");
  TProfile* hxresVsxA4Eta5_prof = (TProfile*)hxresVsxA4Eta5->ProfileX("hxresVsxA4Eta5_prof",1,-1,"s");
  TProfile* hxresVsyA4Eta5_prof = (TProfile*)hxresVsyA4Eta5->ProfileX("hxresVsyA4Eta5_prof",1,-1,"s");
  TProfile* hyresVsQ2A4Eta5_prof = (TProfile*)hyresVsQ2A4Eta5->ProfileX("hyresVsQ2A4Eta5_prof",1,-1,"s");
  TProfile* hyresVsxA4Eta5_prof = (TProfile*)hyresVsxA4Eta5->ProfileX("hyresVsxA4Eta5_prof",1,-1,"s");
  TProfile* hyresVsyA4Eta5_prof = (TProfile*)hyresVsyA4Eta5->ProfileX("hyresVsyA4Eta5_prof",1,-1,"s");

  hQ2resVsQ2->SetAxisRange(3,200,"X");
  hxresVsQ2->SetAxisRange(3,200,"X");
  hyresVsQ2->SetAxisRange(3,200,"X");
  hQ2resVsQ2JB5->SetAxisRange(3,200,"X");
  hxresVsQ2JB5->SetAxisRange(3,200,"X");
  hyresVsQ2JB5->SetAxisRange(3,200,"X");
  hQ2resVsQ2DA5->SetAxisRange(3,200,"X");
  hxresVsQ2DA5->SetAxisRange(3,200,"X");
  hyresVsQ2DA5->SetAxisRange(3,200,"X");
  hQ2resVsQ2A4Eta5->SetAxisRange(3,200,"X");
  hxresVsQ2A4Eta5->SetAxisRange(3,200,"X");
  hyresVsQ2A4Eta5->SetAxisRange(3,200,"X");

  hQ2resVsx->SetAxisRange(0,0.001,"X");
  hxresVsx->SetAxisRange(0,0.001,"X");
  hyresVsx->SetAxisRange(0,0.001,"X");
  hQ2resVsxJB5->SetAxisRange(0,0.001,"X");
  hxresVsxJB5->SetAxisRange(0,0.001,"X");
  hyresVsxJB5->SetAxisRange(0,0.001,"X");
  hQ2resVsxDA5->SetAxisRange(0,0.001,"X");
  hxresVsxDA5->SetAxisRange(0,0.001,"X");
  hyresVsxDA5->SetAxisRange(0,0.001,"X");
  hQ2resVsxA4Eta5->SetAxisRange(0,0.001,"X");
  hxresVsxA4Eta5->SetAxisRange(0,0.001,"X");
  hyresVsxA4Eta5->SetAxisRange(0,0.001,"X");

  hQ2resVsy->GetXaxis()->CenterTitle();
  hxresVsy->GetXaxis()->CenterTitle();
  hyresVsy->GetXaxis()->CenterTitle();
  hQ2resVsyJB5->GetXaxis()->CenterTitle();
  hxresVsyJB5->GetXaxis()->CenterTitle();
  hyresVsyJB5->GetXaxis()->CenterTitle();
  hQ2resVsyDA5->GetXaxis()->CenterTitle();
  hxresVsyDA5->GetXaxis()->CenterTitle();
  hyresVsyDA5->GetXaxis()->CenterTitle();

  hQ2resVsy->GetYaxis()->CenterTitle();
  hxresVsy->GetYaxis()->CenterTitle();
  hyresVsy->GetYaxis()->CenterTitle();
  hQ2resVsyJB5->GetYaxis()->CenterTitle();
  hxresVsyJB5->GetYaxis()->CenterTitle();
  hyresVsyJB5->GetYaxis()->CenterTitle();
  hQ2resVsyDA5->GetYaxis()->CenterTitle();
  hxresVsyDA5->GetYaxis()->CenterTitle();
  hyresVsyDA5->GetYaxis()->CenterTitle();

  hQ2resVsy->GetXaxis()->SetTitleSize(1.8*hQ2resVsy->GetXaxis()->GetTitleSize());
  hxresVsy->GetXaxis()->SetTitleSize(2.*hxresVsy->GetXaxis()->GetTitleSize());
  hyresVsy->GetXaxis()->SetTitleSize(2.*hyresVsy->GetXaxis()->GetTitleSize());
  hQ2resVsyJB5->GetXaxis()->SetTitleSize(1.8*hQ2resVsyJB5->GetXaxis()->GetTitleSize());
  hxresVsyJB5->GetXaxis()->SetTitleSize(2.*hxresVsyJB5->GetXaxis()->GetTitleSize());
  hyresVsyJB5->GetXaxis()->SetTitleSize(2.*hyresVsyJB5->GetXaxis()->GetTitleSize());
  hQ2resVsyDA5->GetXaxis()->SetTitleSize(1.8*hQ2resVsyDA5->GetXaxis()->GetTitleSize());
  hxresVsyDA5->GetXaxis()->SetTitleSize(2.*hxresVsyDA5->GetXaxis()->GetTitleSize());
  hyresVsyDA5->GetXaxis()->SetTitleSize(2.*hyresVsyDA5->GetXaxis()->GetTitleSize());

  hQ2resVsy->GetYaxis()->SetTitleSize(1.8*hQ2resVsy->GetYaxis()->GetTitleSize());
  hxresVsy->GetYaxis()->SetTitleSize(2.*hxresVsy->GetYaxis()->GetTitleSize());
  hyresVsy->GetYaxis()->SetTitleSize(2.*hyresVsy->GetYaxis()->GetTitleSize());
  hQ2resVsyJB5->GetYaxis()->SetTitleSize(1.8*hQ2resVsyJB5->GetYaxis()->GetTitleSize());
  hxresVsyJB5->GetYaxis()->SetTitleSize(2.*hxresVsyJB5->GetYaxis()->GetTitleSize());
  hyresVsyJB5->GetYaxis()->SetTitleSize(2.*hyresVsyJB5->GetYaxis()->GetTitleSize());
  hQ2resVsyDA5->GetYaxis()->SetTitleSize(1.8*hQ2resVsyDA5->GetYaxis()->GetTitleSize());
  hxresVsyDA5->GetYaxis()->SetTitleSize(2.*hxresVsyDA5->GetYaxis()->GetTitleSize());
  hyresVsyDA5->GetYaxis()->SetTitleSize(2.*hyresVsyDA5->GetYaxis()->GetTitleSize());

  hQ2resVsy->GetXaxis()->SetTitleOffset(0.7*hQ2resVsy->GetXaxis()->GetTitleOffset());
  hxresVsy->GetXaxis()->SetTitleOffset(0.7*hxresVsy->GetXaxis()->GetTitleOffset());
  hyresVsy->GetXaxis()->SetTitleOffset(0.7*hyresVsy->GetXaxis()->GetTitleOffset());
  hQ2resVsyJB5->GetXaxis()->SetTitleOffset(0.7*hQ2resVsyJB5->GetXaxis()->GetTitleOffset());
  hxresVsyJB5->GetXaxis()->SetTitleOffset(0.7*hxresVsyJB5->GetXaxis()->GetTitleOffset());
  hyresVsyJB5->GetXaxis()->SetTitleOffset(0.7*hyresVsyJB5->GetXaxis()->GetTitleOffset());
  hQ2resVsyDA5->GetXaxis()->SetTitleOffset(0.7*hQ2resVsyDA5->GetXaxis()->GetTitleOffset());
  hxresVsyDA5->GetXaxis()->SetTitleOffset(0.7*hxresVsyDA5->GetXaxis()->GetTitleOffset());
  hyresVsyDA5->GetXaxis()->SetTitleOffset(0.7*hyresVsyDA5->GetXaxis()->GetTitleOffset());

  hQ2resVsy->GetYaxis()->SetTitleOffset(0.8);
  hxresVsy->GetYaxis()->SetTitleOffset(0.7);
  hyresVsy->GetYaxis()->SetTitleOffset(0.7);
  hQ2resVsyJB5->GetYaxis()->SetTitleOffset(0.8);
  hxresVsyJB5->GetYaxis()->SetTitleOffset(0.7);
  hyresVsyJB5->GetYaxis()->SetTitleOffset(0.7);
  hQ2resVsyDA5->GetYaxis()->SetTitleOffset(0.8);
  hxresVsyDA5->GetYaxis()->SetTitleOffset(0.7);
  hyresVsyDA5->GetYaxis()->SetTitleOffset(0.7);

  TF1* Q2_y01 = new TF1("Q2_y01","x*(pow([0]+[1],2)-pow([0]-[1],2))*[2]",0.0000001,1);
  TF1* Q2_y001 = new TF1("Q2_y001","x*(pow([0]+[1],2)-pow([0]-[1],2))*[2]",0.0000001,1);
  TF1* Q2_y95 = new TF1("Q2_y95","x*(pow([0]+[1],2)-pow([0]-[1],2))*[2]",0.0000001,1);

  Q2_y01->SetParameters(960,275,0.01);
  Q2_y95->SetParameters(960,275,0.95);
  Q2_y001->SetParameters(960,275,0.001);
  Q2_y01->SetLineColor(1);
  Q2_y95->SetLineColor(1);
  Q2_y001->SetLineColor(1);

  TCanvas* aaa = new TCanvas("aaa","aaa",1200,870);
  aaa->Divide(3,3);
  aaa->cd(1);
//  aaa->GetPad(1)->SetRightMargin(0.0);
  aaa->GetPad(1)->SetLogx();
  aaa->GetPad(1)->SetLogy();
  hQ2resVsQ2xProj->Draw("colz");
  Q2_y01->Draw("Lsame");
  Q2_y001->Draw("Lsame");
  Q2_y95->Draw("Lsame");

  TLatex* latex = new TLatex();
  latex->SetNDC();
  latex->SetTextSize(0.075);
  latex->DrawLatex(0.1,0.94,"MuIC: #mu^{-} (960) + p (275)");
  latex->DrawLatex(0.15,0.78,"#DeltaQ^{2}/Q^{2}");

  latex->SetTextAngle(32);
  latex->SetTextSize(0.055);
  latex->DrawLatex(0.51,0.61,"y=0.95");
  latex->DrawLatex(0.6,0.42,"y=0.01");
  latex->DrawLatex(0.65,0.32,"y=0.001");
  latex->SetTextAngle(0);
  latex->SetTextSize(0.075);

  aaa->cd(2);
//  aaa->GetPad(2)->SetRightMargin(0.0);
  aaa->GetPad(2)->SetLogx();
  aaa->GetPad(2)->SetLogy();
  hxresVsQ2xProj->Draw("colz");
  Q2_y01->Draw("Lsame");
  Q2_y001->Draw("Lsame");
  Q2_y95->Draw("Lsame");

  latex->DrawLatex(0.4,0.94,"Lepton-only");
  latex->DrawLatex(0.15,0.78,"#Deltax/x");

  aaa->cd(3);
//  aaa->GetPad(3)->SetRightMargin(0.0);
  aaa->GetPad(3)->SetLogx();
  aaa->GetPad(3)->SetLogy();
  hyresVsQ2xProj->Draw("colz");
  Q2_y01->Draw("Lsame");
  Q2_y001->Draw("Lsame");
  Q2_y95->Draw("Lsame");

  latex->DrawLatex(0.15,0.78,"#Deltay/y");

  aaa->cd(4);
//  aaa->GetPad(4)->SetRightMargin(0.0);
  aaa->GetPad(4)->SetLogx();
  aaa->GetPad(4)->SetLogy();
  hQ2resVsQ2xJB5Proj->Draw("colz");
  Q2_y01->Draw("Lsame");
  Q2_y001->Draw("Lsame");
  Q2_y95->Draw("Lsame");

  latex->DrawLatex(0.15,0.78,"#DeltaQ^{2}/Q^{2}");

  aaa->cd(5);
//  aaa->GetPad(5)->SetRightMargin(0.0);
  aaa->GetPad(5)->SetLogx();
  aaa->GetPad(5)->SetLogy();
  hxresVsQ2xJB5Proj->Draw("colz");
  Q2_y01->Draw("Lsame");
  Q2_y001->Draw("Lsame");
  Q2_y95->Draw("Lsame");

  latex->DrawLatex(0.2,0.94,"Jacquet-Blondel (|#eta_{h}| < 5)");
  latex->DrawLatex(0.15,0.78,"#Deltax/x");

  aaa->cd(6);
//  aaa->GetPad(6)->SetRightMargin(0.0);
  aaa->GetPad(6)->SetLogx();
  aaa->GetPad(6)->SetLogy();
  hyresVsQ2xJB5Proj->Draw("colz");
  Q2_y01->Draw("Lsame");
  Q2_y001->Draw("Lsame");
  Q2_y95->Draw("Lsame");

  latex->DrawLatex(0.15,0.78,"#Deltay/y");

  aaa->cd(7);
//  aaa->GetPad(7)->SetRightMargin(0.0);
  aaa->GetPad(7)->SetLogx();
  aaa->GetPad(7)->SetLogy();
  hQ2resVsQ2xDA5Proj->Draw("colz");
  Q2_y01->Draw("Lsame");
  Q2_y001->Draw("Lsame");
  Q2_y95->Draw("Lsame");

  latex->DrawLatex(0.15,0.78,"#DeltaQ^{2}/Q^{2}");

  aaa->cd(8);
//  aaa->GetPad(8)->SetRightMargin(0.0);
  aaa->GetPad(8)->SetLogx();
  aaa->GetPad(8)->SetLogy();
  hxresVsQ2xDA5Proj->Draw("colz");
  Q2_y01->Draw("Lsame");
  Q2_y001->Draw("Lsame");
  Q2_y95->Draw("Lsame");

  latex->DrawLatex(0.3,0.94,"Double Angle (|#eta_{h}| < 5)");
  latex->DrawLatex(0.15,0.78,"#Deltax/x");

  aaa->cd(9);
//  aaa->GetPad(9)->SetRightMargin(0.0);
  aaa->GetPad(9)->SetLogx();
  aaa->GetPad(9)->SetLogy();
  hyresVsQ2xDA5Proj->Draw("colz");
  Q2_y01->Draw("Lsame");
  Q2_y001->Draw("Lsame");
  Q2_y95->Draw("Lsame");

  latex->DrawLatex(0.15,0.78,"#Deltay/y");

  aaa->Print("resolution_muic_dp05_dang1_Q2all_2D.pdf");
  aaa->Print("resolution_muic_dp05_dang1_Q2all_2D.png");

  TCanvas* bbb = new TCanvas("bbb","bbb",1200,870);
  bbb->Divide(3,3);
  bbb->cd(1);
//  bbb->GetPad(1)->SetRightMargin(0.0);
  bbb->GetPad(1)->SetLogx();
  bbb->GetPad(1)->SetLogy();
  hQ2resVsQ2xProjMean->Draw("colz");
  bbb->cd(2);
//  bbb->GetPad(2)->SetRightMargin(0.0);
  bbb->GetPad(2)->SetLogx();
  bbb->GetPad(2)->SetLogy();
  hxresVsQ2xProjMean->Draw("colz");
  bbb->cd(3);
//  bbb->GetPad(3)->SetRightMargin(0.0);
  bbb->GetPad(3)->SetLogx();
  bbb->GetPad(3)->SetLogy();
  hyresVsQ2xProjMean->Draw("colz");
  bbb->cd(4);
//  bbb->GetPad(4)->SetRightMargin(0.0);
  bbb->GetPad(4)->SetLogx();
  bbb->GetPad(4)->SetLogy();
  hQ2resVsQ2xJB5ProjMean->Draw("colz");
  bbb->cd(5);
//  bbb->GetPad(5)->SetRightMargin(0.0);
  bbb->GetPad(5)->SetLogx();
  bbb->GetPad(5)->SetLogy();
  hxresVsQ2xJB5ProjMean->Draw("colz");
  bbb->cd(6);
//  bbb->GetPad(6)->SetRightMargin(0.0);
  bbb->GetPad(6)->SetLogx();
  bbb->GetPad(6)->SetLogy();
  hyresVsQ2xJB5ProjMean->Draw("colz");
  bbb->cd(7);
//  bbb->GetPad(7)->SetRightMargin(0.0);
  bbb->GetPad(7)->SetLogx();
  bbb->GetPad(7)->SetLogy();
  hQ2resVsQ2xDA5ProjMean->Draw("colz");
  bbb->cd(8);
//  bbb->GetPad(8)->SetRightMargin(0.0);
  bbb->GetPad(8)->SetLogx();
  bbb->GetPad(8)->SetLogy();
  hxresVsQ2xDA5ProjMean->Draw("colz");
  bbb->cd(9);
//  bbb->GetPad(9)->SetRightMargin(0.0);
  bbb->GetPad(9)->SetLogx();
  bbb->GetPad(9)->SetLogy();
  hyresVsQ2xDA5ProjMean->Draw("colz");

  bbb->Print("mean_muic_dp05_dang1_Q2all_2D.pdf");
  bbb->Print("mean_muic_dp05_dang1_Q2all_2D.png");

  TCanvas* ccc = new TCanvas("ccc","ccc",1200,870);
  ccc->Divide(3,3);
  ccc->cd(1);
//  ccc->GetPad(1)->SetTopMargin(0.0);
  ccc->GetPad(1)->SetRightMargin(0.0);
//  ccc->GetPad(1)->SetLogx();
  ccc->GetPad(1)->SetLogz();
  hQ2resVsy->Draw("colz");
  hQ2resVsy_prof->Draw("PESAME");

  latex->DrawLatex(0.1,0.94,"MuIC: #mu^{-} (960) + p (275)");
  latex->DrawLatex(0.7,0.7,"Q^{2} > 3 GeV^{2}");

  ccc->cd(2);
//  ccc->GetPad(2)->SetTopMargin(0.0);
  ccc->GetPad(2)->SetRightMargin(0.0);
//  ccc->GetPad(2)->SetLogx();
  ccc->GetPad(2)->SetLogz();
  hxresVsy->Draw("colz");
  hxresVsy_prof->Draw("PESAME");
  latex->DrawLatex(0.4,0.94,"Lepton-only");

  ccc->cd(3);
//  ccc->GetPad(3)->SetTopMargin(0.0);
  ccc->GetPad(3)->SetRightMargin(0.0);
//  ccc->GetPad(3)->SetLogx();
  ccc->GetPad(3)->SetLogz();
  hyresVsy->Draw("colz");
  hyresVsy_prof->Draw("PESAME");
  ccc->cd(4);
//  ccc->GetPad(4)->SetTopMargin(0.0);
  ccc->GetPad(4)->SetRightMargin(0.0);
//  ccc->GetPad(4)->SetLogx();
  ccc->GetPad(4)->SetLogz();
  hQ2resVsyJB5->Draw("colz");
  hQ2resVsyJB5_prof->Draw("PESAME");
  ccc->cd(5);
//  ccc->GetPad(5)->SetTopMargin(0.0);
  ccc->GetPad(5)->SetRightMargin(0.0);
//  ccc->GetPad(5)->SetLogx();
  ccc->GetPad(5)->SetLogz();
  hxresVsyJB5->Draw("colz");
  hxresVsyJB5_prof->Draw("PESAME");
  latex->DrawLatex(0.2,0.94,"Jacquet-Blondel (|#eta_{h}| < 5)");

  ccc->cd(6);
//  ccc->GetPad(6)->SetTopMargin(0.0);
  ccc->GetPad(6)->SetRightMargin(0.0);
//  ccc->GetPad(6)->SetLogx();
  ccc->GetPad(6)->SetLogz();
  hyresVsyJB5->Draw("colz");
  hyresVsyJB5_prof->Draw("PESAME");
  ccc->cd(7);
//  ccc->GetPad(7)->SetTopMargin(0.0);
  ccc->GetPad(7)->SetRightMargin(0.0);
//  ccc->GetPad(7)->SetLogx();
  ccc->GetPad(7)->SetLogz();
  hQ2resVsyDA5->Draw("colz");
  hQ2resVsyDA5_prof->Draw("PESAME");
  ccc->cd(8);
//  ccc->GetPad(8)->SetTopMargin(0.0);
  ccc->GetPad(8)->SetRightMargin(0.0);
//  ccc->GetPad(8)->SetLogx();
  ccc->GetPad(8)->SetLogz();
  hxresVsyDA5->Draw("colz");
  hxresVsyDA5_prof->Draw("PESAME");
  latex->DrawLatex(0.3,0.94,"Double Angle (|#eta_{h}| < 5)");

  ccc->cd(9);
//  ccc->GetPad(9)->SetTopMargin(0.0);
  ccc->GetPad(9)->SetRightMargin(0.0);
//  ccc->GetPad(9)->SetLogx();
  ccc->GetPad(9)->SetLogz();
  hyresVsyDA5->Draw("colz");
  hyresVsyDA5_prof->Draw("PESAME");

  ccc->Print("resolution_muic_dp05_dang1_Q23.pdf");
  ccc->Print("resolution_muic_dp05_dang1_Q23.png");

  TCanvas* ccc1 = new TCanvas("ccc1","ccc1",1200,870);
  ccc1->Divide(3,3);
  ccc1->cd(1);
  ccc1->GetPad(1)->SetRightMargin(0.0);
//  ccc->GetPad(1)->SetLogx();
  ccc1->GetPad(1)->SetLogz();
  hQ2resVsx->Draw("colz");
  hQ2resVsx_prof->Draw("PESAME");

  latex->DrawLatex(0.1,0.94,"MuIC: #mu^{-} (960) + p (275)");
  latex->DrawLatex(0.7,0.7,"Q^{2} > 3 GeV^{2}");

  ccc1->cd(2);
  ccc1->GetPad(2)->SetRightMargin(0.0);
//  ccc->GetPad(2)->SetLogx();
  ccc1->GetPad(2)->SetLogz();
  hxresVsx->Draw("colz");
  hxresVsx_prof->Draw("PESAME");
  latex->DrawLatex(0.4,0.94,"Lepton-only");

  ccc1->cd(3);
  ccc1->GetPad(3)->SetRightMargin(0.0);
//  ccc->GetPad(3)->SetLogx();
  ccc1->GetPad(3)->SetLogz();
  hyresVsx->Draw("colz");
  hyresVsx_prof->Draw("PESAME");
  ccc1->cd(4);
  ccc1->GetPad(4)->SetRightMargin(0.0);
//  ccc->GetPad(4)->SetLogx();
  ccc1->GetPad(4)->SetLogz();
  hQ2resVsxJB5->Draw("colz");
  hQ2resVsxJB5_prof->Draw("PESAME");
  ccc1->cd(5);
  ccc1->GetPad(5)->SetRightMargin(0.0);
//  ccc->GetPad(5)->SetLogx();
  ccc1->GetPad(5)->SetLogz();
  hxresVsxJB5->Draw("colz");
  hxresVsxJB5_prof->Draw("PESAME");
  latex->DrawLatex(0.2,0.94,"Jacquet-Blondel (|#eta_{h}| < 5)");

  ccc1->cd(6);
  ccc1->GetPad(6)->SetRightMargin(0.0);
//  ccc1->GetPad(6)->SetLogx();
  ccc1->GetPad(6)->SetLogz();
  hyresVsxJB5->Draw("colz");
  hyresVsxJB5_prof->Draw("PESAME");
  ccc1->cd(7);
  ccc1->GetPad(7)->SetRightMargin(0.0);
//  ccc->GetPad(7)->SetLogx();
  ccc1->GetPad(7)->SetLogz();
  hQ2resVsxDA5->Draw("colz");
  hQ2resVsxDA5_prof->Draw("PESAME");
  ccc1->cd(8);
  ccc1->GetPad(8)->SetRightMargin(0.0);
//  ccc->GetPad(8)->SetLogx();
  ccc1->GetPad(8)->SetLogz();
  hxresVsxDA5->Draw("colz");
  hxresVsxDA5_prof->Draw("PESAME");
  latex->DrawLatex(0.3,0.94,"Double Angle (|#eta_{h}| < 5)");

  ccc1->cd(9);
  ccc1->GetPad(9)->SetRightMargin(0.0);
//  ccc->GetPad(9)->SetLogx();
  ccc1->GetPad(9)->SetLogz();
  hyresVsxDA5->Draw("colz");
  hyresVsxDA5_prof->Draw("PESAME");

  ccc1->Print("resolutionx_muic_dp05_dang1_Q23.pdf");
  ccc1->Print("resolutionx_muic_dp05_dang1_Q23.png");

return;
  TCanvas* c = new TCanvas("c","c",1200,1200);
  c->Divide(3,3);
  c->cd(1);
//  c->GetPad(1)->SetLogx();
  c->GetPad(1)->SetLogz();
  hQ2resVsQ2->Draw("colz");
  hQ2resVsQ2_prof->Draw("PESAME");
  c->cd(2);
//  c->GetPad(2)->SetLogx();
  c->GetPad(2)->SetLogz();
  hQ2resVsx->Draw("colz");
  hQ2resVsx_prof->Draw("PESAME");
  c->cd(3);
//  c->GetPad(3)->SetLogx();
  c->GetPad(3)->SetLogz();
  hQ2resVsy->Draw("colz");
  hQ2resVsy_prof->Draw("PESAME");
  c->cd(4);
//  c->GetPad(4)->SetLogx();
  c->GetPad(4)->SetLogz();
  hxresVsQ2->Draw("colz");
  hxresVsQ2_prof->Draw("PESAME");
  c->cd(5);
//  c->GetPad(5)->SetLogx();
  c->GetPad(5)->SetLogz();
  hxresVsx->Draw("colz");
  hxresVsx_prof->Draw("PESAME");
  c->cd(6);
//  c->GetPad(6)->SetLogx();
  c->GetPad(6)->SetLogz();
  hxresVsy->Draw("colz");
  hxresVsy_prof->Draw("PESAME");
  c->cd(7);
//  c->GetPad(7)->SetLogx();
  c->GetPad(7)->SetLogz();
  hyresVsQ2->Draw("colz");
  hyresVsQ2_prof->Draw("PESAME");
  c->cd(8);
//  c->GetPad(8)->SetLogx();
  c->GetPad(8)->SetLogz();
  hyresVsx->Draw("colz");
  hyresVsx_prof->Draw("PESAME");
  c->cd(9);
//  c->GetPad(9)->SetLogx();
  c->GetPad(9)->SetLogz();
  hyresVsy->Draw("colz");
  hyresVsy_prof->Draw("PESAME");
/*
  TCanvas* c1 = new TCanvas("c1","c1",1200,1200);
  c1->Divide(3,3);
  c1->cd(1);
  c1->GetPad(1)->SetLogx();
  c1->GetPad(1)->SetLogz();
  hQ2resVsQ2JB->Draw("colz");
  c1->cd(2);
  c1->GetPad(2)->SetLogx();
  c1->GetPad(2)->SetLogz();
  hQ2resVsxJB->Draw("colz");
  c1->cd(3);
  c1->GetPad(3)->SetLogx();
  c1->GetPad(3)->SetLogz();
  hQ2resVsyJB->Draw("colz");
  c1->cd(4);
  c1->GetPad(4)->SetLogx();
  c1->GetPad(4)->SetLogz();
  hxresVsQ2JB->Draw("colz");
  c1->cd(5);
  c1->GetPad(5)->SetLogx();
  c1->GetPad(5)->SetLogz();
  hxresVsxJB->Draw("colz");
  c1->cd(6);
  c1->GetPad(6)->SetLogx();
  c1->GetPad(6)->SetLogz();
  hxresVsyJB->Draw("colz");
  c1->cd(7);
  c1->GetPad(7)->SetLogx();
  c1->GetPad(7)->SetLogz();
  hyresVsQ2JB->Draw("colz");
  c1->cd(8);
  c1->GetPad(8)->SetLogx();
  c1->GetPad(8)->SetLogz();
  hyresVsxJB->Draw("colz");
  c1->cd(9);
  c1->GetPad(9)->SetLogx();
  c1->GetPad(9)->SetLogz();
  hyresVsyJB->Draw("colz");

  TCanvas* c2 = new TCanvas("c2","c2",1200,1200);
  c2->Divide(3,3);
  c2->cd(1);
  c2->GetPad(1)->SetLogx();
  c2->GetPad(1)->SetLogz();
  hQ2resVsQ2JB4->Draw("colz");
  c2->cd(2);
  c2->GetPad(2)->SetLogx();
  c2->GetPad(2)->SetLogz();
  hQ2resVsxJB4->Draw("colz");
  c2->cd(3);
  c2->GetPad(3)->SetLogx();
  c2->GetPad(3)->SetLogz();
  hQ2resVsyJB4->Draw("colz");
  c2->cd(4);
  c2->GetPad(4)->SetLogx();
  c2->GetPad(4)->SetLogz();
  hxresVsQ2JB4->Draw("colz");
  c2->cd(5);
  c2->GetPad(5)->SetLogx();
  c2->GetPad(5)->SetLogz();
  hxresVsxJB4->Draw("colz");
  c2->cd(6);
  c2->GetPad(6)->SetLogx();
  c2->GetPad(6)->SetLogz();
  hxresVsyJB4->Draw("colz");
  c2->cd(7);
  c2->GetPad(7)->SetLogx();
  c2->GetPad(7)->SetLogz();
  hyresVsQ2JB4->Draw("colz");
  c2->cd(8);
  c2->GetPad(8)->SetLogx();
  c2->GetPad(8)->SetLogz();
  hyresVsxJB4->Draw("colz");
  c2->cd(9);
  c2->GetPad(9)->SetLogx();
  c2->GetPad(9)->SetLogz();
  hyresVsyJB4->Draw("colz");
*/

  TCanvas* c3 = new TCanvas("c3","c3",1200,1200);
  c3->Divide(3,3);
  c3->cd(1);
//  c3->GetPad(1)->SetLogx();
  c3->GetPad(1)->SetLogz();
  hQ2resVsQ2JB5->Draw("colz");
  hQ2resVsQ2JB5_prof->Draw("PESAME");
  c3->cd(2);
//  c3->GetPad(2)->SetLogx();
  c3->GetPad(2)->SetLogz();
  hQ2resVsxJB5->Draw("colz");
  hQ2resVsxJB5_prof->Draw("PESAME");
  c3->cd(3);
//  c3->GetPad(3)->SetLogx();
  c3->GetPad(3)->SetLogz();
  hQ2resVsyJB5->Draw("colz");
  hQ2resVsyJB5_prof->Draw("PESAME");
  c3->cd(4);
//  c3->GetPad(4)->SetLogx();
  c3->GetPad(4)->SetLogz();
  hxresVsQ2JB5->Draw("colz");
  hxresVsQ2JB5_prof->Draw("PESAME");
  c3->cd(5);
//  c3->GetPad(5)->SetLogx();
  c3->GetPad(5)->SetLogz();
  hxresVsxJB5->Draw("colz");
  hxresVsxJB5_prof->Draw("PESAME");
  c3->cd(6);
//  c3->GetPad(6)->SetLogx();
  c3->GetPad(6)->SetLogz();
  hxresVsyJB5->Draw("colz");
  hxresVsyJB5_prof->Draw("PESAME");
  c3->cd(7);
//  c3->GetPad(7)->SetLogx();
  c3->GetPad(7)->SetLogz();
  hyresVsQ2JB5->Draw("colz");
  hyresVsQ2JB5_prof->Draw("PESAME");
  c3->cd(8);
//  c3->GetPad(8)->SetLogx();
  c3->GetPad(8)->SetLogz();
  hyresVsxJB5->Draw("colz");
  hyresVsxJB5_prof->Draw("PESAME");
  c3->cd(9);
//  c3->GetPad(9)->SetLogx();
  c3->GetPad(9)->SetLogz();
  hyresVsyJB5->Draw("colz");
  hyresVsyJB5_prof->Draw("PESAME");

/*
  TCanvas* c4 = new TCanvas("c4","c4",1200,1200);
  c4->Divide(3,3);
  c4->cd(1);
  c4->GetPad(1)->SetLogx();
  c4->GetPad(1)->SetLogz();
  hQ2resVsQ2DA->Draw("colz");
  c4->cd(2);
  c4->GetPad(2)->SetLogx();
  c4->GetPad(2)->SetLogz();
  hQ2resVsxDA->Draw("colz");
  c4->cd(3);
  c4->GetPad(3)->SetLogx();
  c4->GetPad(3)->SetLogz();
  hQ2resVsyDA->Draw("colz");
  c4->cd(4);
  c4->GetPad(4)->SetLogx();
  c4->GetPad(4)->SetLogz();
  hxresVsQ2DA->Draw("colz");
  c4->cd(5);
  c4->GetPad(5)->SetLogx();
  c4->GetPad(5)->SetLogz();
  hxresVsxDA->Draw("colz");
  c4->cd(6);
  c4->GetPad(6)->SetLogx();
  c4->GetPad(6)->SetLogz();
  hxresVsyDA->Draw("colz");
  c4->cd(7);
  c4->GetPad(7)->SetLogx();
  c4->GetPad(7)->SetLogz();
  hyresVsQ2DA->Draw("colz");
  c4->cd(8);
  c4->GetPad(8)->SetLogx();
  c4->GetPad(8)->SetLogz();
  hyresVsxDA->Draw("colz");
  c4->cd(9);
  c4->GetPad(9)->SetLogx();
  c4->GetPad(9)->SetLogz();
  hyresVsyDA->Draw("colz");

  TCanvas* c5 = new TCanvas("c5","c5",1200,1200);
  c5->Divide(3,3);
  c5->cd(1);
  c5->GetPad(1)->SetLogx();
  c5->GetPad(1)->SetLogz();
  hQ2resVsQ2DA4->Draw("colz");
  c5->cd(2);
  c5->GetPad(2)->SetLogx();
  c5->GetPad(2)->SetLogz();
  hQ2resVsxDA4->Draw("colz");
  c5->cd(3);
  c5->GetPad(3)->SetLogx();
  c5->GetPad(3)->SetLogz();
  hQ2resVsyDA4->Draw("colz");
  c5->cd(4);
  c5->GetPad(4)->SetLogx();
  c5->GetPad(4)->SetLogz();
  hxresVsQ2DA4->Draw("colz");
  c5->cd(5);
  c5->GetPad(5)->SetLogx();
  c5->GetPad(5)->SetLogz();
  hxresVsxDA4->Draw("colz");
  c5->cd(6);
  c5->GetPad(6)->SetLogx();
  c5->GetPad(6)->SetLogz();
  hxresVsyDA4->Draw("colz");
  c5->cd(7);
  c5->GetPad(7)->SetLogx();
  c5->GetPad(7)->SetLogz();
  hyresVsQ2DA4->Draw("colz");
  c5->cd(8);
  c5->GetPad(8)->SetLogx();
  c5->GetPad(8)->SetLogz();
  hyresVsxDA4->Draw("colz");
  c5->cd(9);
  c5->GetPad(9)->SetLogx();
  c5->GetPad(9)->SetLogz();
  hyresVsyDA4->Draw("colz");
*/

  TCanvas* c6 = new TCanvas("c6","c6",1200,1200);
  c6->Divide(3,3);
  c6->cd(1);
//  c6->GetPad(1)->SetLogx();
  c6->GetPad(1)->SetLogz();
  hQ2resVsQ2DA5->Draw("colz");
  hQ2resVsQ2DA5_prof->Draw("PESAME");
  c6->cd(2);
//  c6->GetPad(2)->SetLogx();
  c6->GetPad(2)->SetLogz();
  hQ2resVsxDA5->Draw("colz");
  hQ2resVsxDA5_prof->Draw("PESAME");
  c6->cd(3);
//  c6->GetPad(3)->SetLogx();
  c6->GetPad(3)->SetLogz();
  hQ2resVsyDA5->Draw("colz");
  hQ2resVsyDA5_prof->Draw("PESAME");
  c6->cd(4);
//  c6->GetPad(4)->SetLogx();
  c6->GetPad(4)->SetLogz();
  hxresVsQ2DA5->Draw("colz");
  hxresVsQ2DA5_prof->Draw("PESAME");
  c6->cd(5);
//  c6->GetPad(5)->SetLogx();
  c6->GetPad(5)->SetLogz();
  hxresVsxDA5->Draw("colz");
  hxresVsxDA5_prof->Draw("PESAME");
  c6->cd(6);
//  c6->GetPad(6)->SetLogx();
  c6->GetPad(6)->SetLogz();
  hxresVsyDA5->Draw("colz");
  hxresVsyDA5_prof->Draw("PESAME");
  c6->cd(7);
//  c6->GetPad(7)->SetLogx();
  c6->GetPad(7)->SetLogz();
  hyresVsQ2DA5->Draw("colz");
  hyresVsQ2DA5_prof->Draw("PESAME");
  c6->cd(8);
//  c6->GetPad(8)->SetLogx();
  c6->GetPad(8)->SetLogz();
  hyresVsxDA5->Draw("colz");
  hyresVsxDA5_prof->Draw("PESAME");
  c6->cd(9);
//  c6->GetPad(9)->SetLogx();
  c6->GetPad(9)->SetLogz();
  hyresVsyDA5->Draw("colz");
  hyresVsyDA5_prof->Draw("PESAME");


  c->Print("resolution_muic_dp05_dang05_Q23.pdf");
  c->Print("resolution_muic_dp05_dang05_Q23.png");
}
