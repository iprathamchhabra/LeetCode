class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result;
        vector<int> count(nums.size(), 0);
        for (int num : nums) {
            count[num - 1]++;
            if (count[num - 1] == 2) {
                result.push_back(num);
            }
        }
        for (int i = 0; i < count.size(); i++) {
            if (count[i] == 0) {
                result.push_back(i + 1);
                break;
            }
        }
        
        return result;
    }
};
