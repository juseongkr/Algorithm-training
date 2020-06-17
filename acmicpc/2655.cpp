#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 101
typedef tuple<int, int, int, int> tp;

int dp[MAX];
int n, b, h, w;
vector<tp> block;
vector<int> log;

int solve(int cur)
{
	if (cur == n)
		return 0;

	if (~dp[cur])
		return dp[cur];

	dp[cur] = 0;
	auto [b, h, w, k] = block[cur];
	for (int i=cur+1; i<n; ++i) {
		auto [nb, nh, nw, nk] = block[i];
		if (w > nw)
			dp[cur] = max(dp[cur], solve(i));
	}

	return dp[cur] += h;
}

void trace(int cur, int weight)
{
	log.push_back(get<3>(block[cur]));

	for (int i=cur+1; i<n; ++i) {
		auto [b, h, w, k] = block[cur];
		auto [nb, nh, nw, nk] = block[i];

		if (w > nw && solve(i) == weight) {
			trace(i, weight - nh);
			return;
		}
	}
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> b >> h >> w;
		block.push_back({b, h, w, i+1});
	}

	sort(block.rbegin(), block.rend());
	fill(dp, dp+MAX, -1);

	int weight = 0, first = 0;
	for (int i=0; i<n; ++i) {
		int cur = solve(i);
		if (weight < cur) {
			first = i;
			weight = cur;
		}
	}

	trace(first, weight - get<1>(block[first]));

	cout << log.size() << '\n';
	for (int i=log.size()-1; i>=0; i--)
		cout << log[i] << '\n';

	return 0;
}
