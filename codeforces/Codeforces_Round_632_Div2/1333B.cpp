#include <iostream>
using namespace std;
#define MAX 100001

int T, n;
int a[MAX], b[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
		
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i=0; i<n; ++i)
			cin >> a[i];

		for (int i=0; i<n; ++i)
			cin >> b[i];

		bool flag = true;
		int plus = 0, zero = 0, minus = 0;
		for (int i=0; i<n; ++i) {
			if (a[i] != b[i]) {
				if (b[i] > 0) {
					if (plus <= 0) {
						flag = false;
						break;
					}
				} else if (b[i] < 0) {
					if (minus <= 0) {
						flag = false;
						break;
					}
				} else {
					if (a[i] > 0) {
						if (minus <= 0) {
							flag = false;
							break;
						}
					} else { 
						if (plus <= 0) {
							flag = false;
							break;
						}
					}
				}
			}
			if (a[i] > 0)
				plus++;
			else if (a[i] < 0)
				minus++;
			else
				zero++;
		}
		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
