#include <iostream>
#include <stdio.h>

using namespace std;
int main(){
    long long int n,q;
    cin >> n;
    string chaine;
    cin >> chaine;
    long long int np, nm;
    for(int i = 0; i<chaine.length(); i++){
        np += (long long int)(chaine[i] == '+');
        nm += (long long int)(chaine[i] == '-');
    }
    cin >>q;
    for(int i = 0;i <q;i++){
        long int a,b;
        cin >> a;
        cin >> b;
        if(a==b){
            if(np==nm){
                cout << "YES"<< endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else{
            if(a<b){
            long long int temp = b;
            b = a;
            a = temp;
        }
        long long int haut = a*(np-nm);
        long long int bas = (a-b);

        if(haut % bas == 0){
            if(np>=haut/bas && haut/bas>=-nm){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else{
            cout << "NO"<< endl;
        }
        }
    }
    return 0;
}