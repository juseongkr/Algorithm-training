#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001

int num[MAX];

int main()
{
	int t, n;

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=0; i<n; ++i)
			cin >> num[i];

		sort(num, num+n);

		cout << min(num[n-2]-1, n-2) << '\n';
	}

	return 0;
}
