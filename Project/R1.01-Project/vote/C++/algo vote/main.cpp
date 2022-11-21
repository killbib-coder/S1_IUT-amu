#include <iostream>
#include <vector>
using namespace std;

void MethodeBorda(vector<string> & Candidat, vector<vector<unsigned>> & Vote){
    cout<<"Début du vote Methode Borda"<<endl<<endl;

    vector <float> Points (Candidat.size());
    for (unsigned i = 0; i<=Vote.size()-1;i++){ // on compte les points de chaque Candidats
        for (unsigned j = 0; j<=Vote[i].size()-1;j++){
            Points[Vote[i][j]]+=1-float(j)/float(Candidat.size());
        }
    }
    string vainqueur = Candidat[0]; // on définie par défaut le premier candidat comme vainqueur
    float Svainqueur = Points[0];
    cout<<"Le Candidat "<<Candidat[0]<<" a "<<Points[0]<<" points."<<endl;
    for (unsigned i = 1; i<=Points.size()-1;i++){ // on regarde chaque points des candidats pour voir qui à le plus de points
        cout<<"Le Candidat "<<Candidat[i]<<" a "<<Points[i]<<" points."<<endl;
        if (Points[i]>Svainqueur){
            Svainqueur=Points[i];
            vainqueur=Candidat[i];
        }
    }
    cout<<endl<<"Le vainqueur est : "<<vainqueur<<" avec "<<Svainqueur<<" points."<<endl<<endl;
}

void ScrutinUninominalMajoritaireUnTour(vector<string> & Candidat,vector<unsigned> & Vote){
    cout<<"Début du vote uninominatif majoritaire en un tour"<<endl<<endl;
    vector <unsigned> Points (Candidat.size());

    for (unsigned i = 0; i<=Vote.size()-1;i++){
        Points[Vote[i]]++;
    }

    string vainqueur = Candidat[0]; // on définie par défaut le premier candidat comme vainqueur
    float Svainqueur = Points[0];
    cout<<"Le Candidat "<<Candidat[0]<<" a "<<Points[0]<<" points."<<endl;
    for (unsigned i = 1; i<=Points.size()-1;i++){ // on regarde chaque points des candidats pour voir qui à le plus de points
        cout<<"Le Candidat "<<Candidat[i]<<" a "<<Points[i]<<" points."<<endl;
        if (Points[i]>Svainqueur){
            Svainqueur=Points[i];
            vainqueur=Candidat[i];
        }
    }
    cout<<endl<<"Le vainqueur est : "<<vainqueur<<" avec "<<Svainqueur<<" points."<<endl<<endl;
}

int main()
{
    vector <string> candidat (10);
    vector <vector<unsigned>> Vote (2);
    vector<unsigned> v1 (2);
    vector<unsigned> v2 (4);
    v1[0]=5;
    v1[1]=3;
    Vote[0]=v1;
    v2[0]=6;
    v2[1]=5;
    v2[2]=2;
    v2[3]=1;
    Vote[1]=v2;

    MethodeBorda(candidat,Vote);

    vector <string> Candidat2 (10);
    vector <unsigned> Vote2 (5);
    Vote2[0]=3;
    Vote2[1]=2;
    Vote2[2]=4;
    Vote2[3]=5;
    Vote2[4]=3;


    ScrutinUninominalMajoritaireUnTour(Candidat2,Vote2);
    return 0;
}
