#include <iostream>
#include <vector>
using namespace std;

int main(){

    string str, temp;
    unsigned nbelecteur(0);
    cin >> str;
    nbelecteur=stoi(str);
    vector<string> noms(nbelecteur);
    vector<string> vote(nbelecteur);
    unsigned cptVote=0;
    for (size_t i = 0; i < nbelecteur; i++)
    {
        cin >> str;
        temp=str;
        cin >> str;
        noms[i]=temp+" "+str+" ";
        cin >> str;
        vote[cptVote]=str;
        cptVote++;
    }

    //afficher vecteurs
    for (size_t i = 0; i < noms.size(); i++)
    {
        cout << noms[i];
    }
    cout << endl;
    for (size_t i = 0; i < vote.size(); i++)
    {
        cout << vote[i];
    }
    
    return 0;
}