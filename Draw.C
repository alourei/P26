{
  //TFile *out=new TFile("output.root");
  TFile *out=new TFile("output_partial.root");
  TH1F *h[20];
  TCanvas *c=new TCanvas();
  c->Divide(4,5);
  Char_t hname[256];
  for(Int_t i=0;i<20;i++){
    sprintf(hname,"hGeDSSDx_%d",i);
    h[i]=(TH1F*)out->Get(hname);
    h[i]->GetXaxis()->SetRangeUser(0,500);
    c->cd(i+1);
    h[i]->Draw();
  }
  
}
