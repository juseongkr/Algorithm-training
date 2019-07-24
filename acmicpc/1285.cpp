#include <iostream>
using namespace std;
#define MAX 21

int main()
{
	int n;
	string s[MAX];

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> s[i];

	int ans = n*n;
	for (int k=0; k<(1<<n); ++k) {
		int sum = 0;
		for (int i=0; i<n; ++i) {
			int cnt = 0;
			for (int j=0; j<n; ++j) {
				int t = s[j][i];
				if (k & (1 << j)) {
					if (t == 'T')
						t = 'H';
					else
						t = 'T';
				}
				if (t == 'T')
					cnt++;
			}
			sum += min(cnt, n-cnt);
		}
		ans = min(ans, sum);
	}
	cout << ans << '\n';

	return 0;
}
