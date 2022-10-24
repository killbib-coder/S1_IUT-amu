#include <iostream>
#include <vector>
#include <fstream>
#include <cctype>
#include "nsUtil.cxx"

using namespace std;
using namespace nsUtil;

void afficheTableau(const vector<string> & Tab){
    for (int i = 0; i < Tab.size(); ++i) {
        cout << Tab[i] << endl;
    }
}
string ToUpper(string & chaine){
    string alphaMinu = "abcdefghijklmnopkrstuvwxyz";
    string alphaMaj = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (size_t i = 0; i < chaine.size(); ++i) {
        for (size_t j = 0; j < alphaMinu.size(); ++j) {
            if(chaine[i]==alphaMinu[j]){
                chaine[i] = alphaMaj[j];
            }
        }
    }
    return chaine;
}
string ToLower(string & chaine){
    string alphaMinu = "abcdefghijklmnopkrstuvwxyz";
    string alphaMaj = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (size_t i = 0; i < chaine.size(); ++i) {
        for (size_t j = 0; j < alphaMaj.size(); ++j) {
            if(chaine[i]==alphaMaj[j]){
                chaine[i] = alphaMinu[j];
            }
        }
    }
    return chaine;
}
void Exo2(){
    while (true){
        cout << "Saisir chaine de caracteres : ";
        string answer, result;
        cin >> answer;
        if(answer=="fin") break;
        result = ToLower(answer);
        cout << result << endl;
    }
}
vector<string> min_tout(vector<string> & VString){
    for (size_t i = 0; i < VString.size(); ++i) {
        VString[i] = ToLower(VString[i]);
    }
    return VString;
}
vector<string> min_14(vector<string> & VString, const unsigned & LineNumber){
    VString[LineNumber] = ToLower(VString[LineNumber]);
    return VString;
}
vector<string> min_tout_upper(vector<string> & VString){
    for (size_t i = 0; i < VString.size(); ++i) {
        VString[i] = ToUpper(VString[i]);
    }
    return VString;
}
vector<string> min_14_upper(vector<string> & VString, const unsigned & LineNumber){
    VString[LineNumber] = ToUpper(VString[LineNumber]);
    return VString;
}
vector<string> Swap(vector<string> & VString, const unsigned & PosBeg, const unsigned & PosEnd){
    string temp;
    temp = VString[PosBeg];
    VString[PosBeg] = VString[PosEnd];
    VString[PosEnd] = temp;
    return VString;
}
vector<string> Delete(vector<string> & VString, const unsigned PosBeg){
    for (int i = PosBeg; i < VString.size()-1; ++i) {
        VString[i]=VString[i+1];
    }
    VString.resize(VString.size()-1);
    return VString;
}
vector<string> Insert(vector<string> & VString, const unsigned & PosBeg, const string & Line){
    VString.resize(VString.size()+1);
    for (int i = PosBeg; i < VString.size()-1; ++i) {
        VString[i+1]=VString[i];
    }
}


void choix(vector<string> & TabFile){
    vector<string> result;
    string answer, deuxiemeChoix;
    cout << "Entrer le nom de fonction : ";
    cin >> answer;
    if (answer=="min_tout") {
        result = min_tout(TabFile);
        afficheTableau(result);
    } else if (answer=="min_14") {
        unsigned Number;
        cout << "Saisir la ligne que vous voulez lower : ";
        cin >> Number;
        result = min_14(TabFile, Number);
        afficheTableau(result);
    } else if (answer=="maj") {
        cin >> deuxiemeChoix;
        if (deuxiemeChoix=="tout"){
            result = min_tout_upper(TabFile);
            afficheTableau(result);
        } else {
            unsigned long Number = stoul(deuxiemeChoix);
            result = min_14_upper(TabFile,Number);
            afficheTableau(result);
        }
    } else if (answer=="swap") {
        unsigned PosBeg, PosEnd;
        cin >> PosBeg;
        cin >> PosEnd;
        result = Swap(TabFile,PosBeg,PosEnd);
        afficheTableau(result);
    } else if (answer=="delete") {
        unsigned PosBeg;
        cin >> PosBeg;
        result = Delete(TabFile,PosBeg);
        afficheTableau(result);
    }
}

int main(int argc, char *argv[])
{
    vector<string> TabFile = FileToVectString("/home/user/CLionProjects/TP6/LaFontaine.txt");
    choix(TabFile);
    return 0;
}
