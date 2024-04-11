/*
	˼·��https://www.acwing.com/solution/content/43755/
*/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

typedef long long LL;
const int N=100010;
int s[11][N];//��ʾĳ����*10^i%k==j������
int n;//��ʾ��Ҫ�����n����
LL a[N];//���n����
int k;//��ʾk��
LL res;//��ʾ���

int main() {
	//1.��������
	cin >> n >> k;
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	//2.Ԥ����s����
	for(int i = 0; i < n; i ++) {
		LL t = a[i] % k;

		for(int j = 0; j < 11; j ++) { //��Ϊ��Ŀ�и������������10^9
			s[j][t] ++;
			t = t * 10 % k;
		}
	}

	//3.ѭ����������
	for(int i = 0; i < n; i ++) {
		LL t = a[i] % k;
		int len = to_string(a[i]).size();//���������ת��Ϊ�ַ��������ж�ת������ַ�����λ���͵���������ֱ����λ��
		res += s[len][(k - t) % k];

		//4.����
		LL r = t;
		while(len--) r = r * 10 % k;  //�ȼ�����a[i]����10^len��������ͬ�����Ԥ������һ��
		if(r == (k - t) % k) res --;
	}

	//5.�����
	cout << res << endl;

	return 0;
}


