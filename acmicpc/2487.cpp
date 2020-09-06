#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
inline int lcm(int a, int b) { return a / gcd(a, b) * b; }

int n;
vector<int> vec;
vector<bool> visit;

int dfs(int cur, int cnt)
{
	if (visit[cur])
		return cnt;
	visit[cur] = 1;

	return dfs(vec[cur], cnt+1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	vec.resize(n+1);
	visit.resize(n+1, 0);
	for (int i=1; i<=n; ++i)
		cin >> vec[i];

	int ans = 1;
	for (int i=1; i<=n; ++i) {
		if (!visit[i]) {
			int t = dfs(i, 0);
			ans = lcm(ans, t);
		}
	}
	cout << ans << '\n';

	return 0;
}
