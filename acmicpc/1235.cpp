#include <iostream>
#include <set>
using namespace std;

int main()
{
	int n, ans = 0;
	string s[1001];
	set<string> st;

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> s[i];

	int i = 0;
	int r = s[0].length();
	int l = s[0].length()-1;
	while (l && i < n) {
		string t = s[i].substr(l, r);
		if (st.count(t)) {
			i = 0;
			l--;
			ans++;
			st.clear();
		} else {
			i++;
			st.insert(t);
		}
	}

	cout << ans + 1 << '\n';

	return 0;
}
