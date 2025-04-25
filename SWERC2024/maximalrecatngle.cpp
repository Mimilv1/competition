#include <iostream>
#include <vector>


class Solution {
public:
    int verif(int i, int j, int nb_l,int nb_c, vector<vector<char>>& matrice){
        int i1, i2, j1, j2;
        int resultat_totale = 1;
        int resultat_droite = 1;
        int resultat_bas = 1;
        i1 = i;
        i2 = i;
        j1 = j;
        j2 = j;
        bool droite = true;
        bool bas = true;
        while(droite || bas){
            if(droite){
                int reserve=0;
                if(j1 < nb_c - 1){
                    for(int k = i; k<i1+1; k++){
                        reserve++;
                        if(matrice[k][j1+1]==0){
                            droite = false;
                            break;
                        }
                    }
                    if(droite){
                        resultat_droite += reserve;
                        j1++;
                    }
                }
            }
            else droite = false;
            if(bas){
                int reserve=0;
                if(i2 < nb_l - 1){
                    for(int k = i; k<j2+1; k++){
                        reserve++;
                        if(matrice[i2+1][k]==0){
                            bas = false;
                            break;
                        }
                    }
                    if(bas){
                        resultat_bas += reserve;
                        i2++;
                    }
                }
            }
            else bas = false;
            
            if(bas && droite){
                if(matrice[i2][j1]==1){
                    resultat_totale = (j1-j+1)*(i2-i+1) ;
                }
            }
        }
        return 0;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int nb_rows, nb_cols;
        nb_rows = matrix.size();
        nb_cols = matrix[0].size();
        int maxi = 0;
        for(int ligne=0; ligne < nb_rows; ligne ++){
            for(int colonnes = 0; colonnes < nb_cols; nb_cols++){
                if(matrix[ligne][colonnes]){
                    int val = verif(ligne, colonnes, nb_rows, nb_cols, matrix);
                    maxi = max(val, maxi);
                }
            }
        }
        return maxi;
    }
};