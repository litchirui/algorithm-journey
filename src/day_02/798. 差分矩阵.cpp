/**
	798. ≤Ó∑÷æÿ’Û
	https://www.acwing.com/problem/content/description/800/
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;

int n, m, q;
int t, b[N][N];

void insert(int x1, int y1, int x2, int y2, int c) {
	b[x1][y1] += c;
	b[x2 + 1][y1] -= c;
	b[x1][y2 + 1] -= c;
	b[x2 + 1][y2 + 1] += c;
}

int main() {
	scanf("%d%d%d", &n, &m, &q);

	for(int i = 1; i <= n; i ++ )
		for(int j = 1; j <= m; j ++ )
			scanf("%d", &t), insert(i, j, i, j, t);

	int x1, y1, x2, y2;
	while(~scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &t))  insert(x1, y1, x2, y2, t);

	for(int i = 1; i <= n; i ++ ) {
		for(int j = 1; j <= m; j ++ )
			b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1], printf("%d ", b[i][j]);
		puts("");
	}

	return 0;
}
