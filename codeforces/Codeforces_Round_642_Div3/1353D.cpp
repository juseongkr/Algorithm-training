#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 200001
typedef tuple<int, int, int, int> ti;

int T, n;
int a[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;

		priority_queue<ti> que;
		que.push({0, n-1, 0, n-1});
		fill(a, a+n, 0);

		int k = 0;
		while (!que.empty()) {
			auto [x, y, l, r] = que.top();
			que.pop();

			int mid = (l+r)/2;
			a[mid] = ++k;

			if (mid-l-1 >= 0)
				que.push({mid-l, n-l, l, mid-1});

			if (r-mid-1 >= 0)
				que.push({r-mid, n-r, mid+1, r});
		}

		for (int i=0; i<n; ++i)
			cout << a[i] << " ";
		cout << '\n';
	}

	return 0;
}
