#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>

#define x first
#define y second

using namespace std;
using ll = long long;
using PII = pair<int, int>;


const int N = 2e2 + 10;

int n, cnt;
PII q[N * N];  //存每个分数, 一个i可能对应多个j,开 N平方级别的额外空间 

bool cmp(PII a, PII b){
	return a.y * b.x < a.x * b.y;
}

int main() {
	scanf("%d", &n); 
	
	for(int i = 1; i <= n; i ++)  // 分母
		for(int j = 0; j <= i; j ++)  // 分子 
			if(__gcd(i, j) == 1)
				q[cnt ++] = {i, j};
	
	sort(q, q + cnt, cmp);
	
	for(int i = 0; i < cnt; i ++)
		printf("%d/%d\n", q[i].y, q[i].x);
	
	return 0;
}

