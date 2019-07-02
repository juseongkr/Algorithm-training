#include <iostream>
using namespace std;

int main()
{
	int dict[10];
	int n, m;

	while (cin >> n >> m) {
		int cnt = 0;
		for (int i=n; i<=m; ++i) {
			fill(dict, dict+10, 0);
			string s = to_string(i);
			for (int j=0; j<s.length(); ++j) {
				int c = s[j]-'0';
				dict[c]++;
				if (dict[c] >= 2) {
					cnt++;
					break;
				}
			}
		}
		cout << m - n - cnt + 1 << '\n';
	}

	return 0;
}
