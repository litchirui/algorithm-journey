#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<climits>

using namespace std;
using ll = long long;

const int N = 1e5 + 10;

int n, k;
int h[N], w[N];

int check(int mid) {
    ll res = 0;
	for(int i = 0; i < n; i ++) {
		res += (ll) h[i] / mid * (w[i] / mid);
		if(res >= k) return 1;
	}
	return 0;
}

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i ++) scanf("%d%d", &h[i], &w[i]);

	int l = 1, r = 1e5;
	while(l < r) {
		int mid = l + r + 1 >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}

	printf("%d\n", r);

	return 0;
}

