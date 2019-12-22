#include <iostream>
using namespace std;
#define MAX 1000001

int num[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n, t, len = 0;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> t;
		num[t] = num[t-1] + 1;
		len = max(len, num[t]);
	}
	cout << n - len << '\n';

	return 0;
}
