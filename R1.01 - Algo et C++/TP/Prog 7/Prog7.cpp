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
        if (ifs.eof()) break;
        std::cout << str << std::endl;
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
        destination << ++cpt << ' ' << str << std::endl;
    }
    std::cout << cpt << std::endl;
}
 
void validFichier(){
    string sourcefile, destfile;
 
    /*int essai=0;
    while(true){
        std::cout << "Saisir le fichier source : ";
        getline(cin, sourcefile);
        ifstream source(sourcefile);
        if(!source.is_open()){
            std::cout << "Fichier introuvable" << std::endl;
            ++essai;
            if(essai==3){
                std::cout << "3 echecs d'ouverture de fichier en lecture";
                exit(2);
            }
        }
        else{
            break;
        }
    }
    std::cout << "bien joué" << std::endl;*/
 
    ifstream source;
    unsigned i(0);
    for (; i < 3; ++i) {
        std::cout << "Saisir le nom du fichier source : ";
        getline(cin,sourcefile);
        source.open(sourcefile);
        if(source) break;
    }
    if (i==3){
        std::cout << "3 echecs d'ouverture de fichier en lecture" << std::endl;
        exit(2);
    }
 
    ofstream destination;
    i=0;
    for (; i < 3; ++i) {
        std::cout << "Saisir le nom du fichier de destination : ";
        getline(cin,destfile);
        destination.open(destfile);
        if(destination) break;
    }
    if (i==3){
        std::cout << "3 echecs d'ouverture de fichier en ecriture" << std::endl;
        exit(2);
    }
 
    string str;
    long unsigned cpt = 0;
    while (!source.eof()){
        getline(source,str);
        destination << ++cpt << ' ' << str << std::endl;
    }
    std::cout << cpt << std::endl;
}
 
void fonctionGet(){
    ifstream source("LaFontaine.txt");
//    while(true){
//        char c;
//        c=source.get();
//        if(source.eof()) break;
//        cout << c;
//    }
 
    //mot par mot
//    while (true) {
//        char c;
//        source >> c;
//        if (source.eof()) break;
//        cout << c;
//    }
}
 
int main(){
    fonctionGet();
    return 0;
}