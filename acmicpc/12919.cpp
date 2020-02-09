#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

string s, t;
bool flag;

void solve()
{
	if (s == t) {
		flag = true;
		return;
	}

	if (s.length() == t.length())
		return;

	if (t.back() == 'A') {
		t.pop_back();
		solve();
		t.push_back('A');
	}

	if (t.front() == 'B') {
		reverse(t.begin(), t.end());
		t.pop_back();
		solve();
		t.push_back('B');
		reverse(t.begin(), t.end());
	}
}

int main()
{
	cin >> s >> t;
	solve();
	cout << flag << '\n';

	return 0;
}
