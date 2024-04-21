class Solution {
public:
    // 枚举型排列
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();

        for(int i = 0; i < 1 << n; i ++){
            vector<int> temp;
            for(int j = 0; j < n; j ++)
                if(i >> j & 1)
                    temp.push_back(nums[j]);
            res.push_back(temp);
        }        
        return res;
    }
};