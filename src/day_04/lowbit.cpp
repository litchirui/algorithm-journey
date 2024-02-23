#include<iostream>

using namespace std;

int lowbit(int x){
	return x & -x;
}

int main(){
	
	int n = 10;  // 1010
	
	printf("%d\n", lowbit(n));  // 2
	
	for(int i = 31; i >= 0; i --) printf("%d", n >> i & 1);  puts("ԭ��");
	
	int x = -n;
	for(int i = 31; i >= 0; i --) printf("%d", x >> i & 1);  puts("����");
	
	int y = ~n;
	for(int i = 31; i >= 0; i --) printf("%d", y >> i & 1);  puts("����");
	
	return 0;
}
