#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> w(n);
    vector<double> p(n);
    int somme = 0;
    for(int i =0; i<n; i++){
        int val;
        scanf("%d", &val);
        w[i] = val;
        somme += val;
    }
    for(int i = 0; i<n; i++){
        double val;
        scanf("%lf", &val);
        p[i] = val;
    }
    vector<vector<double>> tab(n,vector<double>(somme,0));
    tab[0][0]=1-p[0];
    tab[0][w[0]]=p[0]*w[0];
    for(int i = 1; i < n; i++){
        for(int j = 0; j < somme; j++){
            tab[i][j] = tab[i-1][j-w[i]]*p[i] + tab[i-1][j]*(1-p[i]);
        }
    }
    double resultat = 0;
    for(int i = somme/2; i<somme;i++){
        resultat += tab[n][i];
    }
    cout << resultat;
    return 0;
}