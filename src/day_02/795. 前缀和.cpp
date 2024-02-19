/**
	795. ǰ׺��
	https://www.acwing.com/problem/content/797/
*/

#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int s[N];

int main(){
	
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++ ){
		scanf("%d", &s[i]);
		s[i] += s[i - 1];
	}
	
	while(m --){
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", s[r] - s[l - 1]);
	}
	
} 
