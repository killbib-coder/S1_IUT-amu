#include <iostream>
using namespace std;


unsigned CompterDoublonWFor(string Chaine){
    if (Chaine.size() < 2) return 0;
    unsigned Compt = 0;
    for (unsigned i = 0; i != Chaine.size()-1; i++)
    {
        if (Chaine[i] == Chaine[i+1]) Compt+=1;
    }
    return Compt;    
}
unsigned CompterDoublonWhile(string Chaine){
    if (Chaine.size() < 2) return 0;
    unsigned Compt = 0, i = 0;
    while (i != Chaine.size()-1)
    {
        if (Chaine[i] == Chaine[i+1]) Compt +=1;
        i+=1;
    }
    return Compt;    
}
unsigned CompterDoublonForInverse(string Chaine){
    if (Chaine.size() < 2) return 0;
    unsigned Compt = 0;
    for (unsigned i = 1; i != Chaine.size(); i++)
    {
        if (Chaine[i] == Chaine[i-1]) Compt+=1;
    }
    return Compt;    
}
unsigned CompterDoublonWhileInverse(string Chaine){
    if (Chaine.size() < 2) return 0;
    unsigned Compt = 0, i = 1;
    while (i != Chaine.size())
    {
        if (Chaine[i] == Chaine[i-1]) Compt +=1;
        i+=1;
    }
    return Compt;    
}


int main(){
    string Str = "aa bn cc";
    unsigned resultTest = CompterDoublonForInverse(Str);
    cout << resultTest;
    return 0;
}