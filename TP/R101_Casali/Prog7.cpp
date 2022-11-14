#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

void flux_cin(){
    string ficelle;
    while(true){
        std::cin >> ficelle;
        if (cin.eof()) break;
        std::cout << ficelle << std::endl;
    }
}

void affichefich(){
    /*ifstream ifs ("LaFontaine.txt");
    vector <string> VString;
    string Line;

    for ( ;getline (ifs, Line); ) VString.push_back (Line);
    for (size_t i = 0; i < VString.size(); i++) std::cout << VString[i] << std::endl;*/
    ifstream ifs ("LaFontaine.txt");
    string str;
    while (true){
        getline(ifs,str);
        std::cout << str << std::endl;
        if (ifs.eof()) break;
    }
}

void nomFichAuClavier(){
    string sourceFile, destFile;
    std::cout << "Fichier source : ";
    getline(cin,sourceFile);
    std::cout << "Fichier destination : ";
    getline(cin,destFile);
    ifstream source (sourceFile);
    ofstream destination (destFile);

    string str;
    long unsigned cpt = 0;
    while (!source.eof()){
        getline(source,str);
        cpt++;
        destination << cpt << ' ' << str << std::endl;
    }
    std::cout << cpt;
}

void validFichier(){
    
}

int main(){
    nomFichAuClavier();
    return 0;
}