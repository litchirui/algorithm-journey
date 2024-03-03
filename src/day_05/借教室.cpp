#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e6 + 10;

int n, m;
int w[N];
int l[N], r[N], d[N];
LL b[N];

bool check(int mid)
{
    fill(b, b + N, 0);
    for (int i = 1; i <= mid; i ++ ){
        b[l[i]] += d[i];
        b[r[i] + 1] -= d[i];
    }

    for (int i = 1; i <= n; i ++ ){
        b[i] += b[i - 1];
        if (b[i] > w[i]) return false;
    }

    return true;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &w[i]);
    for (int i = 1; i <= m; i ++ ) scanf("%d%d%d", &d[i], &l[i], &r[i]);

    int l = 0, r = m;
    while (l < r){
        int mid = l + r + 1 >> 1;
        check(mid)? l = mid : r = mid - 1;
    }

    if (r == m) puts("0");
    else printf("-1\n%d\n", r + 1);
    return 0;
}
