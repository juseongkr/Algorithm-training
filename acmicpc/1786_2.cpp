#include <iostream>
#include <vector>
using namespace std;
#define MOD 2147483647
#define BASE 26

vector<int> ans;

long long hashing(string s)
{
	long long ret = 0;
	for (int i=0; i<s.length(); ++i)
		ret = (ret * BASE + s[i]) % MOD;
	return ret;
}

void match(string a, string b)
{
	if (a.length() < b.length())
		return;

	long long hashing_b = hashing(b);
	long long hashing_a = hashing(a.substr(0, b.length()));

	long long first = 1;
	for (int i=0; i<b.length()-1; ++i)
		first = (first * BASE) % MOD;

	for (int i=0; i<=a.length()-b.length(); ++i) {
		if (hashing_a == hashing_b)
			ans.push_back(i+1);

		if (i + b.length() < a.length()) {
			hashing_a = hashing_a - (a[i] * first) % MOD;
			hashing_a = (hashing_a + MOD) % MOD;
			hashing_a = ((hashing_a * BASE) % MOD + a[i+b.length()]) % MOD;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string a, b;

	getline(cin, a);
	getline(cin, b);

	match(a, b);

	cout << ans.size() << '\n';
	for (int i=0; i<ans.size(); ++i)
		cout << ans[i] << " ";

	return 0;
}
