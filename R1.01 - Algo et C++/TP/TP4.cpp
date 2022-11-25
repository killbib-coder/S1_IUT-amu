#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;

// TD3
void afficheTabInt(const vector<int> & tabInt){
    for (unsigned i = 0; i < tabInt.size(); i++)
    {
        cout << tabInt[i] << " ";
    }
    
}

vector<int> genereTabInt(){
    cout << "Saisir taille du tableau : ";
    unsigned n;
    cin >> n;
    vector<int> tabInt(n); 
    for (unsigned i = 0; i < n; i++)
    {
        cout << "Saisir la valeur a la position " << i+1 << " : ";
        cin >> tabInt[i];
    }
    return tabInt;
} void testGenereTabInt(){
    vector<int> tabInt = genereTabInt();
    afficheTabInt(tabInt);
}


// TD4

unsigned saisirEntierSupX (const string & Invite, const string & erreur, const unsigned & X){
    int N;
    while (true)
    {
        cout << Invite;
        cin >> N;
        if(N > X) break;
        cout << "erreur" << endl;
    }
    return N;    
} void testSaisirEntierSupX(){
    int Z;
    cout << "Entrer la somme : ";
    cin >> Z;
    unsigned N = saisirEntierSupX("Entrer un nombre : ", "Plus grand que",Z);
    cout << "Nombre de saisie : " << N;
}


unsigned find(const int & Val, const vector<int> & tabInt){
    for (unsigned i = 0; i < tabInt.size(); i++)
    {
        if(tabInt[i]==Val) return i;
    }
    return tabInt.size();
} void testFind(){
    int Val, posVal;
    vector<int> tabInt = genereTabInt();
    cout << "Saisir la valeur a chercher : ";
    cin >> Val;
    posVal = find(Val,tabInt);
    cout << "La valeur cherché est a la position " << posVal;
}


vector<int> genereTabIntAleaSansRedondance(const unsigned & N, const unsigned & M){
    srand(time(NULL));
    vector<int> tabInt(1);
    tabInt[0] = rand()%N;
    unsigned i = 0;
    int vAlea;
    while (i<N-1)
    {
        vAlea=rand()%N+1;
        
        if (find(vAlea,tabInt)==tabInt.size())
        {
            tabInt.resize(tabInt.size()+1);
            tabInt[tabInt.size()-1] = vAlea;
            i=i+1;
        }
    }
    return tabInt;    
} void testGenereTabIntAleaSansRedondance(){
    unsigned N;
    cout << "Saisir taille tableau : ";
    cin >> N;
    vector<int> tabInt = genereTabIntAleaSansRedondance(N,6);
    for (unsigned i = 0; i < tabInt.size(); i++)
    {
        if(find(tabInt[i], tabInt)== tabInt.size()) 
            cout << "Erreur";
    }

    afficheTabInt(tabInt);
}



int main(){
    testGenereTabIntAleaSansRedondance();
    return 0;
}