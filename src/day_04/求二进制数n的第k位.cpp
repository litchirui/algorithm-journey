#include<iostream>

using namespace std;


int main(){
	
	int n = 10;  
	
	for(int k = 3; k >= 0; k --) printf("%d", n >> k & 1);  // 二进制：1010
	
	puts("");
	printf("第3位：%d\n", n >> 3 & 1); 
	printf("第2位：%d\n", n >> 2 & 1);
	printf("第1位：%d\n", n >> 1 & 1);
	printf("第0位：%d\n", n >> 0 & 1);
	
	return 0;
}
