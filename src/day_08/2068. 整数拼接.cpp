/*
	思路：https://www.acwing.com/solution/content/43755/
*/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

typedef long long LL;
const int N=100010;
int s[11][N];//表示某个数*10^i%k==j的数量
int n;//表示将要输入的n个数
LL a[N];//存放n个数
int k;//表示k倍
LL res;//表示结果

int main() {
	//1.输入数据
	cin >> n >> k;
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	//2.预处理s数组
	for(int i = 0; i < n; i ++) {
		LL t = a[i] % k;

		for(int j = 0; j < 11; j ++) { //因为题目中给出的最大数是10^9
			s[j][t] ++;
			t = t * 10 % k;
		}
	}

	//3.循环数组计算答案
	for(int i = 0; i < n; i ++) {
		LL t = a[i] % k;
		int len = to_string(a[i]).size();//将这个数字转化为字符串，再判断转换后的字符串的位数就等于这个数字本身的位数
		res += s[len][(k - t) % k];

		//4.判重
		LL r = t;
		while(len--) r = r * 10 % k;  //等价于求a[i]乘以10^len的余数，同上面的预处理求法一样
		if(r == (k - t) % k) res --;
	}

	//5.输出答案
	cout << res << endl;

	return 0;
}


