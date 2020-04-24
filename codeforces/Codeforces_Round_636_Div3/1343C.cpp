#include <iostream>
using namespace std;
#define MAX 200001

int T, n;
long long num[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		for (int i=0; i<n; ++i)
			cin >> num[i];

		long long ans = 0, temp = num[0];
		for (int i=0; i<n-1; ++i) {
			temp = max(temp, num[i]);
			if ((num[i] > 0 && num[i+1] < 0) || (num[i] < 0 && num[i+1] > 0)) {
				ans += temp;
				temp = num[i+1];
			}
		}
		ans += max(num[n-1], temp);
		cout << ans << '\n';
	}

	return 0;
}
