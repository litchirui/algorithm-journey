//接龙数列 | 线性DP 题解：https://www.acwing.com/solution/content/183951/
 
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<climits>

using namespace std;

const int N = 1e5 + 10;

int n;
int l[N], r[N];
int f[N], g[10];  // g[x]：最后一位数以x结尾的序列最大长度 

int main() {
	scanf("%d", &n);
	
	char num[10];
	for(int i = 0; i < n; i ++){
		scanf("%s", num);
		l[i] = num[0] -'0', r[i] = num[strlen(num) - 1] - '0';
	}
	
	int res = 0;
	for(int i = 0; i < n; i ++){
		f[i] = 1;
//		for(int j = 0; j < i; j ++)
//			if(r[j] == l[i])
//				f[i] = max(f[i], f[j] + 1);
		f[i] = max(f[i], g[l[i]] + 1);
		g[r[i]] = max(g[r[i]], f[i]);
		res = max(res, f[i]);
	}
	
//	要求使得数列变成接龙数列的最少删除个数， 相当于求该数列的最长接龙子数列的长度， 用总长度减去最长接龙长度即为最少删除个数。
	printf("%d\n",n - res);
	
	return 0;
}

