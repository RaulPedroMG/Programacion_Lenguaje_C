uniforme1(){

gROOT->Reset();
	Int_t NumData = 10000;
	Int_t NumBarras = 10;
	Float_t x;

	TH1F *h = new TH1F("Uniforme", "Uniforme", NumBarras, 5, 7);
	TH1F *hfr = new TH1F("FrecRel", "Cuadratica(Frecuencia relativa)", NumBarras, 5, 7);

	for(Int_t i = 0; i < NumData; i++){
		x = 5+2*(gRandom->Rndm());
		h->Fill(x);
	}
	h->SetMinimum(0);
	h->SetFillColor(12);
	h->Draw();

	for(Int_t i=0; i < NumBarras; i++){
		Fre = h->GetBinContent(i+1);
		cout<<Fre<<endl;
		Fre_R = Fre / NumData;
		cout<<Fre_R<<endl;
		hfr->SetBinContent(i+1, Fre_R);
	}
	hfr->SetMinimum(0);
	hfr->SetFillColor(12);
}