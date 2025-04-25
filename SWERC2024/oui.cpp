#include <iostream>
#include <string>
#include <vector>
using namespace std;

int calcul(string ligne){
    for(int i = 0; i<ligne.length();i++){
        if(ligne[i]=='#'){
            return i+1;
        }
    }
    return 0;
}

int main(){
    int nb_test;
    cin >> nb_test;
    for(int i = 0; i<nb_test; i++){
        int nb_linges;
        cin >> nb_linges;
        vector<string> entree(nb_linges);
        for(int j = 0; j< nb_linges; j++){
            cin >> entree[j];
        }
        for(int j = nb_linges-1; j >=0; j--){
            cout << calcul(entree[j]) << " ";
        }
        cout << endl;
    }
    return 0;
}