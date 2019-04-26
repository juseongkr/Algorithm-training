#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool func(string a, string b)
{
	if (a.length() != b.length()) {
		return a.length() < b.length();
	} else {
		int s1 = 0, s2 = 0;
		for (int i=0; i<a.length(); ++i) {
			if (1 <= a[i]-'0' && a[i]-'0' <= 9)
				s1 += (a[i]-'0');
			if (1 <= b[i]-'0' && b[i]-'0' <= 9)
				s2 += (b[i]-'0');
		}
		if (s1 != s2)
			return s1 < s2;
	}
	return a < b;
}

int main()
{
	vector<string> v;
	string str;
	int n;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> str;
		v.push_back(str);
	}

	sort(v.begin(), v.end(), func);

	for (int i=0; i<n; ++i)
		cout << v[i] << '\n';

	return 0;
}
