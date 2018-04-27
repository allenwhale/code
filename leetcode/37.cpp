#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        array<int, 9> hchk, vchk, bchk;
        bool dfs(int idx, vector<vector<char>> &board){
            if(idx == 81) return true;
            int i = idx / 9, j = idx % 9, b = (i / 3) * 3 + (j / 3);
            if(board[i][j] != '.') return dfs(idx + 1, board);
            for(int k = 1 ; k <= 9 ; k++){
                int kk = 1 << k;
                if((hchk[i] & kk) || (vchk[j] & kk) || (bchk[b] & kk))continue;
                hchk[i] |= kk, vchk[j] |= kk, bchk[b] |= kk;
                board[i][j] = k + '0';
                if(dfs(idx + 1, board))return true;
                board[i][j] = '.';
                hchk[i] ^= kk, vchk[j] ^= kk, bchk[b] ^= kk;
            }
            return false;
        }
        void solveSudoku(vector<vector<char>>& board) {
            for(int i = 0 ; i < 9 ; i++){
                for(int j = 0 ; j < 9 ; j++){
                    if(board[i][j] != '.'){
                        int c = 1 << (board[i][j] - '0');
                        hchk[i] |= c, vchk[j] |= c, bchk[(i / 3) * 3 + (j / 3)] |= c;
                    }
                }
            }
            dfs(0, board);
        }
};
int main(){
    return 0;
}
