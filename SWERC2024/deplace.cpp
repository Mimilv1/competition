//SWERC 2023 pb K, Emilien Lambin

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    vector<int> choix1;
    vector<int> choix2;

    vector<int> result1;
    vector<int> result2;
    cin >> N;
    vector<int> liste = vector<int>(N);
    for(int i = 0; i< N/2; i++){
        liste[i] = i + 1;
        int val;
        cin >> val;
        choix1.push_back(val);
    }

    for(int i = 0; i< N/2; i++){
        liste[i+N/2] = i + 1 + N/2 ;
        int val;
        cin >> val;
        choix2.push_back(val);
    }

    for(int i = 0; i<N; i++){
        if (i%2 == 0){
            result1.push_back(liste[choix1[i/2] - 1]);
            liste.erase(liste.begin() + choix1[i/2] - 1);
        }
        else{
            result2.push_back(liste[choix2[i/2] - 1]);
            liste.erase(liste.begin() + choix2[i/2] - 1);
        }
    }

    for(int i : result1){
        cout << i << " ";
    }
    cout << endl;
    for(int i : result2){
        cout << i << " ";
    }

    return 0;
}