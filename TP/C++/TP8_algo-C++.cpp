#include <iostream>
using namespace std;
#include <vector>

bool estBienTrie(vector<int> & tab){
    unsigned i = 1;
    while (i < tab.size())
    {
        if (tab[i-1] > tab[i]) return false;
        ++i;        
    }
    return true;    
}


void triSelection (vector<int> & tab){
    int temp;
    temp = tab[0];
    unsigned min;
    for (size_t i = 0; i < tab.size()-1; i++)
    {
        min=i;
        for (unsigned j = i+1; j < tab.size(); j++)
        {
            if(tab[j] < tab[min]) min=j;
        }
        if (min != i)
        {
            temp=tab[i];
            tab[i]=tab[min];
            tab[min]=temp;
        }
    }
}

void triABulle(vector<int> & tab ){
    unsigned temp;
    for (unsigned i = 0; i<tab.size() ; i++ ){
        for (unsigned j = 0 ; j<tab.size()-1 ; j++){
            if (tab[j] > tab[j+1]){
                temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
            }
        }
    }
}

void triInsertion (vector<int> & tab){
    int temp;
    unsigned j;
    for (size_t i = 1; i < tab.size(); i++)
    {
        temp = tab[i];
        j=i;
        while (j>0 and tab[j-1] > temp)
        {
            tab[j]=tab[j-1];
            j=j-1;
        }
        tab[j]=temp;
    }
}

void triParComptage (vector<int> & tab){
    unsigned borneSuperieur =0;
    vector<int> tabTrie(tab.size());
    for (size_t i = 0; i < tab.size(); i++)
    {
        if (tab[i] > borneSuperieur) borneSuperieur=tab[i];    
    }
    for (size_t i = 0; i < borneSuperieur; i++) tabTrie[i]=0;
    for (size_t i = 0; i < tab.size(); i++)tabTrie[i]=tabTrie[i]+1;
    unsigned cpt = 0;
    for (size_t i = 0; i < tab.size(); i++)
    {
        for (size_t j = 0; j < tabTrie[i]; j++)
        {
            tab[cpt]=i;
            ++cpt;
        }        
    }
}

int main(){
    vector<int> tabTest{1,4,5,2,7,6};
    triABulle(tabTest); 
    cout << tabTest[0] << tabTest[1] << tabTest[2]<< endl;
    cout << estBienTrie(tabTest);
}