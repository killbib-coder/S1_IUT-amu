#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void affichVInt (const vector <int> & VInt){
    for (size_t i = 0; i < VInt.size(); ++i) {
        cout << VInt[i] << endl;
    }
}

void affichVIntIterrator(const vector <int> & VInt){
    for (auto it = begin(VInt); it != end(VInt); ++it)
    {
        cout << *it << " ";
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

void triSelection (vector<int> & tab){
    int temp;
    temp = tab[0];
    unsigned min;
    for (size_t i = 0; i < tab.size()-1; ++i)
    {
        min=i;
        for (unsigned j = i+1; j < tab.size(); ++j)
        {
            if(tab[j] < tab[min]) min=j;
        }
        if (min != i)
        {
            temp=tab[i];
            tab[i]=tab[min];
            tab[min]=temp;
        }
    }
}

void triSelectionIter (vector<int> & tab){
    int temp = tab[0];
    unsigned min;
    unsigned cpt=0;
    for (auto it = begin(tab); it != end(tab); ++it)
    {
        min=cpt;
        for (auto it2 = begin(tab)+1; it2 != end(tab); ++it2){
            
        }
    }
}

int main(){
    // int nombre;
    // extractionsGenerique(nombre);
    vector<int> VInt{1,2,3,4,5,6,7,8};
    affichVIntIterrator(VInt);
    return 0;
}
