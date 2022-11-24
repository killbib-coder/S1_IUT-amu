#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void affichVInt (const vector <int> & VInt){
    for (size_t i = 0; i < VInt.size(); ++i) {
        cout << VInt[i] << endl;
    }
}

template <typename T>
void affichVector (const vector <T> & V){
    for (size_t i = 0; i < V.size(); ++i) {
        cout << V[i] << endl;
    }
}

template <typename T>
void extractionsGenerique (T & Val){
//    for(T variable; cin >> variable;) cout << variable << endl;
    for(;cin >> Val;) cout << Val << endl;
}

template <typename T>
bool testSiFichierExists (T & stream){
    string sourcefile;
    unsigned i(0);
    for (; i < 3; ++i) {
        cout << "Nom du fichier : ";
        getline(cin,sourcefile);
        stream.open(sourcefile);
        if(stream) break;
    }
    if (i==3){
        std::cout << "3 echecs d'ouverture de fichier en lecture" << std::endl;
        return false;
    }
    return true;
}

int main(){
    int nombre;
    extractionsGenerique(nombre);
    return 0;
}
