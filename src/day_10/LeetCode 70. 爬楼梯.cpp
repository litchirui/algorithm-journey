// 求斐波那契数列的第n项
class Solution {
public:
    int climbStairs(int n) {
        int c, a = 1, b = 1;
        for (int i = 1; i < n; i++) { // 执行 n - 1次
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};
