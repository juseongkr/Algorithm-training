#include <iostream>
#include <cmath>
using namespace std;

int dict[26];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, ans = 0;
	string s;
	
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> s;
		dict[s[0]-'a']++;
	}

	for (int i=0; i<26; ++i) {
		int a = dict[i]/2;
		int b = dict[i]-a;
		ans += a*(a-1)/2;
		ans += b*(b-1)/2;
	}

	cout << ans << '\n';

	return 0;
}
