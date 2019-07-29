#include <iostream>
using namespace std;

int n;
bool flag = false;

bool check(string s)
{
	int len = s.length();
	for (int i=1; i<=len/2; ++i) {
		for (int j=0; j<=len-i*2; ++j) {
			string a = s.substr(j, i);
			string b = s.substr(j+i, i*2);
			if (a == b)
				return false;
		}
	}
	return true;
}

void solve(string s)
{
	if (s.length() == n) {
		cout << s << '\n';
		flag = true;
		return;
	}

	for (int i=1; i<=3; ++i) {
		string t = s;
		t += i+'0';
		if (flag)
			return;
		if (check(t))
			solve(t);
	}
}

int main()
{
	cin >> n;

	solve("1");

	return 0;
}
