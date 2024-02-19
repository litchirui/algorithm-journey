/**
	796. 子矩阵的和
	https://www.acwing.com/problem/content/798/
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 

using namespace std;

const int N = 5e3 + 10;

int n, m, q;
int s[N][N];

int main(){
	
	scanf("%d%d%d", &n, &m, &q);
	
	// 求二维前缀和
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++){
			scanf("%d", &s[i][j]);
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
		}
			
	
	// 解决询问
	int x1, y1, x2, y2;
	while(~scanf("%d%d%d%d", &x1, &y1, &x2, &y2)){
		printf("%d\n", s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);
	}
	
	return 0;
}
