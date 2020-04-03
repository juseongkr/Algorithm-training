#include <iostream>
#include <vector>
using namespace std;
#define MOD 998244353

int n, k, num;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	vector<int> vec;
	long long sum = 0;
	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> num;
		if (num > n-k) {
			vec.push_back(i+1);
			sum += num;
		}
	}

	cout << sum << '\n';
	long long ans = 1;
	for (int i=0; i<vec.size()-1; ++i)
		ans = ans * (vec[i+1] - vec[i]) % MOD;

	cout << ans % MOD << '\n';

	return 0;
}
