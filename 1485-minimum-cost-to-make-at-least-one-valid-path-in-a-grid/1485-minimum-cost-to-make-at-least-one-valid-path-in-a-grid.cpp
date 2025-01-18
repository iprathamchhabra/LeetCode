class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        cost[0][0] = 0;
        pq.push({0, 0, 0});
        
        while (!pq.empty()) {
            auto [curr_cost, x, y] = pq.top();
            pq.pop();
            
            if (x == m - 1 && y == n - 1) {
                return curr_cost;
            }
            
            if (curr_cost > cost[x][y]) {
                continue;
            }
            
            vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for (int direction = 0; direction < 4; ++direction) {
                int nx = x + directions[direction].first;
                int ny = y + directions[direction].second;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int next_cost = curr_cost + (grid[x][y] == direction + 1 ? 0 : 1);
                    if (next_cost < cost[nx][ny]) {
                        cost[nx][ny] = next_cost;
                        pq.push({next_cost, nx, ny});
                    }
                }
            }
        }
        
        return -1;
    }
};