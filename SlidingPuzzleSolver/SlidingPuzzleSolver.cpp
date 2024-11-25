class Solution {
public:
    int res = 1e6;
    string solve = "";

    void process(vector<vector<int>> board, int count, unordered_map <string, int>& m) {
        string curString = "000000";
        int x, y;
        for(int i = 0; i < board.size(); i ++)
        for(int j = 0; j < board[0].size();j ++) {
            if(board[i][j] == 0) {
                x = i;
                y = j;
            }

            curString[i * board[0].size() + j] = char(board[i][j] + '0'); 
        }

        if(curString == solve) {
            res = min(res, count);
        }

        if(m.find(curString) != m.end() && m[curString] <= count)
            return;
        m[curString] = count;

        if(x < board.size() - 1) {
            swap(board[x][y], board[x + 1][y]);
            process(board, count + 1, m);
            swap(board[x][y], board[x + 1][y]);
        }
        if(x > 0) {
            swap(board[x][y], board[x - 1][y]);
            process(board, count + 1, m);
            swap(board[x][y], board[x - 1][y]);
        }
        if(y > 0) {
            swap(board[x][y - 1], board[x][y]);
            process(board, count + 1, m);
            swap(board[x][y - 1], board[x][y]);
        }
        if(y < board[0].size() - 1) {
            swap(board[x][y + 1], board[x][y]);
            process(board, count + 1, m);
            swap(board[x][y + 1], board[x][y]);
        }
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_map <string, int> m;
        solve = "123450";

        process(board, 0, m);

        return (res == 1e6 ? - 1: res);
    }
};