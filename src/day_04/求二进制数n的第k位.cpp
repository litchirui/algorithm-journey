#include<iostream>

using namespace std;


int main(){
	
	int n = 10;  
	
	for(int k = 3; k >= 0; k --) printf("%d", n >> k & 1);  // �����ƣ�1010
	
	puts("");
	printf("��3λ��%d\n", n >> 3 & 1); 
	printf("��2λ��%d\n", n >> 2 & 1);
	printf("��1λ��%d\n", n >> 1 & 1);
	printf("��0λ��%d\n", n >> 0 & 1);
	
	return 0;
}
