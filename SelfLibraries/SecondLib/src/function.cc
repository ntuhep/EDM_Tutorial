#include <iostream>

#include "TH1F.h"
#include "TCanvas.h"

void SecondLib()
{
   TCanvas* c = new TCanvas("c","c");
   TH1F* hist = new TH1F("hist","hist",10,0,10);
   for( int i = 0 ; i < 45 ; ++i ){
      hist->Fill( i%10 );
   }
   hist->Draw();
   c->SaveAs("test.png");
}
