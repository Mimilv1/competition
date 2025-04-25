#include <iostream>
#include <set>

using namespace std; //2009D

int main(){
    int t, n, x, y, nombre_couples;
    int64_t total_tri;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n;
        int tab[2*n];
        set<int> points_bas;
        set<int> points_haut;

        for (int j = 0; j < n; j++){
            cin >> x;
            cin >> y;
            tab[2*j] = x;
            tab[2*j + 1] = y;
            if (y==1) points_haut.insert(x);
            else points_bas.insert(x); // pour eviter le cas egal a 0 et la marge pour les tests
        }

        nombre_couples = 0;

        for (int j = 0; j < n; j++){
            if(tab[2*j + 1] == 0 && points_haut.count(tab[2*j]) == 1 ) nombre_couples++;
        }
        total_tri = 0;

        for (int j = 0; j < n; j++){
            int y,x;
            y = tab[2*j + 1];
            x = tab[2*j];
            if(y == 0){ // si le point est en bas
                total_tri += nombre_couples - points_haut.count(x);
                if(points_haut.count(x + 1) == 1 && points_haut.count(x - 1) == 1){
                    total_tri++;
                }
            }
            else{
                total_tri += nombre_couples - points_bas.count(x);
                if(points_bas.count(x + 1) == 1 && points_bas.count(x - 1) == 1){
                    total_tri++;
                }
            }
        }
        cout << total_tri << endl;
    }
    return 0;
}