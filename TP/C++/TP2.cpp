#include <iostream>
using namespace std;
#include "EasyAssert.h"


// Exo1
unsigned TrouveCarDansString (char Caract, string Chaine,unsigned Debut){
    unsigned i;
    i = Debut;
    while (i != Chaine.size() and Caract != Chaine[i])
    {
        i += 1;
    }
    return i;
    
} void AssertTrouveCarDansString(){
    string Str = "Salut ca va";
    EASY_ASSERT(TrouveCarDansString('a', Str, 0)==1);
    EASY_ASSERT(TrouveCarDansString('a', Str, 3)==7);
    EASY_ASSERT(TrouveCarDansString('a', Str, 6)==7);
    EASY_ASSERT(TrouveCarDansString('b', Str, 6)==Str.size());
}


// Exo2
unsigned ComptCarac(char Caract, string Chaine){
    unsigned Cpt = 0;
    for (unsigned i = 0; i < Chaine.size()-1; i++)
    {
        if (Caract == Chaine[i])
        {
            Cpt+=1;
        }
    }
    return Cpt;
} void AssertComptCarac(){
    string Str = "Salut ca va?";
    EASY_ASSERT(ComptCarac('a', Str)==3);
    EASY_ASSERT(ComptCarac('b', Str)==0);
}


// Exo3
unsigned ComptCaracV2(char Caract, string Chaine){
    unsigned Cpt = 0, Pos = 0;
    while (true)
    {
        Pos = TrouveCarDansString(Caract,Chaine,Pos);
        if(Pos == Chaine.size()) break;
        Cpt+=1;
        Pos+=1;
    }
    return Cpt;    
} void AssertComptCaracV2(){
    string Str = "Salut ca va?";
    EASY_ASSERT(ComptCarac('a', Str)==3);
    EASY_ASSERT(ComptCarac('b', Str)==0);
}


int main(){
    AssertComptCaracV2();
    return 0;
}