#include <iostream>
using namespace std;

int n, cnt, half;
string s, ans;

string solve(int l, int r)
{
	bool flag = false;
	int k = 0, i = l, j = r;
	for (int k=0; k<half; ++k) {
		if (s[i] != s[j]) {
			if (flag)
				return "";
			flag = true;
			k--;
			j++;
		} else {
			i++;
			j++;
		}
	}

	return s.substr(l, half);
}

int main()
{
	cin >> n >> s;
	if (n % 2 == 0) {
		cout << "NOT POSSIBLE\n";
		return 0;
	}

	half = (n-1)/2;
	string a = solve(half+1, 0);
	string b = solve(0, half);

	if (!a.length() && !b.length()) {
		cout << "NOT POSSIBLE\n";
	} else if (!a.length()) {
		cout << b << '\n';
	} else if (!b.length()) {
		cout << a << '\n';
	} else if (a != b) {
		cout << "NOT UNIQUE\n";
	} else {
		cout << a << '\n';
	}

	return 0;
}
