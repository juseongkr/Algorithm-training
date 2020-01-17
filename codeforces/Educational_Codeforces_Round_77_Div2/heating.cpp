#include <iostream>
using namespace std;
#define MAX 10001

int n, x, y;
int num[MAX];

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		int ans = 0;
		fill(num, num+MAX, 0);
		for (int j=0; j<y; ++j)
			num[j%x]++;

		for (int j=0; j<y; ++j)
			ans += num[j] * num[j];

		cout << ans << '\n';
	}

	return 0;
}
