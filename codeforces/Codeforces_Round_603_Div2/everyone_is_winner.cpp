#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int t, n;

	cin >> t;
	while (t--) {
		set<int> st;
		cin >> n;
		st.insert(0);
		for (int i=1; i*i<=n; ++i) {
			st.insert(n/i);
			st.insert(i);
		}

		cout << st.size() << '\n';
		for (auto i : st)
			cout << i << ' ';
		cout << '\n';
	}

	return 0;
}
