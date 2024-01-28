class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int r = matrix.size(), c = matrix[0].size();
        for(int i = 0;i < r;i++){
            for(int j = 1;j < c;j++){
                matrix[i][j] += matrix[i][j-1]; 
            }
        }
        int cnt = 0;
        map<int, int> mp;
        for(int i = 0;i < c;i++){
            for(int j = i;j < c;j++){
                mp.clear();
                mp[0] = 1;
                int sum = 0;
                for(int k = 0;k < r;k++){
                    sum += matrix[k][j] - (i > 0 ? matrix[k][i-1] : 0);
                    cnt += mp[sum - target];
                    mp[sum]++;
                }
            }
        }
        return cnt;
    }
};