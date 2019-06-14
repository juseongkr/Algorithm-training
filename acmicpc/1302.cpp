#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<string, int> m;
	string s, ans;
	int n, cnt = 0;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> s;
		m[s]++;
	}

	for (auto it=m.begin(); it!=m.end(); ++it) {
		if (cnt < it->second) {
			cnt = it->second;
			ans = it->first;
		}
	}
	cout << ans << '\n';

	return 0;
}
