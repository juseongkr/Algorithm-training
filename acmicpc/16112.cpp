#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 300003

int n, k;
int stone[MAX];

int main()
{
	cin >> n >> k;
	for (int i=0; i<n; ++i)
		cin >> stone[i];

	sort(stone, stone+n);

	long long exp = 0, ans = 0;
	for (int i=n-1; i>=0; i--) {
		if (i < k)
			ans += exp;
		exp += stone[i];
	}
	cout << ans << '\n';

	return 0;
}
