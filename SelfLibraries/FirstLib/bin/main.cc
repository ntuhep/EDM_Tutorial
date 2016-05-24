#include <iostream>

using namespace std;

void FirstLib();  // in SelfLibraries/FirstLib/src 
void SecondLib(); // in SelfLibraries/SecondLib/src

int main() 
{
   cout << "From main, Hello world!" << endl;
   for( int i = 0 ; i < 3 ; ++i ){
      FirstLib();
   }
   SecondLib();
}
