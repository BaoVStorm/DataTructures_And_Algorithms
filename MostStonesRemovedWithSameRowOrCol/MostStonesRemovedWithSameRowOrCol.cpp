class Solution {
public:
    void processRow(int& pos, vector<int>& done, vector<vector<int>>& row, vector<vector<int>>& col, vector<vector<int>>& stones) {
        done[pos] = 1;

        int r = stones[pos][0];

        for(auto i : row[r]) {
            if(done[i] == 0) {
                processCol(i, done, row, col, stones);
            }
        }
    }

    void processCol(int& pos, vector<int>& done, vector<vector<int>>& row, vector<vector<int>>& col, vector<vector<int>>& stones) {
        done[pos] = 1;

        int c = stones[pos][1];
        
        for(auto i : col[c]) {
            if(done[i] == 0) {
                processRow(i, done, row, col, stones);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int maxR = 0, maxC = 0;

        for(int i = 0; i < stones.size(); i++)
        {
            int r = stones[i][0], c = stones[i][1];

            maxR = max(maxR, r);
            maxC = max(maxC, c);
        }
        vector<vector<int>> row(maxR + 1), col(maxC + 1);
        vector<int> done(stones.size(), 0);
        int kq = 0;

        for(int i = 0; i < stones.size(); i++) {
            int r = stones[i][0], c = stones[i][1];

            row[r].push_back(i);
            col[c].push_back(i);
        }
        
        for(int i = 0; i < stones.size(); i++) {
            if(done[i] == 0) {
                kq++;
                processRow(i, done, row, col, stones);
                processCol(i, done, row, col, stones);
            }
        }

        return stones.size() - kq;
    }
};