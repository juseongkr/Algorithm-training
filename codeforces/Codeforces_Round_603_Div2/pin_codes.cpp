#include <iostream>
#include <map>
using namespace std;
#define MAX 11

int t, n;
map<string, int> mp;
string s[MAX], l[MAX];

string next(string p)
{
	string k = p;
	for (int i=0; i<4; ++i) {
		for (int j=0; j<10; ++j) {
			char temp = k[i];
			k[i] = '0' + j;
			if (mp[k])
				k[i] = temp;
			else
				return k;
		}
	}
	return "";
}

int main()
{
	cin >> t;
	while (t--) {
		int ans = 0;
		mp.clear();
		cin >> n;
		for (int i=0; i<n; ++i) {
			cin >> s[i];
			l[i] = s[i];
			mp[s[i]]++;
		}

		for (int i=0; i<n; ++i) {
			if (mp[s[i]] != 1) {
				mp[s[i]]--;
				ans++;
				l[i] = next(s[i]);
				mp[l[i]]++;
			}
		}

		cout << ans << '\n';
		for (int i=0; i<n; ++i)
			cout << l[i] << '\n';
	}

	return 0;
}
