#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
const long long BASE = 2;
const long long MOD = 1e16+7;

int n;
string s;

long long hashing(string s)
{
	long long ret = 0;
	for (int i=0; i<s.length(); ++i)
		ret = (ret * BASE + s[i]) % MOD;
	return ret;
}

bool match(int mid)
{
	unordered_set<long long> st;
	long long hash = hashing(s.substr(0, mid));

	long long first = 1;
	for (int i=0; i<mid-1; ++i)
		first = (first * BASE) % MOD;

	for (int i=0; i<=n-mid; ++i) {
		if (st.count(hash))
			return true;
		else
			st.insert(hash);

		if (i + mid < n) {
			hash = hash - (s[i] * first) % MOD;
			hash = (hash + MOD) % MOD;
			hash = ((hash * BASE) % MOD + s[i+mid]) % MOD;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> s;
	int l = 0, r = n;
	while (l+1 < r) {
		int mid = (l+r)/2;
		if (match(mid))
			l = mid;
		else
			r = mid;
	}
	cout << l << '\n';

	return 0;
}
