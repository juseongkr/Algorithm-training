#include <iostream>
#include <algorithm>
using namespace std;

int num[200001], arr[200001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, sum = 0;

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> num[i];

		arr[i] = num[i];
		sum += num[i];
		sort(arr, arr+i);

		if (sum > m) {
			int time = sum;
			int ans = 0;

			for (int j=i-1; j>=0; j--) {
				ans++;
				time -= arr[j];
				if (time <= m) {
					cout << ans << " ";
					break;
				}
			}
		} else {
			cout << "0 ";
		}
	}

	return 0;
}
