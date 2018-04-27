#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            vector<int> hchk(9), vchk(9), bchk(9);
            for(int i = 0 ; i < 9 ; i++){
                for(int j = 0 ; j < 9 ; j++){
                    if(board[i][j] == '.') continue;
                    int c = 1 << (board[i][j] - '0');
                    if((hchk[i] & c) || (vchk[j] & c) || (bchk[(i / 3) * 3 + (j / 3)] & c))
                        return false;
                    hchk[i] |= c;
                    vchk[j] |= c;
                    bchk[(i / 3) * 3 + (j / 3)] |= c;
                }
            }
            return true;
        }
};

int main(){
    return 0;
}
