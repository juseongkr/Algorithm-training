#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define MAX 21

int x[MAX], y[MAX];
bool visit[MAX];
double ans;
int n;

void dfs(int idx, int cnt)
{
	if (idx == n)
		return;

	if (cnt == n/2) {
		double a = 0.0, b = 0.0;
		for (int i=0; i<n; ++i) {
			if (visit[i]) {
				a -= x[i];
				b -= y[i];
			} else {
				a += x[i];
				b += y[i];
			}
		}
		ans = min(ans, sqrt(a*a + b*b));
		return;
	}

	dfs(idx+1, cnt);
	visit[idx] = true;
	dfs(idx+1, cnt+1);
	visit[idx] = false;
}

int main()
{
	int t;

	cin >> t;
	while (t--) {
		cin >> n;
		ans = 1e9+1;
		for (int i=0; i<n; ++i)
			cin >> x[i] >> y[i];

		dfs(0, 0);

		cout << fixed << setprecision(6) << ans << '\n';
	}

	return 0;
}
