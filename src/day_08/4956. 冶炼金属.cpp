// 暴力枚举：https://www.acwing.com/solution/content/183543/
//严格数学推导：https://www.acwing.com/solution/content/183693/
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

int main() {
	
	int maxv =INT_MAX , minv = INT_MIN;
	
	scanf("%d", &n);
	while(~scanf("%d%d", &a, &b)){
		minv = max(minv, a / (b + 1) + 1);  //不能低于每一个炉子的最小值，取max
	    maxv = min(maxv, a / b); //不能大于每一个炉子的最大值，取max
	}
	
	printf("%d %d\n", minv, maxv);
	
	return 0;
}

