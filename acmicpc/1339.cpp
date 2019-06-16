#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int dict[26];

int main()
{
	vector<int> vec;
	int n, ans = 0, t = 9;
	string s;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> s;
		for (int j=0; j<s.length(); ++j) {
			int k = pow(10, s.length()-1-j);
			dict[s[j]-'A'] += k;
		}
	}

	for (int i=0; i<26; ++i)
		if (dict[i])
			vec.push_back(dict[i]);

	sort(vec.rbegin(), vec.rend());

	for (int i=0; i<vec.size(); ++i)
		ans += vec[i] * t--;

	cout << ans << '\n';

	return 0;
}
