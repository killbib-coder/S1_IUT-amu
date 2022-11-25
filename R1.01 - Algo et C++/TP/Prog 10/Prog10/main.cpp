//
//    Title: Jeu voleur contrebendier
//
//    Author: Killbib
//
//    Version: 1.1
//

#include <iostream>
#include <vector>
using namespace std;

void clearscreen(){
    cout << "\033[H\033[2J";
}
const unsigned KReset   (0);
const unsigned KRouge   (31);
const unsigned KBleu    (34);
void couleur (const unsigned & coul) {
    cout << "\033[" << coul <<"m";
}

typedef vector <char> CVLine; // un type représentant une ligne de la grille
typedef vector <CVLine> CMatrix; // un type représentant la grille
const char kTokenPlayer1 = 'X';
const char kTokenPlayer2 = 'O';
const char kEmpty        = '+';
void  showMatrix (const CMatrix & Mat){
    clearscreen();
    couleur (KReset);
    for (unsigned i = 0; i < Mat.size()+2; ++i) {
        cout << "- ";
    }
    cout << endl;
    for ( const CVLine & uneligne: Mat){
        cout << "| ";
        for ( const char & cell : uneligne){
            if ( cell==kTokenPlayer1)
                couleur ( KRouge);
            else if ( cell==kTokenPlayer2)
                couleur ( KBleu);
            else
                couleur ( KReset);
                cout << cell << " ";
        }
        couleur(KReset);
        cout << "|";
        cout << endl;
    }
    for (unsigned i = 0; i < Mat.size()+2; ++i) {
        cout << "- ";
    }
    cout << endl;
}
struct CPosition
{
    unsigned abscisse;
    unsigned ordonne;
};
void initMat (CMatrix & Mat, unsigned nbLine, unsigned nbColumn, CPosition & posPlayer1, CPosition & posPlayer2){
    for (int i = 0; i < nbLine; ++i) {
        Mat.push_back(CVLine(nbLine,kEmpty));
    }
    Mat[0][Mat.size()-1] = kTokenPlayer1;
    Mat[Mat.size()-1][0] = kTokenPlayer2;
    posPlayer1 = {unsigned(Mat.size()-1),0};
    posPlayer2 = {0,unsigned(Mat.size()-1)};
}

void moveToken (CMatrix & Mat, char move, CPosition  & pos){
    switch (move) {
        case 'a':
            Mat[pos.ordonne-1][pos.abscisse-1]=Mat[pos.ordonne][pos.abscisse];
            Mat[pos.ordonne][pos.abscisse]=kEmpty;
            pos = {pos.abscisse-1,pos.ordonne-1};
            break;
        case 'z':
            Mat[pos.ordonne-1][pos.abscisse]=Mat[pos.ordonne][pos.abscisse];
            Mat[pos.ordonne][pos.abscisse]=kEmpty;
            pos = {pos.abscisse,pos.ordonne-1};
            break;
        case 'e':
            Mat[pos.ordonne-1][pos.abscisse+1]=Mat[pos.ordonne][pos.abscisse];
            Mat[pos.ordonne][pos.abscisse]=kEmpty;
            pos = {pos.abscisse+1,pos.ordonne-1};
            break;
        case 'q':
            Mat[pos.ordonne][pos.abscisse-1]=Mat[pos.ordonne][pos.abscisse];
            Mat[pos.ordonne][pos.abscisse]=kEmpty;
            pos = {pos.abscisse-1,pos.ordonne};
            break;
        case 'd':
            Mat[pos.ordonne][pos.abscisse+1]=Mat[pos.ordonne][pos.abscisse];
            Mat[pos.ordonne][pos.abscisse]=kEmpty;
            pos = {pos.abscisse+1,pos.ordonne};
            break;
        case 'w':
            Mat[pos.ordonne+1][pos.abscisse-1]=Mat[pos.ordonne][pos.abscisse];
            Mat[pos.ordonne][pos.abscisse]=kEmpty;
            pos = {pos.abscisse-1,pos.ordonne+1};
            break;
        case 'x':
            Mat[pos.ordonne+1][pos.abscisse]=Mat[pos.ordonne][pos.abscisse];
            Mat[pos.ordonne][pos.abscisse]=kEmpty;
            pos = {pos.abscisse,pos.ordonne+1};
            break;
        case 'c':
            Mat[pos.ordonne+1][pos.abscisse+1]=Mat[pos.ordonne][pos.abscisse];
            Mat[pos.ordonne][pos.abscisse]=kEmpty;
            pos = {pos.abscisse+1,pos.ordonne+1};
            break;

        default:
            cout << "Mauvaise touche..." << endl;
            break;
    }
}

int ppal(){
    CMatrix Mat;
    CPosition pos1, pos2;
    initMat(Mat,10,10,pos1,pos2);
    unsigned coupMax=10;
    bool victoire=false;
    showMatrix(Mat);
    char deplacement;
    while(coupMax>1 and victoire!=true){
        cout << "deplacement joueur 1 : ";
        cin >> deplacement;
        moveToken(Mat,deplacement,pos1);
        showMatrix(Mat);
        if (pos1.abscisse==pos2.abscisse && pos1.ordonne==pos2.ordonne) {
            cout << "joueur 1 a gagné !" << endl;
            victoire=true;
            break;
        }
        cout << "deplacement joueur 2 : ";
        cin >> deplacement;
        moveToken(Mat,deplacement,pos2);
        showMatrix(Mat);
        if (pos2.abscisse==pos1.abscisse && pos2.ordonne==pos1.ordonne) {
            cout << "joueur 2 a gagné !" << endl;
            victoire=true;
            break;
        }
        --coupMax;
    }
    if(coupMax==1){
        cout << "Le nombre de coup max est atteint" << endl;
        cout << "Voulez-vous rejouer ? (o/n) : ";
        char rep;
        cin >> rep;
        if(rep=='o') ppal();
    }
    return 0;
}

int main(){
    ppal();
    return 0;
}
