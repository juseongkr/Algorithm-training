#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 200002

int n;
int a[MAX], b[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0; i<n; ++i)
		cin >>b[i];

	vector<int> vec;
	for (int i=0; i<n; ++i)
		vec.push_back(b[i] - a[i]);

	sort(vec.begin(), vec.end());

	long long ans = 0;
	for (int i=0; i<n; ++i) {
		int x = a[i] - b[i];
		auto it = lower_bound(vec.begin(), vec.end(), a[i]-b[i]) - vec.begin();
		if (a[i]-b[i] > b[i]-a[i])
			it--;
		ans += it;
	}
	cout << ans / 2 << '\n';

	return 0;
}
