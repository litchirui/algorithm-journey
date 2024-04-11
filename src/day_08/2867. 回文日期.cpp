#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 10;

const int months[] = {
	0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

bool is_leap(int year) {
	return year % 4 == 0 && year % 100 || year % 400 == 0;
}

int get_days(int y, int m) {
	if(m == 2)
		return 28 + is_leap(y);
	return months[m];
}

void next_day(int &y, int &m, int &d) {
	d ++;
	if(d > get_days(y, m)) {
		d = 1;
		m ++;
		if(m > 12) {
			m = 1;
			y ++;
		}
	}
}

bool check1(char s[]) { //判断是否是回文日期
	for(int i = 0, j = 7; i < j; i ++, j --) {
		if(s[i] != s[j])
			return false;
	}
	return true;
}

bool check2(char s[]) { //判断是否是 ABABBABA型的回文日期
	return s[0] == s[2] && s[1] == s[3] && s[0] != s[1];
}

int main() {
	int y, m, d;
	scanf("%04d%02d%02d", &y, &m, &d);

	char s[N] = {0};

	bool found1 = false, found2 = false;
	while(!found1 || !found2) {
		next_day(y, m, d);
		sprintf(s, "%04d%02d%02d", y, m, d);
		if(check1(s)) {
			if(!found1) {
				puts(s);
				found1 = true;
			}
			if(!found2 && check2(s)) {
				found2 = true;
				puts(s);
			}
		}
	}

	return 0;
}

