#include <iostream>
using namespace std;
#include "EasyAssert.h"

unsigned TrouveCarDansString (char Caract, string Chaine,unsigned Debut){
    unsigned i;
    i = Debut;
    while (i != Chaine.size() and Caract != Chaine[i])
    {
        i = i+1;
    }
    return i;
    
}
void AssertTrouveCarDansString(char Caract, string Chaine,unsigned Debut){
    EASY_ASSERT(TrouveCarDansString(Caract, Chaine, Debut));
}

int main(){
    string str;
    str = "Salut ca va ?";
    cout << TrouveCarDansString('c', str, 0) << endl;
    AssertTrouveCarDansString('a', str, 0);
    return 0;
}