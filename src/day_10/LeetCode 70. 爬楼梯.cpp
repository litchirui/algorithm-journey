// ��쳲��������еĵ�n��
class Solution {
public:
    int climbStairs(int n) {
        int c, a = 1, b = 1;
        for (int i = 1; i < n; i++) { // ִ�� n - 1��
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};
