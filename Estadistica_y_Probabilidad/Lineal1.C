Lineal1(){
	Int_t NumData = 1000000;
	Int_t NumBarras = 50;
	Float_t x, u, Fre, Fre_R;

	TH1F *h = new TH1F("h", "Cuadratica", NumBarras, 0, 3);
	TH1F *hfr = new TH1F("hrf", "Lineal(Frecuencia relativa)", NumBarras, 0, 3);

	for(Int_t i = 0; i < NumData; i++){
		u = gRandom->Integer(2);
		x = sqrt(9.*u);
		h->Fill(x);
	}

	h->SetFillColor(12);
	h->Draw();

	for(Int_t i=0; i < NumBarras; i++){
		Fre = h->GetBinContent(i+1);
		//cout<<Fre<<endl;
		Fre_R = Fre / NumData;
		//cout<<Fre_R<<endl;
		hfr->SetBinContent(i+1, Fre_R);
	}
	hfr->SetFillColor(12);
}