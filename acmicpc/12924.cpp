#include <iostream>
#include <set>
using namespace std;

int a, b, ans;
set<int> st;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> a >> b;
	for (int i=a; i<=b; ++i) {
		string c = to_string(i);
		int n = c.length();
		st.clear();
		for (int j=1; j<n; ++j) {
			int t = stoi(c.substr(j, n-j) + c.substr(0, j));
			if (i < t && t <= b)
				st.insert(t);
		}
		ans += st.size();
	}
	cout << ans << '\n';

	return 0;
}
