/**
	799. 最长连续不重复子序列
	https://www.acwing.com/problem/content/description/801/
*/

#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int n, a[N], cnt[N];

int get_max(int a[]){
	
	int res = 0;
	for(int i = 0, j = 0; i < n; i ++){
		cnt[a[i]] ++;
		while(cnt[a[i]] > 1) cnt[a[j ++]] --;
		res = max(res, i - j + 1);
	}
	return res;
}

int main(){
	
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
	
	printf("%d\n", get_max(a));
	
	return 0;
}