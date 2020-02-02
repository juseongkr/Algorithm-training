#include <iostream>
#include <set>
using namespace std;
#define MAX 1000000000

int t, n, s, k, p;
set<int> st;

int main()
{
	cin >> t;
	while (t--) {
		st.clear();
		cin >> n >> s >> k;
		for (int i=0; i<k; ++i) {
			cin >> p;
			st.insert(p);
		}

		int x = MAX, y = MAX, idx = 0;
		for (int i=s; i<=n; ++i, idx++) {
			if (!st.count(i)) {
				x = idx;
				break;
			}
		}

		idx = 0;
		for (int i=s; i>=1; i--, idx++) {
			if (!st.count(i)) {
				y = idx;
				break;
			}
		}

		cout << min(x, y) << '\n';
	}

	return 0;
}
