/**
	788. 逆序对的数量
	https://www.acwing.com/problem/content/790/
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int n;
int q[N], tmp[N];

LL merge_sort(int l, int r) {

	if(l >= r) return 0;

	int mid = l + r >> 1;
	LL res = merge_sort(l, mid) + merge_sort(mid + 1, r);

	// 归并
	int k = 0, i = l, j = mid + 1;
	while(i <= mid && j <= r)
		if(q[i] <= q[j])
			tmp[k ++] = q[i ++];
		else 
			tmp[k ++] = q[j ++], res += mid - i + 1;

	// 扫尾
	while(i <= mid) tmp[k ++] = q[i ++];
	while(j <= r) tmp[k ++] = q[j ++];

	// 还原
	for(int i = 0; i < k; i ++) q[l + i] = tmp[i];

	return res;
}

int main() {

	scanf("%d", &n);

	for(int i = 0; i < n; i ++) scanf("%d", &q[i]);

	printf("%lld\n", merge_sort(0, n - 1));

	return 0;
}
