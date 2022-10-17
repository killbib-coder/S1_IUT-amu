#include <iostream>
#include <vector>
using namespace std;

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
}






int main(){
    vector<int> tabInt = genereTabInt();
    afficheTabInt(tabInt);
    return 0;
}