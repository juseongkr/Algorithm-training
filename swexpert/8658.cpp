#include <iostream>
using namespace std;
const int INF = 1e9+7;

int main()
{
	int t;
	string s;

	cin >> t;
	for (int T=1; T<=t; ++T) {
		int mi = INF, mx = 0;
		for (int i=0; i<10; ++i) {
			int num = 0;
			cin >> s;
			for (int j=0; j<s.length(); ++j)
				num += s[j]-'0';

			mi = min(mi, num);
			mx = max(mx, num);
		}
		cout << "#" << T << " " << mx << " " << mi << '\n';
	}

	return 0;
}
