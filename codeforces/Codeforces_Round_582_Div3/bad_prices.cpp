#include <iostream>
using namespace std;
#define MAX 150001

int num[MAX];

int main()
{
	int t, n;

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=0; i<n; ++i)
			cin >> num[i];

		int ans = 0;
		int mn = num[n-1];
		for (int i=n-1; i>=0; i--) {
			if (num[i] > mn)
				ans++;
			else
				mn = num[i];
		}
		cout << ans << '\n';
	}

	return 0;
}
