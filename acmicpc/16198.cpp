#include <iostream>
#include <vector>
using namespace std;
#define MAX 11

int n, t, ans;
vector<int> vec;

void solve(int val)
{
	if (vec.size() == 2) {
		ans = max(ans, val);
		return;
	}

	int ret = 0;
	for (int i=1; i<vec.size()-1; ++i) {
		int cur = vec[i];
		int en = vec[i-1] * vec[i+1];
		vec.erase(vec.begin() + i);
		solve(val + en);
		vec.insert(vec.begin() + i, cur);
	}
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> t;
		vec.push_back(t);
	}

	solve(0);

	cout << ans << '\n';

	return 0;
}
