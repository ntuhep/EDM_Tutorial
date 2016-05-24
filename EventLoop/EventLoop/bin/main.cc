#include <iostream>
#include "DataFormats/FWLite/interface/Event.h"
#include "DataFormats/FWLite/interface/Handle.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "TFile.h"

using namespace std;

int main( ){
   fwlite::Event ev( TFile::Open("/wk_cms/yichen/TstarAnalysis/filtered_MiniAODs/MuonSignal/TstarTstarToTgluonTgluon_M-1000_TuneCUETP8M1_13TeV-madgraph-pythia8/tstarBaseline_aa.root") );
   fwlite::Handle<vector<pat::Jet>>  my_handle;
   
   unsigned i = 0 ; 
   for( ev.toBegin() ; ! ev.atEnd() ; ++ev , ++i) {
      cout << "At Event [" << i << endl;
      my_handle.getByLabel( ev, "skimmedPatJets"  , "" ,"TstarBaseLine");
      const vector<pat::Jet>& jet_list = *(my_handle);

      for( unsigned i = 0 ; i < jet_list.size() ; ++i ) {
         for( unsigned j = 0 ; j < jet_list.size() ; ++j ) {
            cout << "Dijet mass: "
                 << ( jet_list[i].p4() + jet_list[j].p4() ).mass() << endl;
         }
      }

   }

   return 0;
}
