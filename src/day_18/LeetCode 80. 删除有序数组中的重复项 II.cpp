class Solution {
public:
    //双指针
    int removeDuplicates(vector<int>& nums) {
        int k = 0;  //当前数组有效元素个数
        for(auto x: nums){
            if(k < 2 || (nums[k - 1] != x || nums[k - 2] != x))
            nums[k ++] = x;
        }
        return k;
    }
};

class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) return nums.size();
        int k = 1;
        for (int i = 2; i < nums.size(); i ++ )
            if (nums[i] != nums[k - 1])
                nums[ ++ k] = nums[i];
        k ++ ;
        return k;
    }
};

