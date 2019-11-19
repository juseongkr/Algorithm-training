#include <iostream>
using namespace std;
#define MAX 184

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n;

	while (1) {
		cin >> n;
		if (n == 0)
			break;

		int ans = 0;
		for (int i=0; i<=MAX; ++i) {
			for (int j=i; j<=MAX; ++j) {
				for (int k=j; k<=MAX; ++k) {
					for (int p=k; p<=MAX; ++p) {
						if (i*i + j*j + k*k + p*p == n)
							ans++;
					}
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
