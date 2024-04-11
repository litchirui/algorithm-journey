#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>

using namespace std;


int main(){
	string s, res;
	
	cin >> s;
	
	for(int i = 0; i < s.size(); i ++){
		if(i + 1 < s.size() && s[i + 1] <= '9'){  //大小写英文字母的ascll码一定严格大于'9'的ascll码值 
			int k = s[i + 1] - '0';
			while(k --) res += s[i];
			i ++;
		}else{
			res += s[i];
		}
	}
	cout << res << endl;
	
	return 0;
}


