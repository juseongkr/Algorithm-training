#include <iostream>
#include <vector>
using namespace std;

int T;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> s;
		vector<string> ans;
		for (int i=0; i<s.length(); ++i) {
			if (s[i] != '0') {
				string p;
				p += s[i];
				for (int j=0; j<s.length()-i-1; ++j)
					p += '0';
				ans.push_back(p);
			}
		}
		cout << ans.size() << '\n';
		for (int i=0; i<ans.size(); ++i)
			cout << ans[i] << " ";
		cout << '\n';
	}

	return 0;
}
