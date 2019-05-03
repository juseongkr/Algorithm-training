#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<string, int> check;
	string s;
	int n;

	cin >> n;
	for (int k=0; k<n; ++k) {
		cin >> s;
		string t = s;
		reverse(t.begin(), t.end());
		if (t == s || check.count(t))
			cout << s.length() << " " << s[s.length()/2] << '\n';
		else
			check[s] = 1;
	}

	return 0;
}
