#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001

int main()
{
	int n, a[MAX], b[MAX];
	bool flag = true;

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];

	for (int i=0; i<n; ++i)
		cin >> b[i];

	sort(a, a+n);
	sort(b, b+n);

	for (int i=0; i<=n/2; ++i)
		if (a[i] >= b[i+n/2])
			flag = false;

	if (flag)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}
