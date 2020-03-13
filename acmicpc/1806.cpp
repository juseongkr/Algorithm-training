#include <iostream>
using namespace std;
#define MAX 100001

int n, s, l, r, sum, cnt;
int num[MAX];

int main()
{
	cin >> n >> s;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	int ans = MAX;
	while (l <= r && r <= n) {
		if (sum >= s) {
			ans = min(ans, r-l);
			sum -= num[l++];
			cnt++;
		} else {
			sum += num[r++];
		}
	}
	if (cnt)
		cout << ans << '\n';
	else
		cout << "0\n";

	return 0;
}
