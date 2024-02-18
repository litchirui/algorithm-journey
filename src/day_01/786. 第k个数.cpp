/** 
	786. 第k个数
	https://www.acwing.com/problem/content/description/788/
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 

using namespace std;

const int N = 1e5 + 10;

int n, k;
int a[N];

int quick_sort(int l, int r, int k){
	
	if(l == r) return a[l];
	
	int x = a[l], i = l - 1, j = r + 1;
	while(i < j){
		while(a[++ i] < x);
		while(a[-- j] > x);
		if(i < j) swap(a[i], a[j]);
	}
	
	// 划分左半区间长度 
	int sl = j - l + 1;
	return k <= sl ? quick_sort(l, j, k) : quick_sort(j + 1, r, k - sl);
}

int main(){
	
	scanf("%d%d", &n, &k);
	
	for(int i = 0; i < n; i ++) scanf("%d", &a[i]);
	
	printf("%d\n", quick_sort(0, n - 1, k));
	
	return 0;
}
