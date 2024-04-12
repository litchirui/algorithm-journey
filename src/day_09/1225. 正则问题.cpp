#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>

using namespace std;

int k;
string str;

int dfs()
{
    int res = 0;
    while (k < str.size())
    {
        if (str[k] == '(')  // ���� (......)
        {
            k ++ ;  // ���� '('
            res += dfs();
            k ++ ; // ���� ')'
        }
        else if (str[k] == '|')
        {
            k ++ ;  // ���� '|'
            res = max(res, dfs());
        }
        else if (str[k] == ')') break;
        else
        {
            k ++ ;  // ���� 'x'
            res ++ ;
        }
    }

    return res;
}

int main()
{
    cin >> str;
    cout << dfs() << endl;

    return 0;
}

