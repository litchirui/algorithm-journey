/**
	����㣺���ʣ�µĳ����� L = n/2 (��ȡ��)���ҵ������� L ���������䣬��ȡ����͵����ֵ 
	�㷨��ǰ׺��
	https://www.acwing.com/problem/content/564/
*/

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 5e6 + 10;

int n;
int s[N];
char str[N];

int main(){
    int T;
    scanf("%d", &T);
    int t = 0;
    while(T --){
        scanf("%d", &n);
        scanf("%s", str + 1);  // ���ַ��������±��1��ʼ��λ��
        for(int i = 1; i <= n; i ++) s[i] = s[i - 1] + str[i] - '0';  // Ԥ����ǰ׺��
            
        int res = 0, m = (n + 1) / 2;  // ��ȡ��
        for(int i = m; i <= n; i ++)  // ö�ٳ���Ϊm�����䣬���������ֵ
            res = max(res, s[i] - s[i - m]);
        
        printf("Case #%d: %d\n", ++t, res);
    }
    
    return 0;
}
