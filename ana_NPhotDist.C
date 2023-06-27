{
    ff = new TFile("data/noTwiss_Galactic_100k.root");
    tt = (TTree*) ff->Get("t1");
    
    Int_t odet_n;
    Int_t odet_ID[100], odet_nPhot[100];

    tt->SetBranchAddress("odet_n", &odet_n);
    tt->SetBranchAddress("odet_ID", odet_ID);       // Array do not need '&'
    tt->SetBranchAddress("odet_nPhot", odet_nPhot);

    Double_t nbins, max;

    nbins = 100;
    max = 800;

    hh = new TH2D("nPhot_100_200", "nPhot_100_200", nbins, 0, max, nbins, 0, max);

    nentries = tt->GetEntries();
    Int_t nPhot_100, nPhot_200;
    for (Long64_t i=0; i<nentries; i++){
        tt->GetEntry(i);

        nPhot_100=0;
        nPhot_200=0;

        for (int j=0; j<odet_n; j++){
            if (odet_ID[j] == 100) 
                nPhot_100 = nPhot_100 + odet_nPhot[j];
            if (odet_ID[j] == 300) 
                nPhot_200 += odet_nPhot[j];
        }

	if (nPhot_100 != 0 || nPhot_200 != 0) hh->Fill(nPhot_100, nPhot_200);
    }

    cc = new TCanvas("cc", "cc", 800, 600);
    hh->GetXaxis()->SetTitle("Nphot CH3");
    hh->GetYaxis()->SetTitle("Nphot CH5");
    hh->SetTitle("CH5 vs CH3");
    hh->Draw("colz");
    // cc->SaveAs("nPhot_7_9.png");

}
