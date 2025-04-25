//SWERC 2023 G Emilien lambin
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int max_index(vector<double> t){
    int indice_max = 0;
    double max = t[0];
    int taille = t.size();
    for(int i = 0; i<taille; i++){
        if(t[i]>max){
            indice_max = i;
            max = t[i];
        }
    }
    return indice_max;
}

int main(){
    int N,M;
    cin>> N;
    cin >> M;
    vector<vector<double>> tab_score(M, vector<double>(N)) ;
    vector<double> dishes(N*2);
    vector<double> person(M*2);
    for(int i = 0; i<N; i++){
        cin>>dishes[2*i];
        cin>>dishes[2*i+1];
    }
    double person_t, person_d;
    for(int i = 0; i<M; i++){
        cin>>person_d;
        cin>>person_t;
        for(int j = 0; j<N; j++){
            tab_score[i][j] = (person_d * dishes[2*j] + person_t * dishes[2*j+1]) / (person_d + person_t);
        }
    }
    for(int i = 0; i<M; i++){
        cout << max_index(tab_score[i]) + 1 << endl;
    }
    return 0;
}