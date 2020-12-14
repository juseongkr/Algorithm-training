#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	pair<int, int> num[MAX];
	long long total = 0, sum = 0;
	int n, a, b;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a >> b;
		total += b;
		num[i] = {a, b};
	}

	sort(num, num+n);

	for (int i=0; i<n; ++i) {
		sum += num[i].second;
		if (sum * 2 >= total) {
			cout << num[i].first;
			break;
		}
	}

	return 0;
}
