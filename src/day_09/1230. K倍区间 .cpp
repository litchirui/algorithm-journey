#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<climits>

using namespace std;
using ll = long long;

const int N = 1e5 + 10;

int n, k;
ll s[N];
int cnt[N];

int main() {
		
	scanf("%d%d", &n, &k);
	
	for(int i = 1; i <= n; i ++){
		scanf("%d", &s[i]);
		s[i] += s[i - 1];
	}
	
	ll res = 0;
	cnt[0] ++;
	for(int i = 1; i <= n; i ++){
		res += cnt[s[i] % k] ;
		cnt[s[i] % k] ++;
	}
	
	printf("%lld\n", res);	
	return 0;
}

