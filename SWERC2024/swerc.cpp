#include <iostream>
#include <vector>
#include <map>
using namespace std;

void recherche_feuille(vector<int>& feuille, vector<vector<int>> adjacence, int indice, vector<bool>& visiter){
    if (!visiter[indice]){
        visiter[indice] = true;
        if(adjacence[indice].size() == 1){
            feuille.push_back(indice);
        }
        else{
            for(int i : adjacence[indice]){
                recherche_feuille(feuille, adjacence, i, visiter);
            }
        }
    }
}

void mettre_poids(int feuille, int noeud, vector<map<int, int>>& poids_f, vector<bool>& visiter, int poids, vector<int> feuilles, vector<vector<int>> adjacence){
    if (!visiter[noeud]){
        visiter[noeud] = true;
        if(adjacence[noeud].size() == 1 && noeud != feuille){
            poids_f[feuille][noeud] = poids;
        }
        else{
            for(int i : adjacence[noeud]){
                mettre_poids(feuille, i, poids_f, visiter, poids + 1, feuilles, adjacence);
            }
        }
    }
}

int main(){
    int N,P;
    cin >> N;
    cin >> P;
    vector<vector<int>> adjacence(N); 
    for(int i = 0; i < N-1;i++){
        int x,y;
        cin >> x;
        cin >> y;
        adjacence[x].push_back(y);
        adjacence[y].push_back(x);
    }
    vector<int> feuille;
    vector<bool> visiter(N);
    
    recherche_feuille(feuille, adjacence, 0, visiter);
    vector<map<int, int>> poids_f(N); // trop grand mais plus simple
    
    for(int i : feuille){
        fill(visiter.begin(), visiter.end(), false);
        mettre_poids(i,i, poids_f, visiter, 1, feuille, adjacence);
    }
    int max = 0;
    for(int i : feuille){
        for(int j : feuille){
            if(poids_f[i][j]>max){
                max = poids_f[i][j];
            }
        }
    }
    cout << max;
   return 0;
}