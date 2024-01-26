class Solution {
public:
int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const int MOD = 1e9 + 7;
        vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>>(m, vector<int>(n, 0)));
        vector<int> dirs = {0, 1, 0, -1, 0};

        for (int k = 1; k <= maxMove; ++k) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int d = 0; d < 4; ++d) {
                        int ni = i + dirs[d];
                        int nj = j + dirs[d + 1];
                        if (ni < 0 || ni >= m || nj < 0 || nj >= n) {
                            dp[k][i][j] += 1;
                        } else {
                            dp[k][i][j] = (dp[k][i][j] + dp[k - 1][ni][nj]) % MOD;
                        }
                    }
                }
            }
        }

        return dp[maxMove][startRow][startColumn];        
    }
};