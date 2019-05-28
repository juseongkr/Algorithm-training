#include <iostream>
using namespace std;

int main()
{
	int t, n, m;

	cin >> t;
	while (t--) {
		int cnt = 0;
		cin >> n >> m;
		for (int i=n; i<=m; ++i) {
			int num = i;
			if (num == 0)
				cnt++;
			while (num) {
				if (num % 10 == 0)
					cnt++;
				num /= 10;
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}
