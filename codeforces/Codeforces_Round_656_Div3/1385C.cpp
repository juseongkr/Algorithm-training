#include <iostream>
using namespace std;
#define MAX 200001

int T, n;
int x[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		int prev = -1;
		bool flag = true;
		for (int i=0; i<n; ++i) {
			cin >> x[i];
			if (prev > x[i])
				flag = false;
			prev = x[i];
		}

		if (flag) {
			cout << "0\n";
			continue;
		}

		int cur = 0, ans = 0;
		flag = true;
		for (int i=n-1; i>=0; i--) {
			if (flag) {
				if (x[i] >= cur) {
					cur = x[i];
				} else {
					cur = x[i];
					flag = false;
				}
			} else {
				if (x[i] <= cur) {
					cur = x[i];
				} else {
					ans = i+1;
					break;
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
