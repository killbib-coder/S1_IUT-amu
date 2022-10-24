#include <iostream>
#include <vector>
using namespace std;


string chiffrementParTransposition(string & phraseACrypter)
{
    vector<unsigned> cle(6);
    for (size_t i = 0; i < cle.size(); i++)
    {
        cout << "Saisir valeur : ";
        cin>>cle[i];
    }    
    unsigned compteur = 0;
    string resultat;
    for (size_t i = 0; i < phraseACrypter.size(); i++)
    {
        resultat += phraseACrypter[cle[i]];
    }
    return resultat;
}

int main(){
    string phraseACrypter = "uococu";
    string resultat;
    resultat = chiffrementParTransposition(phraseACrypter);
    cout << resultat;
}