#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>

using namespace std;

const int N = 40;

int n, m;
int f[N][N];

int main() {

	cin >> n >> m;

	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m ; j ++) {
			if(i == 1 && j == 1) 
				f[i][j] = 1;
			else{
				if(i % 2 || j % 2)
				f[i][j] = f[i - 1][j] + f[i][j - 1];
			}
		}

	cout << f[n][m] << endl;
	return 0;
}


