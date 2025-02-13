Ejercicio1(){
	Int_t NumD = 400;
	Int_t a, b, c;

	TH1F *hisEnt1 = new TH1F("hisEnt1", "Enteros", 10, -0.5, 9.5);
	TH1F *hisEnt2 = new TH1F("hisEnt2", "Enteros", 10, -0.5, 9.5);
	TH1F *hisEnt3 = new TH1F("hisEnt3", "Enteros", 10, -0.5, 9.5);

	for(Int_t i = 0; i < NumD; i++){
		a = gRandom->Integer(10);
		b = gRandom->Gaus(4.5, 1);
		c = gRandom->Gaus(4.5, 1.5);
		hisEnt1-> Fill(a);
		hisEnt2-> Fill(b);
		hisEnt3-> Fill(c);
	}
	hisEnt1->SetMinimum(0);
	//hisEnt2->SetMinimum(0);
	//hisEnt3->SetMinimum(0);
	hisEnt1->Draw();
	//hisEnt2->Draw();
	//hisEnt3->Draw();
}