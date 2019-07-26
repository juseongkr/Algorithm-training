#include <iostream>
using namespace std;
#define MOD 1000007
#define BASE 256

int hashing(string s)
{
	int ret = 0;
	for (int i=0; i<s.length(); ++i)
		ret = (ret * BASE + s[i]) % MOD;
	return ret;
}

bool match(string a, string b)
{
	if (a.length() < b.length())
		return false;

	int hashing_b = hashing(b);
	int hashing_a = hashing(a.substr(0, b.length()));

	int first = 1;
	for (int i=0; i<b.length()-1; ++i)
		first = (first * BASE) % MOD;

	for (int i=0; i<=a.length()-b.length(); ++i) {
		if (hashing_a == hashing_b)
			if (a.substr(i, b.length()) == b)
				return true;
		if (i + b.length() < a.length()) {
			hashing_a = hashing_a - (a[i] * first) % MOD;
			hashing_a = (hashing_a + MOD) % MOD;
			hashing_a = ((hashing_a * BASE) % MOD + a[i+b.length()]) % MOD;
		}
	}
	return false;
}

int main()
{
	string a, b;

	cin >> a >> b;

	cout << match(a, b) << '\n';

	return 0;
}
