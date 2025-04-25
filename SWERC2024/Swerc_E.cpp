#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct tupple
{
    int p;
    int q;
};


tupple distance(int pos_1, int h1, int pos_1_1 , int h_1_1 , int pos_2, int h2, int pos_3, int h3){
    int a,b;
    tupple result;
    if(h3 > h1){
    a = h3-h2;
    b = -a*pos_2 + pos_2;// vérif ça
    result.p = h1-b;
    result.q = a;
    int div = __gcd(result.p, result.q);
    result.p = result.p / div;
    result.q = result.q / div;
    }
    else if(h1>h3){
        a = h_1_1-h1;
        b = -a*pos_1 + pos_1; // vérif ça
        result.p = h3-b;
        result.q = a;
        int div = __gcd(result.p, result.q);
        result.p = result.p / div;
        result.q = result.q / div;
    }
    else{
        result.p = pos_3-pos_1;
        result.q = 1;
    }
    return result;
}

int main(){
    int N;
    cin >> N;
    vector<int> sommet(N);
    vector<int> descente;
    int precedant = -1;
    for(int i=0; i< N; i++){
        cin >> sommet[i];
        if(precedant>sommet[i]){
            descente.push_back(i-1);
        }
        precedant = sommet[i];
    }




    return 0;
}