#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<climits>

using namespace std;

typedef long long ll;

const int N = 1e9 + 10;

int n;
int a, b; 

int get(int a, int b){
	int l = 1, r = 1e9 + 1;
	while(l < r){
		int mid = l + r >> 1;
		if(a / mid <= b) r = mid;
		else l = mid + 1;
	}
	return r;
}

int main() {
	
	int maxv = 1e9, minv = 1;
	scanf("%d", &n);
	while(~scanf("%d%d", &a, &b)){
		minv = max(minv, get(a, b));
		maxv = min(maxv, get(a, b - 1) - 1);
	}
	
	printf("%d %d\n", minv, maxv);
	
	return 0;
}

