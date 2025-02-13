cuadratica1(){
	Int_t NumData = 10000;
	Int_t NumBarras = 50;
	Float_t x, u, Fre, Fre_R;

	TH1F *h = new TH1F("h", "Cuadratica", NumBarras, 0, 6);
	TH1F *hfr = new TH1F("FrecRel", "Cuadratica(Frecuencia relativa)", NumBarras, 0, 6);

	for(Int_t i = 0; i < NumData; i++){
		u = gRandom->Rndm();
		x = pow(216.*u, 0.333333);
		h->Fill(x);
	}

	h->SetFillColor(12);
	h->Draw();

	for(Int_t i=0; i < NumBarras; i++){
		Fre = h->GetBinContent(i+1);
		cout<<Fre<<endl;
		Fre_R = Fre / NumData;
		cout<<Fre_R<<endl;
		hfr->Fill(i+1, Fre_R);
	}
	hfr->SetFillColor(12);
}