/**
 *
 * @file    nsUtil.cxx
 *
 * @author  A. Casali
 *
 * @date    10/11/2014
 *
 * @brief   3 fonctions pour utiliser des flux
 *
 **/

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

#include "nsUtil.h"

using namespace std;

/*
 * fonction permettant de charger un fichier texte dans un vecteur de string
 * 1 ligne du fichier texte correspond à une case du vecteur
 */

vector <string> nsUtil::FileToVectString (const string & FileName)
{

    ifstream ifs (FileName);
    vector <string> VString;
    string Line;

    for ( ;getline (ifs, Line); )
        VString.push_back (Line);

    return VString;
}// FileToVectString ()

/*
 * fonction permettant d'afficher à l'écran le contenu d'un vecteur de string
 */

void nsUtil::EditVString (const vector <string> & VString)
{
    for (const string & str : VString)
        cout << str << endl;
    cout << endl;
}// EditVString ()

/*
 * fonction permettant de mettre le contenu d'un vecteur dans un fichier texte
 * a raison d'un element par ligne
 */

void nsUtil::VectStringToFile (const vector <string> & VString, const string & FileName)
{
    ofstream ofs (FileName);
    for (const string & s : VString)
        ofs << s << endl;
}// VectStringToFile()

void nsUtil::EditVStringV2(const std::vector<string> &VString, const char & Car)
{
    for (const string & str : VString)
        cout << setw (4) << str.size () << " : " << str << Car << endl;
    cout << endl;
}

void nsUtil::EditVStringV3(const std::vector<string> &VString)
{
    for (unsigned i(0); i < VString.size(); ++i)
        cout << setw (3) << i << " : " << VString[i] << endl;
    cout << endl;
}
