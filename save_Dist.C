{
    // ff = new TFile("data/musr_600.root");
    TFile *f = new TFile("data/musr_600.root");
    tree *t = new TTree(ff->Get("t1"));
    // t = (tree*) ff->Get("t1");
    
    Int_t save_n;
    Int_t save_detID[1000], save_particleID[1000];

    t->SetBranchAddress("save_n", &save_n);
    t->SetBranchAddress("save_detID", save_detID);       // Array do not need '&'
    t->SetBranchAddress("save_particleID", save_particleID);

    Double_t nbins, max;

    nbins = 100;
    max = 800;

    TH2D *hh = new TH2D("nPhot_100_200", "nPhot_100_200", nbins, 0, max, nbins, 0, max);

    nentries = t->GetEntries();
    Int_t nPhot_100, nPhot_200;
    for (Long64_t i=0; i<nentries; i++){
        t->GetEntry(i);

        nPhot_100=0;
        nPhot_200=0;

        for (int j=0; j<save_n; j++){
            if (save_detID[j] == 10 && save_particleID[j] == -22)
                nPhot_100 = nPhot_100 + save_detID[j];
            if (save_detID[j] == 12 && save_particleID[j] == -22)
                nPhot_200 += save_detID[j];
        }

	if (nPhot_100 != 0 || nPhot_200 != 0) hh->Fill(nPhot_100, nPhot_200);
    }

    TCanvas *cc = new TCanvas("cc", "cc", 800, 600);
    // hh->GetXaxis()->Setitle("Nphot CH3");
    // hh->GetYaxis()->Setitle("Nphot CH5");
    // hh->Setitle("CH5 vs CH3");
    hh->Draw("colz");
    // cc->SaveAs("nPhot_7_9.png");
}
