#include <iostream>
#include <vector>
using namespace std;

int t, n, m;
string p;

int main()
{
	cin >> t;
	while (t--) {
		vector<string> s;
		cin >> n >> m;
		for (int i=0; i<n; ++i) {
			cin >> p;
			s.push_back(p);
		}

		vector<int> row, col;
		row.resize(n);
		col.resize(m);
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				row[i] += (s[i][j] == '.');
				col[j] += (s[i][j] == '.');
			}
		}

		int ans = n+m;
		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j)
				ans = min(ans, row[i] + col[j] - (s[i][j] == '.'));
		cout << ans << '\n';
	}

	return 0;
}
