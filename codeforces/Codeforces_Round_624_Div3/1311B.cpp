#include <iostream>
using namespace std;
#define MAX 102

int T, n, m, k;
int num[MAX], p[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n >> m;
		fill(num, num+MAX, 0);
		fill(p, p+MAX, 0);
		for (int i=0; i<n; ++i)
			cin >> num[i];
		for (int i=0; i<m; ++i) {
			cin >> k;
			p[k-1] = 1;
		}

		bool ans = false;
		for (int j=0; j<n; ++j) {
			for (int i=0; i<n-1; ++i) {
				if (num[i] > num[i+1] && p[i])
					swap(num[i], num[i+1]);
			}

			bool flag = true;
			for (int i=0; i<n-1; ++i) {
				if (num[i] > num[i+1]) {
					flag = false;
					break;
				}
			}

			if (flag)
				ans = true;
		}
		if (ans)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
