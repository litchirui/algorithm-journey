#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<climits>
const int N = 1e4 + 10;

int n, a[N];

int main() {
	int maxv =INT_MIN , minv = INT_MAX;
	double avg = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++) {
		scanf("%d", &a[i]);
		if(a[i] > maxv) maxv = a[i]; if(a[i] < minv) minv = a[i];
		avg += a[i];
	}
	
	avg /= n;
	printf("%d\n", maxv);
	printf("%d\n", minv);
	printf("%.2lf\n", avg);

	return 0;
}
