#include <iostream>
#include <map>
using namespace std;
#define MAX 52

int n;
string s;
long long x, ans;
map<long long, int> dict;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> s;
	dict[0] = 1LL;
	for (int i=0; i<n; ++i) {
		if ('a' <= s[i] && s[i] <= 'z')
			x ^= (1LL << (s[i]-'a'));
		else
			x ^= (1LL << (s[i]-'A'+26));

		if (dict.count(x))
			ans += dict[x];

		for (int k=0; k<MAX; ++k)
			if (dict.count(x ^ (1LL << k)))
				ans += dict[x ^ (1LL << k)];

		dict[x]++;
	}
	cout << ans << '\n';

	return 0;
}
