#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int t, n;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		int sum = 0;
		cin >> n >> s;
		if (n == 1) {
			cout << "-1\n";
			continue;
		}

		vector<char> ans;
		while ((s.back()-'0') % 2 == 0 && s.length() != 0)
			s.pop_back();

		if (s.length() == 0) {
			cout << "-1\n";
			continue;
		}

		bool flag = false;
		for (int i=s.length()-1; i>=0; i--) {
			sum += s[i]-'0';
			ans.push_back(s[i]);
			if (sum % 2 == 0 && sum != 0) {
				flag = true;
				break;
			}
		}

		if (flag) {
			for (int i=ans.size()-1; i>=0; i--)
				cout << ans[i];
			cout << '\n';
		} else {
			cout << "-1\n";
		}
	}

	return 0;
}
