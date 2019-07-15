#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, t;

	cin >> n;
	int sum = 1;
	for (int i=0; i<n; ++i) {
		cin >> t;
		sum += t;
	}
	cout << sum - n << '\n';

	return 0;
}
