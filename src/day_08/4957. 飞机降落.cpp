#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<climits>

using namespace std;

typedef long long ll;

const int N = 10;

int n, t;
struct Plane{
	int t, d, l;
}p[N];

bool st[N];

bool dfs(int u, int last){
	if(u == n) return true;
	
	for(int i = 0; i < n; i ++){
		int t = p[i].t, d = p[i].d, l = p[i].l;
		if(!st[i] && t + d >= last){
			st[i] = true;
			if(dfs(u + 1, max(last, t) + l)) 
				return true;
			st[i] = false;
		}
	}
	
	return false;
}

int main() {
	
	scanf("%d", &t);
	while(t --){
		scanf("%d", &n);
		for(int i = 0; i < n; i ++){
			scanf("%d%d%d", &p[i].t, &p[i].d, &p[i].l);
		}
		
		fill(st, st + N, 0);
		
		if(dfs(0, 0)) puts("YES");
		else puts("NO");
	}
	
	return 0;
}

