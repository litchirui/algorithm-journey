#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>

using namespace std;

typedef long long ll;

const int N = 1e5;

ll n;

int main(){
	
	scanf("%lld", &n);
	
	if(n > 0)
	while(printf("%lld ", n), n /= 2);
	
	return 0;
}

