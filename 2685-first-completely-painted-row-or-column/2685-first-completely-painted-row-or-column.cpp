class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    int m = mat.size(); 
    int n = mat[0].size(); 
    
    unordered_map<int, pair<int, int>> positionMap;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            positionMap[mat[i][j]] = {i, j};
        }
    }
    
    vector<int> rowPaintedCount(m, 0);
    vector<int> colPaintedCount(n, 0);
    
    for (int i = 0; i < arr.size(); ++i) {
        int num = arr[i];
        auto [row, col] = positionMap[num];
        
        rowPaintedCount[row]++;
        colPaintedCount[col]++;
        
        if (rowPaintedCount[row] == n || colPaintedCount[col] == m) {
            return i;
        }
    }
    
    return -1; 
}
};