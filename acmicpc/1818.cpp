#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 200001

int main()
{
	int num[MAX];
	int n, t, len = 0;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> t;
		int it = lower_bound(num, num+len, t) - num;
		if (it == len)
			len++;
		num[it] = t;
	}
	cout << n - len << '\n';

	return 0;
}
