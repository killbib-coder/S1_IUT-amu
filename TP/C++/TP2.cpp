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
void AssertTrouveCarDansString(){
    string Str = "Salut ca va";
    EASY_ASSERT(TrouveCarDansString('a', Str, 0)==1);
    EASY_ASSERT(TrouveCarDansString('a', Str, 3)==7);
    EASY_ASSERT(TrouveCarDansString('a', Str, 6)==7);
    EASY_ASSERT(TrouveCarDansString('b', Str, 6)==11);
}

int main(){
    AssertTrouveCarDansString();
    return 0;
}