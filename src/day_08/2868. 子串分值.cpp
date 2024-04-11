#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int n;
char str[N];
int l[N], r[N];  // 分别表示 str[i]上次出现的位置和下次出现的位置 
int p[30];  // 26个字母第一次出现的位置

int main() {

	scanf("%s", str + 1);  // 将字符串读到下标从1开始的位置
	n = strlen(str + 1);  //字符串长度

	// 求 l[i] 
	for(int i = 1; i <= n; i ++) {
		int t = str[i] - 'a';  // 将 26个字母映射成下标 0 - 25
		l[i] = p[t];  // 左边第一次出现的位置是pt 
		p[t] = i;  // 将pt更新成当前的位置 
	}
	
	fill(p, p + 30, n + 1);
	
	// 求 r[i] 
	for(int i = n; i; i --){
		int t = str[i] - 'a';
		r[i] = p[t];
		p[t] = i;
	}
	
	ll res = 0;
	for (int i = 1; i <= n; i ++)
		res += (ll)(i - l[i]) * (r[i] - i); 
	
	printf("%lld\n", res);

	return 0;
}

