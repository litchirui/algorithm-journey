#include<iostream>

using namespace std;

const int N = 1e3 + 10;

void split_word(char str[]) {
	
	for(int i = 0; str[i]; i ++ ) {

		int j = i;
		while(str[j] && str[j] != ' ') j ++;  // ѭ��������jָ��ո�����ַ���β
		
		for(int k = i; k < j; k ++) printf("%c", str[k]);
		puts("");

		i = j;  // i ++��ָ����һ����ĸ
	}
}

int main() {

	char str[N];

	gets(str);
	split_word(str);

	return 0;
}
