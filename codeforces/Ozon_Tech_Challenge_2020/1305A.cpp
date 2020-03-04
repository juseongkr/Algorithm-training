#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define MAX 101

int T, n;
int a[MAX], b[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		for (int i=0; i<n; ++i)
			cin >> a[i];

		for (int i=0; i<n; ++i)
			cin >> b[i];

		sort(a, a+n);
		sort(b, b+n);

		for (int i=0; i<n; ++i)
			cout << a[i] << " ";
		cout << '\n';
		for (int i=0; i<n; ++i)
			cout << b[i] << " ";
		cout << '\n';
	}

	return 0;
}
