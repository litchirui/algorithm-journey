/**
	�Ӵ���д��ǰ׺��˼��/˫ָ�룩 ��⣺https://www.acwing.com/solution/content/163084/
	���������뵽�ı���������������ѭ����������ĳ���,���ж��������β�Ƿ���������, ʱ�临�Ӷ�ΪO(n^2)��Ȼ�ᳬʱ.
	������˫ָ�붯̬ά��һ�γ���Ϊk�����䣬 ���Ҷ˵�������ǰ׺��˼��Ԥ����b��������b��������Ϊ��aΪ�����������������������������ƶ���̬���伴�ɡ�
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
	//��׺����ʽ 
//	for(int i = 1, j = k; j <= n; i ++, j ++) {
//		if(s[i] == a) cnt ++;
//		if(s[j] == b) res += cnt;
//	}

	// Ϊ�˷������д�ɺ�׺����ʽ
	// iΪ����Ϊ k��������ָ�룬��ʼָ�����һ����������ĵ�һ��Ԫ�أ�jΪβָ�� 
	for(int i = n - k + 1, j = n; i >= 1; i --, j --) {
		if(s[j] == b) cnt ++;
		if(s[i] == a) res += cnt;
	}

	cout << res << endl;

	return 0;
}

