#include<iostream>
#include<vector>
using namespace std;



int main(){
    unsigned nbElec,nmCandidat,choix,nbCandid;
    cout << "combien de candidat : ";
    cin >> nbCandid;
    cout << "combien d'électeur : ";
    cin >> nbElec;
    vector<unsigned> lsCandid (nbCandid);
    for (unsigned i = 0; i < lsCandid.size(); ++i) lsCandid[i]=0;
    for(unsigned i = 0; i < nbElec;i++){
        cout << "Numéro du candidat de 1 a " << nbCandid << " : ";
        cin >> nmCandidat ;
        nmCandidat--;
        cout << "Votez pour tapez 1" << endl
             << "Votez contre tapez 2" << endl
             << "Votre choix : ";
        cin >> choix;
        if (choix == 1){
            lsCandid[nmCandidat]++;
        }
        else if (choix == 2 && nmCandidat > 0){
            lsCandid[nmCandidat]--;
        }
    }
    unsigned max = 0,pos=0;
    size_t i =0;
    for(; i < lsCandid.size(); ++i){
        if(lsCandid[i]>max){
            max = lsCandid[i];
            pos=i+1;
        }
    }
    cout << "Le candidat élu est le numéro " << pos << endl;
    return 0;
}
