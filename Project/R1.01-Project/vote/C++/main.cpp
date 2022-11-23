#include <iostream>
#include <vector>
using namespace std;

int main(){

    string str,nom;

    unsigned i=1,compteur=0;
    vector<string> noms;
    vector<string> vote;
    unsigned cptVote=0;
    while (true)
    {
        getline(cin,str);
        if (cin.eof()) break;    
        
        if (compteur==0){
            nom=str;
            compteur++;
        }
        else if (compteur==1){
            noms.push_back(nom+" "+str);
            compteur++;
        }
        else if (compteur==2){
            vote.push_back(str);
            cptVote++;
            compteur=0;
        }
        i++;
        
    }
    cout << endl << endl;
    for (size_t i = 0; i < noms.size(); i++)
    {
        cout << noms[i]<<" / ";
    }
    cout << endl << endl;
    for (size_t i = 0; i < vote.size(); i++)
    {
        cout << vote[i];
    }
    
    return 0;
}