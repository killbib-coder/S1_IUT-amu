#include <iostream>
#include <vector>
using namespace std;

int main(vector<string> & Candidat, vector<vector<unsigned>> & Vote){
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