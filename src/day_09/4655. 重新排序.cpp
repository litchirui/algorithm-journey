#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>

using namespace std;
using ll = long long;
const int N = 1e5 + 10;

int n, m;
int w[N];
int s[N];  // 统计每个位置的 w[i]会被加多少次 

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d", &w[i]);
	
	scanf("%d", &m);
	while(m --) {
		int l, r;
		scanf("%d%d", &l, &r);
		s[l] ++, s[r + 1] --;  
	}
	
	for(int i = 1; i <= n; i ++) 
		s[i] += s[i - 1];
	
	ll sum1 = 0;
	for(int i = 1; i <= n; i ++) 
		sum1 += (ll) s[i] * w[i];
	
	ll sum2 = 0;
	sort(s + 1, s + n + 1);
	sort(w + 1, w + n + 1);
	for(int i = 1; i <= n; i ++) 
		sum2 += (ll) s[i] * w[i];
	
	printf("%lld", sum2 - sum1);
	

	return 0;
}

