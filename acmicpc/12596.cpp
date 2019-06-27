#include <iostream>
#include <map>
using namespace std;

int main()
{
	int g, n, k;

	cin >> g;
	for (int t=1; t<=g; ++t) {
		map<int, int> m;
		cin >> n;
		for (int i=0; i<n; ++i) {
			cin >> k;
			if (m.count(k))
				m[k]++;
			else
				m.insert({k, 1});
		}
		for (auto i : m) {
			if (i.second == 1) {
				cout << "Case #" << t << ": " << i.first << '\n';
				break;
			}
		}
	}

	return 0;
}
