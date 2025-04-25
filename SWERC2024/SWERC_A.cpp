// SWERC A 2023 Emilien lambin 
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class carte{
    public :
    int valeur;
    char lettre;    
    int lettre_val;
    void mise(){
        switch (lettre)
        {
        case 'S':
            lettre_val = 1;
            break;
        case 'W':
            lettre_val = 2;
            break;
        case 'E':
            lettre_val = 3;
            break;
        case 'R':
            lettre_val = 4;
            break;
        case 'C':
            lettre_val = 5;
            break;
        
        default:
            cout << "ERRERU CARTE" << endl;
            break;
        }
    }
};

bool compare(carte A, carte B){
    if(A.lettre_val != B.lettre_val){
        return A.lettre_val < B.lettre_val;
    }
    else{
        return A.valeur < B.valeur;
    }
}

int recherche(carte A, vector<carte> B, int N){
    int indice;
    for(int i = 0; i < N; i++){
        if((B[i].valeur == A.valeur && B[i].lettre_val == A.lettre_val)){
            indice = i;
            break;
        }
    }
    return indice;
}

int main(){
    int N;
    cin >> N;
    vector<carte> entree = vector<carte>(N);
    vector<carte> sortie = vector<carte>(N);
    for(int i = 0; i<N; i++){
        string entre;
        cin >> entre;
        carte ma_carte;
        ma_carte.lettre = entre[0];
        ma_carte.valeur = entre[1];
        ma_carte.mise();
        entree[i] = ma_carte;
    }
    sortie = entree;
    sort(sortie.begin(),sortie.end(),compare);
    int nb_op = 0;
    int indice = 0;
    while (indice != N){
        if(entree[indice].valeur == sortie[indice].valeur && entree[indice].lettre_val == sortie[indice].lettre_val){
            indice += 1;
        }
        else{
            int emplacement;
            emplacement = recherche(entree[indice], sortie, N);
            nb_op += 1;
            carte val = entree[indice];
            entree.erase(entree.begin() + indice);
            entree.insert(entree.begin() + emplacement, val);
        }
    }
    cout << nb_op;
    return 0;
}