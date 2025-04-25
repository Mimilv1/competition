#include <iostream>

using namespace std;

int main(){
    int val1;
    int val2;
    cin >> val1;
    cin >> val2;
    int somme = val1 +val2;
    switch (somme)
    {
    case 3:
        cout << 3 << endl;
        break;
    
    case 4:
        cout << 2 << endl;
        break;
    
    case 5:
        cout << 1 << endl;
    default:
        break;
    }
    return 0;
}