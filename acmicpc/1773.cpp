#include <iostream>
using namespace std;

int main()
{
	int num[101], time[2000001];
	int n, c, ans = 0;

	cin >> n >> c;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	fill(time, time+c+1, 0);
	for (int i=0; i<n; ++i) {
		for (int j=1; j*num[i]<=c; ++j) {
			if (time[j*num[i]] == 0) {
				time[j*num[i]] = 1;
				ans++;
			}
		}
	}
	cout << ans << '\n';

	return 0;
}
