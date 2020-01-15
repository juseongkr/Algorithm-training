#include <iostream>
#include <unordered_set>
using namespace std;
#define MAX 2001

int n, k, ans;
string s[MAX];
unordered_set<string> st;

int main()
{
	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> s[i];
		st.insert(s[i]);
	}

	for (int i=0; i<n; ++i) {
		for (int j=i+1; j<n; ++j) {
			string t;
			for (int p=0; p<k; ++p) {
				if (s[i][p] == s[j][p]) {
					t += s[i][p];
				} else {
					string r = string() + s[i][p] + s[j][p];
					if (r == "SE" || r == "ES")
						t += 'T';
					else if (r == "ET" || r == "TE")
						t += 'S';
					else if (r == "ST" || r == "TS")
						t += 'E';
				}
			}
			if (st.count(t))
				ans++;
		}
	}
	cout << ans/3 << '\n';

	return 0;
}
