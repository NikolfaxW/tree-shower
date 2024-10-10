#include <iostream>
#include <TFile.h>  // For handling ROOT files
#include <TTree.h>  // For handling ROOT trees
#include <TBranch.h>
#include <TLeaf.h>
#include <TChain.h>
#include <TH1F.h>

int main() {
    std::cout << "Hello, World!" << std::endl;
    TFile *file = TFile::Open("../../Pythia-project-tree-creator/results/Jet_tree2.root");
    TTree *tree = (TTree*)file->Get("T");
    tree->Print();  // Shows the tree structure (branches, leaves)
    tree->Scan();   // Shows the data in the tree
    file->Close();
    return 0;
}
