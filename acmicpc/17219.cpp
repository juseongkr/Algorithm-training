#include <iostream>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	map<string, string> mp;
	string s, p;
	int n, m;

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> s >> p;
		mp[s] = p;
	}

	for (int i=0; i<m; ++i) {
		cin >> s;
		cout << mp[s] << '\n';
	}

	return 0;
}
