#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1001

int main()
{
	vector<int> x, y;
	int a[MAX], b[MAX];
	int n, m;
	long long t;

	cin >> t >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	cin >> m;
	for (int i=0; i<m; ++i)
		cin >> b[i];

	for (int i=0; i<n; ++i) {
		int sum = a[i];
		x.push_back(sum);
		for (int j=i+1; j<n; ++j) {
			sum += a[j];
			x.push_back(sum);
		}
	}

	for (int i=0; i<m; ++i) {
		int sum = b[i];
		y.push_back(sum);
		for (int j=i+1; j<m; ++j) {
			sum += b[j];
			y.push_back(sum);
		}
	}

	sort(y.begin(), y.end());

	long long ans = 0;
	for (int i=0; i<x.size(); ++i) {
		int high = upper_bound(y.begin(), y.end(), t - x[i]) - y.begin();
		int low = lower_bound(y.begin(), y.end(), t - x[i]) - y.begin();
		ans += (high - low);
	}
	cout << ans << '\n';

	return 0;
}
