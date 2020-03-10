#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 101

int num[MAX];
int T, n;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		for (int i=0; i<n; ++i)
			cin >> num[i];

		sort(num, num+n);

		for (int i=n-1; i>=0; i--)
			cout << num[i] << " ";
		cout << '\n';
	}

	return 0;
}
