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
PII q[N * N];  //��ÿ������, һ��i���ܶ�Ӧ���j,�� Nƽ������Ķ���ռ� 

bool cmp(PII a, PII b){
	return a.y * b.x < a.x * b.y;
}

int main() {
	scanf("%d", &n); 
	
	for(int i = 1; i <= n; i ++)  // ��ĸ
		for(int j = 0; j <= i; j ++)  // ���� 
			if(__gcd(i, j) == 1)
				q[cnt ++] = {i, j};
	
	sort(q, q + cnt, cmp);
	
	for(int i = 0; i < cnt; i ++)
		printf("%d/%d\n", q[i].y, q[i].x);
	
	return 0;
}

