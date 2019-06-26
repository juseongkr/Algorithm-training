#include <iostream>
using namespace std;
#define MAX 10001

int main()
{
	int n, ans = 0;

	cin >> n;
	for (int i=1; i<=n; ++i) {
		for (int j=i; i*j<=n; ++j)
			ans++;
	}

	cout << ans << '\n';

	return 0;
}
