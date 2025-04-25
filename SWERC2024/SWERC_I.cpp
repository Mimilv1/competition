// SWERC I 2023 Emilien lambin 
#include <stdio.h>
#include<iostream>
#include <vector>
using namespace std;

int main(){
    int M, N;
    cin >> M;
    cin >> N;
    int ScoreA = 0;
    int ScoreB = 0;
    int val = 0;
    for(int i = 0; i<M; i++){
        cin >> val;
        ScoreA += val;
    }
    for(int i = 0; i<N; i++){
        ScoreB += val;
        cin >>val;
        ScoreB += val;
    }
    if(ScoreA == ScoreB){
        cout << "TIED";
    }
    else if(ScoreA>ScoreB){
        cout << "ALICE";
    }
    else{
        cout << "BOB";
    }
    return 0;
}