class Solution {
    // 类似荷兰国旗问题
    // 三指针 j、i右移, k左移
    // 保证 0到j - 1是 0, j到i - 1是 1, k到n-1是 2
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0, j = 0, k = n - 1; i <= k;){
            if(nums[i] == 0) swap(nums[i ++], nums[j ++]);
            else if(nums[i] == 2) swap(nums[i], nums[k --]);
            else i ++;
        }
    }
};