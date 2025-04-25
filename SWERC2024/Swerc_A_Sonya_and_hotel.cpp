#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long int n, d;
    cin >>n;
    cin >> d;
    vector<int> hotel;
    for(int i = 0; i<n;i++){
        int v;
        cin >> v;
        hotel.push_back(v);
    }
    sort(hotel.begin(), hotel.end());
    int nbh = 2;
    for(int i = 0; i-1<n; i++){
        if(hotel[i+1] - hotel[i] >= 2*d+1){
            nbh += 2;
        }
        else if(hotel[i+1] - hotel[i] == 2*d){
            nbh +=1;
        }
    }
    cout << nbh;
    return 0;
}