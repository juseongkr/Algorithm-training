#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) { return a > b; }

int main()
{
	int price[1001];
	int n, m, sum;

	cin >> n >> m;
	for (int i=0; i<m; ++i)
		cin >> price[i];

	sort(price, price+m, cmp);

	int ans = 0, total = 0;
	for (int i=0; i<m; ++i) {
		if (i+1 > n)
			sum = price[i] * n;
		else
			sum = price[i] * (i+1);
		if (total < sum) {
			total = sum;
			ans = price[i];
		}
	}

	cout << ans << ' ' << total << '\n';

	return 0;
}
