#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1001

int num[MAX];

int main()
{

	int n, l;

	cin >> n >> l;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	sort(num, num+n);

	int ans = 1;
	int prev = num[0];
	for (int i=0; i<n; ++i) {
		if (num[i] - prev + 1 > l) {
			prev = num[i];
			ans++;
		}
	}

	cout << ans << '\n';

	return 0;
}
