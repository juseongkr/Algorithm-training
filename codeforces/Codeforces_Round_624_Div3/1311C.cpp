#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
 
string s;
int T, n, m, k;
int ans[26];
 
int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
 
	cin >> T;
	while (T--) {
		cin >> n >> m >> s;
		vector<int> vec, d[26];
		fill(ans, ans+26, 0);
		for (int i=0; i<m; ++i) {
			cin >> k;
			vec.push_back(k-1);
		}
		vec.push_back(s.length()-1);

		for (int i=0; i<26; ++i)
			d[i].resize(s.length(), 0);
 
		d[s[0]-'a'][0]++;
		for (int i=1; i<s.length(); ++i) {
			for (int j=0; j<26; ++j)
				d[j][i] = d[j][i-1];
			d[s[i]-'a'][i]++;
		}
 
		for (int i=0; i<vec.size(); ++i)
			for (int j=0; j<26; ++j)
				ans[j] += d[j][vec[i]];
 
		for (int i=0; i<26; ++i)
			cout << ans[i] << " ";
		cout << '\n';
	}
 
	return 0;
}
