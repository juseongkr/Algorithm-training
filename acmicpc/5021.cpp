#include <iostream>
#include <map>
using namespace std;
#define MAX 51
const int INF = 1e9+7;

int n, m;
map<string, double> mp;
string x[MAX], y[MAX], z[MAX], s, ans;

int main()
{
	cin >> n >> m >> s;
	mp[s] = INF;
	for (int i=0; i<n; ++i)
		cin >> z[i] >> x[i] >> y[i];

	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			mp[z[j]] = (mp[x[j]] + mp[y[j]]) / 2;

	double cur = 0;
	for (int i=0; i<m; ++i) {
		cin >> s;
		if (cur < mp[s]) {
			cur = mp[s];
			ans = s;
		}
	}
	cout << ans << '\n';

	return 0;
}
