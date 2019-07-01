#include <iostream>
using namespace std;
#define MAX 80001

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	bool num[MAX];
	int sum[MAX];
	int t, n;

	cin >> t;
	fill(num, num+MAX, false);
	for (int i=3; i<=MAX; ++i)
		if (i % 3 == 0 || i % 7 == 0)
			num[i] = true;

	for (int i=1; i<=MAX; ++i) {
		if (num[i])
			sum[i] = sum[i-1] + i;
		else
			sum[i] = sum[i-1];
	}

	for (int i=0; i<t; ++i) {
		cin >> n;
		cout << sum[n] << '\n';
	}

	return 0;
}
