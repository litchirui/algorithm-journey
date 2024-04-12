/**
	子串简写（前缀和思想/双指针） 题解：https://www.acwing.com/solution/content/163084/
	这题首先想到的暴力做法，是两层循环控制区间的长度,再判断区间的首尾是否和条件相等, 时间复杂度为O(n^2)显然会超时.
	这里用双指针动态维护一段长度为k的区间， 在右端点往后用前缀和思想预处理b的数量，b的数量即为以a为起点所有满足题意区间的数量，再移动动态区间即可。
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<climits>

using namespace std;
typedef long long ll;
const int N = 5e5 + 10;

int n, k, cnt;
char s[N], a, b;
ll res;

int main() {
	//	cin >> k >> s + 1 >> a >> b;

	//	cout << k << endl;
	//	cout << s + 1 << ' ' << a << ' ' << b << endl;

	scanf("%d", &k);
	scanf("%s %c %c", s + 1, &a, &b);

	n = strlen(s + 1);
	//后缀和形式 
//	for(int i = 1, j = k; j <= n; i ++, j ++) {
//		if(s[i] == a) cnt ++;
//		if(s[j] == b) res += cnt;
//	}

	// 为了方便理解写成后缀和形式
	// i为长度为 k的区间首指针，初始指向最后一个这样区间的第一个元素，j为尾指针 
	for(int i = n - k + 1, j = n; i >= 1; i --, j --) {
		if(s[j] == b) cnt ++;
		if(s[i] == a) res += cnt;
	}

	cout << res << endl;

	return 0;
}

