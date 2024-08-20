class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int kq = 0, n = piles.size();
        vector<vector<int>> db (n, vector<int> (n + 1, 0));
        vector<int> shuffer_sum (n, 0);
        shuffer_sum[n - 1] = piles[n - 1];

        for(int i = n - 2; i >= 0; i--) {
            shuffer_sum[i] += shuffer_sum[i + 1] + piles[i];
        }

        for(int i = n - 1; i >= 0; i--) {
            for(int j = 1; j <= n; j++) {
                if(i + 2 * j >= n) {
                    db[i][j] = shuffer_sum[i];
                }
                else {
                    for(int m = 1; m <= j * 2; m++) {
                        db[i][j] = max(db[i][j], shuffer_sum[i] -  db[min(i + m, n - 1)][max(m, j)]);
                    }
                }
            }
        }

        return db[0][1];
    }
};