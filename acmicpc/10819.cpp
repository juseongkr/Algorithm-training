#include <iostream>
#include <vector>
using namespace std;

int n, ans;
int check[9];
vector<int> vec, ret;

void dfs()
{
	if (ret.size() == n) {
		int sum = 0;
		for (int i=1; i<n; ++i)
			sum += abs(ret[i-1] - ret[i]);
		ans = max(ans, sum);
	}

	for (int i=0; i<n; ++i) {
		if (!check[i]) {
			check[i] = 1;
			ret.push_back(vec[i]);
			dfs();
			ret.pop_back();
			check[i] = 0;
		}
	}
}

int main()
{
	int t;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> t;
		vec.push_back(t);
	}

	dfs();

	cout << ans << '\n';

	return 0;
}
