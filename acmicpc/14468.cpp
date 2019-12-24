#include <iostream>
using namespace std;

pair<int, int> v[26];

int main()
{
	string s;

	cin >> s;
	for (int i=0; i<52; ++i) {
		int c = s[i]-'A';
		if (v[c].first == 0)
			v[c].first = i+1;
		else
			v[c].second = i+1;
	}

	int ans = 0;
	for (int i=0; i<26; ++i) {
		for (int j=0; j<26; ++j) {
			if (v[i].second < v[j].second && v[i].first < v[j].first && v[j].first < v[i].second)
				ans++;
		}
	}
	cout << ans << '\n';

	return 0;
}
