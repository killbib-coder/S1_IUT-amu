#include <iostream>
#include <vector>
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
        if(tabInt[i]==Val) return i+1;
    }
    return 0;
} void testFind(){
    int Val, posVal;
    vector<int> tabInt = genereTabInt();
    cout << "Saisir la valeur a chercher : ";
    cin >> Val;
    posVal = find(Val,tabInt);
    cout << "La valeur cherché est a la position " << posVal;
}



int main(){
    testFind();
    return 0;
}