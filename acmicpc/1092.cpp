#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define MAX 51

int crain[MAX];

bool cmp(int a, int b) { return a > b; }

int main()
{
	int n, m, box, mx_box = 0;
	multiset<int> st;

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> crain[i];

	cin >> m;
	for (int i=0; i<m; ++i) {
		cin >> box;
		mx_box = max(mx_box, box);
		st.insert(box);
	}

	sort(crain, crain+n, cmp);
	if (mx_box > crain[0]) {
		cout << "-1\n";
		return 0;
	}

	int ans = 0;
	while (!st.empty()) {
		ans++;
		for (int i=n-1; i>=0; i--) {
			if (st.empty())
				break;

			auto it = st.find(crain[i]);
			if (it == st.end()) {
				it = st.lower_bound(crain[i]);
				if (it != st.begin())
					st.erase(--it);
			} else {
				st.erase(it);
			}
		}
	}
	cout << ans << '\n';

	return 0;
}
