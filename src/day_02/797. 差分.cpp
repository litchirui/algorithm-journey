/**
	797. ²î·Ö
	https://www.acwing.com/problem/content/description/799/
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 

using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N], b[N];

void insert(int l, int r, int c){
	b[l] += c;
	b[r + 1] -= c;
}

int main(){
	scanf("%d%d", &n, &m);
	
	for(int i = 1; i <= n; i ++ ) scanf("%d", &a[i]), insert(i, i , a[i]);
	
	int l, r, c;
	while(~scanf("%d%d%d", &l, &r, &c)) insert(l, r, c);
	
	for(int i = 1; i <= n; i ++) b[i] += b[i - 1], printf("%d ", b[i]);
	
	return 0;
}