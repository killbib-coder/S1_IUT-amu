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

void triSelection (vector<int> && tab){
    int temp = tab[0];
    unsigned min;
    for (unsigned i = 0; i < tab.size()-1; i++)
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

