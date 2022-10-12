#include <iostream>
using namespace std;

unsigned TrouveCarDansString (char & Caract, string & Chaine,unsigned & Debut){
    unsigned i;
    i = Debut;
    while (i != Chaine.size() and Caract != Chaine[i])
    {
        i = i+1;
    }
    return i;
    
}

int main(){
    string str;
    str = "Salut ca va ?";
    cout << TrouveCarDansString('a', str, 0);
    return 0;
}