/**
	切入点：最后剩下的长度是 L = n/2 (上取整)，找到长度是 L 的所有区间，并取区间和的最大值 
	算法：前缀和
	https://www.acwing.com/problem/content/564/
*/

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 5e6 + 10;

int n;
int s[N];
char str[N];

int main(){
    int T;
    scanf("%d", &T);
    int t = 0;
    while(T --){
        scanf("%d", &n);
        scanf("%s", str + 1);  // 把字符串读到下标从1开始的位置
        for(int i = 1; i <= n; i ++) s[i] = s[i - 1] + str[i] - '0';  // 预处理前缀和
            
        int res = 0, m = (n + 1) / 2;  // 上取整
        for(int i = m; i <= n; i ++)  // 枚举长度为m的区间，并更新最大值
            res = max(res, s[i] - s[i - m]);
        
        printf("Case #%d: %d\n", ++t, res);
    }
    
    return 0;
}
