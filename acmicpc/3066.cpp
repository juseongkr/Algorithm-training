#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 40001

int T, n, t;
int num[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		int len = 0;
		fill(num, num+MAX, 0);
		for (int i=1; i<=n; ++i) {
			cin >> t;
			auto it = lower_bound(num, num + len, t);
			if (it == num + len)
				len++;
			*it = t;
		}

		cout << len << '\n';
	}

	return 0;
}
