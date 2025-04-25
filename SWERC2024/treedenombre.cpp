#include <vector>
class Solution {
public:
    int numTrees(int n) {
        vector<int> tab = new int[20];
        tab[0]=1;
        for(int i = 1; i<20; i++){
            int val = 0;
            for(int j =0;j<i;j++){
                val += tab[i-j] * tab[j];
            }
        tab[i] = val;
        }
        cout << tab[n];
    }
};