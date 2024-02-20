#include<iostream>

using namespace std;

const int N = 1e3 + 10;

void split_word(char str[]) {
	
	for(int i = 0; str[i]; i ++ ) {

		int j = i;
		while(str[j] && str[j] != ' ') j ++;  // 循环结束，j指向空格或者字符串尾
		
		for(int k = i; k < j; k ++) printf("%c", str[k]);
		puts("");

		i = j;  // i ++后指向下一个字母
	}
}

int main() {

	char str[N];

	gets(str);
	split_word(str);

	return 0;
}
