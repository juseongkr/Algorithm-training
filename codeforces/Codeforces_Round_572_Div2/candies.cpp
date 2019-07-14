#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001

int main()
{
	int n, q, l, r;
	int num[MAX];

	cin >> n;
	for (int i=1; i<=n; ++i)
		cin >> num[i];
	for (int i=1; i<=n; ++i)
		num[i] += num[i-1];

	cin >> q;
	while (q--) {
		cin >> l >> r;
		cout << (num[r] - num[l-1]) / 10 << '\n';
	}

	return 0;
}
