#include <iostream>
using namespace std;
#include <vector>

bool estBienTrie(const vector<int> & tab){
    unsigned i = 0;
    while (i < tab.size())
    {
        if (tab[i-1] > tab[i]) return false;
        ++i;        
    }
    return true;    
}

void triSelection (vector<int> & tab){
    int temp = tab[0];
    unsigned min;
    for (size_t i = 0; i < tab.size()-1; i++)
    {
        min=i;
        for (unsigned j = 0; i+1 < tab.size(); i++)
        {
            min=j;
        }
        if (min != i)
        {
            temp=tab[i];
            tab[i]=tab[min];
            tab[min]=temp;
        }
    }
}

void triBulles (vector<int> & tab){
    bool permut = true;
    unsigned passage = 0;
    int temp;
    while (permut==true)
    {
        permut=false;
        for (unsigned i = 0; i < tab.size()-passage; i++)
        {
            if (tab[i] > tab[i+1])
            {
                temp=tab[i];
                tab[i]=tab[i+1];
                tab[i+1]=temp;
            }
        }
        ++passage;
    }
}

void triInsertion (vector<int> & tab){
    int temp;
    unsigned j;
    for (size_t i = 0; i < tab.size(); i++)
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

