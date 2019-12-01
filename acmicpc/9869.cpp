#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 10001

int main()
{
	vector<int> vec[MAX];
	int n, x, y;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		vec[y-1].push_back(x);
	}

	priority_queue<int> que;

	int ans = 0;
	for (int i=MAX-1; i>=0; i--) {
		for (int j=0; j<vec[i].size(); ++j)
			que.push(vec[i][j]);

		if (que.empty())
			continue;

		ans += que.top();
		que.pop();
	}
	cout << ans << '\n';

	return 0;
}
