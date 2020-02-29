#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 21

string s;
int n, k;
long long ans;
vector<int> vec[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> s;
		vec[s.length()].push_back(i);
	}

	for (int i=0; i<MAX; ++i) {
		for (int j=0; j<vec[i].size(); ++j) {
			auto it = lower_bound(vec[i].begin(), vec[i].end(), vec[i][j] - k) - vec[i].begin();
			ans += (j - it);
		}
	}
	cout << ans << '\n';

	return 0;
}
