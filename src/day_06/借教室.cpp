/**
	https://www.acwing.com/problem/content/505/
*/
#include<iostream>
#include<cstring>
#include<algorithm>

typedef long long LL;

using namespace std;

const int N = 1e6 + 10;

int n, m;
int w[N];
int d[N], s[N], t[N];
LL b[N];

bool check(int mid){
    memset(b, 0, sizeof b);
    for(int i = 1; i <= mid; i ++){
        b[s[i]] += d[i];
        b[t[i] + 1] -= d[i];
    }
    
    LL s = 0;  // 前缀和
    for(int i = 1; i <= n; i ++){  // 遍历天数，返回教室数量是否能满足所有订单需求
        s += b[i];
        if(s > w[i]) return false;  // 订单需求 > 某天教室数量
    }
    return true;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%d", &w[i]);
    for(int i = 1; i <= m; i ++) scanf("%d%d%d", &d[i], &s[i], &t[i]);
    
    int l = 0, r = m;
    while(l < r){
        int mid = l + r + 1 >> 1;
        check(mid) ? l = mid : r = mid - 1;
    }
    
    if(l == m) puts("0");
    else printf("-1\n%d\n", l + 1);
    
    
    return 0;
}
