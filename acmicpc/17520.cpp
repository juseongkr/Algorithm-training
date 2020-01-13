#include <iostream>
using namespace std;
#define MOD 16769023

int n;

int main()
{
	cin >> n;
	int ans = 1;
	for (int i=0; i<(n+1)/2; ++i) {
		ans *= 2;
		ans %= MOD;
	}
	cout << ans << '\n';

	return 0;
}
