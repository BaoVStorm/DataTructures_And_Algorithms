class Solution {
public:
    long long maxPoints(vector<vector<int>>& a) {
        const int m = a.size(), n = a[0].size();

        vector<vector<long>> L(m, vector<long>(n)), R(m, vector<long>(n)), S(m, vector<long>(n));
        long Result = a[0][0];

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0)
                    S[i][j] = a[i][j];
                else
                    S[i][j] = a[i][j] + max(L[i-1][j], R[i-1][j]);

                Result = max(Result, S[i][j]);
            }
            
            int Max_, index; 

            // Left 
            Max_ = S[i][0];
            L[i][0] = S[i][0];
            index = 0;
            for(int j = 1; j < n; j++) {
                if(Max_ - (j - index) < S[i][j]) {
                    Max_ = L[i][j] = S[i][j];
                    index = j; 
                }
                else 
                    L[i][j] = Max_ - (j - index);
            }

            // Right array
            Max_ = R[i][n-1] = S[i][n-1];
            index = n-1; 
            for(int j = n-2; j >= 0; j--) {
                if(Max_ - (index - j) < S[i][j]) {
                    Max_ = R[i][j] = S[i][j];
                    index = j; 
                }
                else 
                    R[i][j] = Max_ - (index - j);
            }
        } 

        return Result;
    }
};
