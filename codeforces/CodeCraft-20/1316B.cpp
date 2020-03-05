#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int t, n;
string s;

int main()
{
	cin >> t;
	while (t--) {
		cin >> n >> s;
		vector<pair<string, int>> vec;

		for (int i=0; i<n-1; ++i) {
			string p = s.substr(i, n-i);
			string q = s.substr(0, i);
			if (p.length() % 2)
				reverse(q.begin(), q.end());

			vec.push_back({p + q, i});
		}

		reverse(s.begin(), s.end());
		vec.push_back({s, n - 1});

		sort(vec.begin(), vec.end());

		cout << vec[0].first << '\n';
		cout << vec[0].second + 1 << '\n';
	}

	return 0;
}
