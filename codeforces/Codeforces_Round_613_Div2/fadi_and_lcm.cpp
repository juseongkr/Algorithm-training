#include <iostream>
using namespace std;
 
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
 
pair<long long, long long> ans;
long long n, a, b;
 
int main()
{
	cin >> n;

	ans = {1, n};
	long long mi = n;
	for (long long i=1; i*i<=n; ++i) {
		if (n % i == 0) {
			a = i, b = n/i;
			if (lcm(a, b) == n) {
				if (mi > max(a, b)) {
					ans = {a, b};
					mi = max(a, b);
				}
			}
		}
	}
	cout << ans.first << " " << ans.second << '\n';
 
	return 0;
}
