class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;

        int m = heightMap.size(), n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    minHeap.push({heightMap[i][j], i * n + j});
                    visited[i][j] = true;
                }
            }
        }

        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int waterTrapped = 0;
        int maxHeight = 0;

        while (!minHeap.empty()) {
            auto [height, idx] = minHeap.top();
            minHeap.pop();
            maxHeight = max(maxHeight, height);
            int x = idx / n, y = idx % n;

            for (auto& dir : directions) {
                int newX = x + dir[0], newY = y + dir[1];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && !visited[newX][newY]) {
                    visited[newX][newY] = true;
                    waterTrapped += max(0, maxHeight - heightMap[newX][newY]);
                    minHeap.push({heightMap[newX][newY], newX * n + newY});
                }
            }
        }

        return waterTrapped;
    }
};
