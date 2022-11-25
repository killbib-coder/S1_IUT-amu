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
    int min =tab[0],max=tab[0],pointeur=0;
    for (size_t i = 0; i < tab.size(); i++)
    {
        if(tab[i]<min) min = tab[i];
        else if (tab[i]>max) max = tab[i];
    }
    vector<int> tab2(max-min,0);
    for (size_t i = 0; i < tab.size(); i++) ++tab2[tab[i]-min];
    for (size_t i = 0; i <= tab2.size(); i++)
    {
        for (size_t j = 0; j < tab2[i]; j++)
        {
            tab[pointeur]=i+min;
            ++pointeur;
        }
    }
}

int main(){
    vector<int> tabTest{1,4,5,2,7,6};
    triParComptage(tabTest); 
    cout << tabTest[0] << tabTest[1] << tabTest[2]<< endl;
    cout << estBienTrie(tabTest);
}