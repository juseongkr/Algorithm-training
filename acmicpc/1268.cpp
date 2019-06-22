#include <iostream>
using namespace std;

int num[1001][6], know[1001];

int main()
{
	int n, ans, max = 0;

	cin >> n;
	for (int i=0; i<n; ++i)
		for (int j=0; j<5; ++j)
			cin >> num[i][j];

	for (int i=0; i<n; ++i) {
		int cnt = 0;
		for (int j=0; j<5; ++j) {
			for (int k=0; k<n; ++k) {
				if (num[i][j] == num[k][j])
					know[k]++;
			}
		}

		for (int j=0; j<n; ++j) {
			if (know[j]) {
				cnt++;
				know[j] = 0;
			}
		}

		if (max < cnt) {
			max = cnt;
			ans = i+1;
		}
	}
	cout << ans << '\n';

	return 0;
}
