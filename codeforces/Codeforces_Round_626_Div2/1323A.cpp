#include <iostream>
using namespace std;
#define MAX 101

int T, n;
int num[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		bool flag = false;
		int ans = 0;
		for (int i=0; i<n; ++i) {
			cin >> num[i];
			if (num[i] % 2 == 0) {
				flag = true;
				ans = i+1;
			}
		}
		if (flag) {
			cout << "1\n" << ans << '\n';
			continue;
		}

		int l = 0, r = 0;
		for (int i=0; i<n; ++i) {
			int sum = num[i];
			for (int j=i+1; j<n; ++j) {
				sum += num[j];
				if (sum % 2 == 0) {
					ans = j-i+1;
					l = i+1;
					r = j+1;
					break;
				}
			}
		}

		if (ans == 0) {
			cout << "-1\n";
		} else {
			cout << ans << '\n';
			cout << l << " " << r << '\n';
		}
	}

	return 0;
}
