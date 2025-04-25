#include <iostream>

using namespace std;

int min(int a, int b){
    if(a>b){
        return b;  
    } 
    return a;
}

int max(int a, int b){
    if(a>b){
        return a;
    } 
    return b;
}

int main(){
    int nbtest;
    cin >> nbtest;
    for (int i = 0; i < nbtest; i++)
    {
        int a,b;
        cin >> a >> b;
        int c = min(a,b);
        int maximum = max(a,b);
        cout << maximum - c << endl;
        
    }
    
    return 0 ;
}