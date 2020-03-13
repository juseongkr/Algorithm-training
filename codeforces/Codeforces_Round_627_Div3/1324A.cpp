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
		int mx = 0;
		cin >> n;
		for (int i=0; i<n; ++i) {
			cin >> num[i];
			mx = max(mx, num[i]);
		}

		bool flag = true;
		for (int i=0; i<n; ++i) {
			if ((mx - num[i]) % 2 != 0) {
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
