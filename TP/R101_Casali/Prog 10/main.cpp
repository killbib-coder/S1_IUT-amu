#include <iostream>
#include <vector>
using namespace std;

void clearscreen(){
    cout << "\033[H\033[2J";
}
const unsigned KReset   (0);
const unsigned KNoir    (30);
const unsigned KRouge   (31);
const unsigned KVert    (32);
const unsigned KJaune   (33);
const unsigned KBleu    (34);
const unsigned KMAgenta (35);
const unsigned KCyan    (36);
const unsigned KBackVert (42);   
void couleur (const unsigned & coul) {
    cout << "\033[" << coul <<"m";
}
void testCouleurs(){
    clearscreen();
    couleur (KRouge);
    cout << "Rouge" << endl;
    couleur (KVert);
    cout << "Vert" << endl;
    couleur (KReset);
    cout << "Retour à la normale" << endl;
    couleur (KBackVert);
    cout << "Fond vert" << endl;
    couleur (KReset);
}

typedef vector <char> CVLine; // un type représentant une ligne de la grille
typedef vector <CVLine> CMatrix; // un type représentant la grille
typedef pair   <unsigned, unsigned> CPosition; // un type représentant une coordonnée dans la grille
const char kTokenPlayer1 = 'X';
const char kTokenPlayer2 = 'O';
const char kEmpty        = '+';
void  showMatrix (const CMatrix & Mat){
    clearscreen();
    couleur (KReset);
    for ( const CVLine & uneligne: Mat){
        for ( const char & cell : uneligne){
            if ( cell==kTokenPlayer1)
                couleur ( KRouge);
            else if ( cell==kTokenPlayer2)
                couleur ( KBleu);
            else 
                couleur ( KReset);
                cout << cell << " ";
        }
        cout << endl;
    }    
}


int main(){
    CMatrix mat (10, CVLine(10,kEmpty));
    mat[0][mat.size()-1] = kTokenPlayer1;
    mat[mat.size()-1][0] = kTokenPlayer2;
    showMatrix(mat);
    return 0;
}