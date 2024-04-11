#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int n;
char str[N];
int l[N], r[N];  // �ֱ��ʾ str[i]�ϴγ��ֵ�λ�ú��´γ��ֵ�λ�� 
int p[30];  // 26����ĸ��һ�γ��ֵ�λ��

int main() {

	scanf("%s", str + 1);  // ���ַ��������±��1��ʼ��λ��
	n = strlen(str + 1);  //�ַ�������

	// �� l[i] 
	for(int i = 1; i <= n; i ++) {
		int t = str[i] - 'a';  // �� 26����ĸӳ����±� 0 - 25
		l[i] = p[t];  // ��ߵ�һ�γ��ֵ�λ����pt 
		p[t] = i;  // ��pt���³ɵ�ǰ��λ�� 
	}
	
	fill(p, p + 30, n + 1);
	
	// �� r[i] 
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

