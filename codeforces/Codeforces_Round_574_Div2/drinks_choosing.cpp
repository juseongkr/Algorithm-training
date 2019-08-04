#include <iostream>
using namespace std;
#define MAX 1001

int num[MAX];

int main()
{
	int n, k, t;

	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> t;
		num[t]++;
	}

	int cnt = 0;
	for (int i=1; i<=k; ++i)
		if (num[i] % 2 != 0)
			cnt++;

	cout << n - cnt/2 << '\n';

	return 0;
}
