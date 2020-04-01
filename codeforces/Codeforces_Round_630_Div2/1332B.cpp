#include <iostream>
using namespace std;
#define MAX 1001
const int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

int T, n;
int num[MAX], used[MAX], ans[MAX];

int main()
{
	cin >> T;
	while (T--) {
		cin >> n;
		fill(used, used+MAX, 0);
		for (int i=0; i<n; ++i)
			cin >> num[i];

		int cnt = 0;
		for (int i=0; i<n; ++i) {
			for (int j=0; j<11; ++j) {
				if (num[i] % prime[j] == 0) {
					if (!used[j])
						used[j] = ++cnt;
					ans[i] = used[j];
					break;
				}
			}
		}

		cout << cnt << '\n';
		for (int i=0; i<n; ++i)
			cout << ans[i] << " ";
		cout << '\n';
	}

	return 0;
}
