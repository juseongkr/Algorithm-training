#include <iostream>
using namespace std;

int main()
{
	int n, k, t, cnt = 0;
	int day[501] = {0, };

	cin >> n >> k;

	for (int i=0; i<n; ++i)
		cin >> day[i];

	for (int i=0; i<n-1; ++i) {
		if (day[i] + day[i+1] < k) {
			t = k - (day[i] + day[i+1]);
			day[i+1] += t;
			cnt += t;
		}
	}

	cout << cnt << '\n';
	for (int i=0; i<n; ++i)
		cout << day[i] << " ";
	cout << '\n';

	return 0;
}
