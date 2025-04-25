#include <iostream>
#include <vector>

using namespace std;
bool recherche(int cible, vector<int> tab){ // Rendez-vous de Marian et Robin faire Djikstra de sommet initial a cheval puis de cheval a
    for(int i = 0; i<tab.size();i++){
        if(cible == tab[i]){
            return true;
        }
    }
    return false;
}


int main()
{
    int nb_test;
    cin >> nb_test;
    for(int i = 0; i<nb_test; i++){
        int n, m, h;
        cin >>n >>m >>h;
        vector<bool> visiter(n);;
        vector<int> chevaux(h);
        for(int j=0;j<h;j++){
            cin >> chevaux[j];
        }
        vector<int> lien(3*m);
        vector<int> poids_actuelle(n);
        for(int j=0;j<m; j++){
            cin >> lien[3*j] >> lien[3*j+1] >> lien[3*j+2];
        }
        visite(lien, visiter, poids_actuelle, false, chevaux, 1);
    } 
    return 0;
}

void visite(vector<int> arrete, vector<bool>& visiter, vector<int>& poids_actuelle, bool cheval, vector<int> chevaux, int sommet){
    if(!cheval && recherche(sommet, chevaux)){
        cheval = true;
    }
    vector<int> adjacent;
}