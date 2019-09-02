#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string s, t;

	cin >> s >> t;
	int len = t.length();
	for (int i=0; i<len; ++i) {
		if (s == t) {
			cout << "1\n";
			return 0;
		}
		char c = t[t.length()-1];
		t.pop_back();
		if (c == 'B')
			reverse(t.begin(), t.end());
	}
	cout << "0\n";

	return 0;
}
