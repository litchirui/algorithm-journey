/**
 * a   1 5 3 3 4
 * b   1 2 2 2 1
 * a-b 0 3 1 1 3
 * 差分0 3 -2 0 2
 * 
	算法：差分
	https://www.acwing.com/problem/content/4265/
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];
//思路：将b序列变成a序列，先求a-b序列，再求a-b序列的差分，答案即为将差分序列变为0的次数
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	
	for(int i = 1; i <= n; i ++){
		int b;
		scanf("%d", &b);
		a[i] -= b;
	}
	
	//倒着求差分 
	for(int i = n; i; i --) a[i] -= a[i - 1];
	
	//每次将差分
	int pos = 0, neg = 0;
	for(int i = 1; i <= n; i ++)
		if(a[i] > 0) pos += a[i];
		else neg -= a[i];
	
	printf("%d\n", max(pos, neg)); 
	return 0;
}
