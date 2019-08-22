#include <iostream>
#include <set>
using namespace std;
#define MAX 11

int n, k;
int visit[MAX];
string card[MAX];
set<string> ans;

void solve(int t, string s)
{
	if (t == k) {
		ans.insert(s);
		return;
	}

	for (int i=0; i<n; ++i) {
		if (visit[i])
			continue;
		visit[i] = 1;
		solve(t+1, s + card[i]);
		visit[i] = 0;
	}
}

int main()
{
	cin >> n >> k;
	for (int i=0; i<n; ++i)
		cin >> card[i];

	solve(0, "");

	cout << ans.size() << '\n';

	return 0;
}
