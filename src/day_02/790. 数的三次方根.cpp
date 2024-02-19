/**
	790. 数的三次方根
	https://www.acwing.com/problem/content/792/
*/

#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    double x;
    scanf("%lf", &x);
    
    double l = -10000, r = 10000;  
    while(r - l > 1e-8){  
        double mid = (l + r) / 2;
        mid * mid * mid >= x ? r = mid : l = mid;
    }
    
    printf("%lf\n", l);
    
    return 0;
}
