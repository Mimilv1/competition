#include <iostream>

using namespace std;

int main()

{
    string c;
    cin >> c;
    bool trouve=false;
    string result;
    string compare;
    char val = c[0];
    int longueur = c.length();
    for (int parcour_1 = 1; parcour_1< longueur/2 + 1; parcour_1++){
        int debut;
        if(val==c[parcour_1]){
            for(int parcour_2 = 0;parcour_2<parcour_1;parcour_2++){
                if(c[parcour_2]!=c[parcour_1+parcour_2]){
                    break;
                }
                if(parcour_2==parcour_1-1){
                    trouve=true;
                    result=c.substr(parcour_1,longueur-parcour_1);
                    compare=c.substr(0,parcour_1);
                    break;
                }
            }
            if(trouve){
                break;
            }
        }
    }
    if(trouve && compare != result ){
        cout << "YES" << endl;
        cout << result << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}