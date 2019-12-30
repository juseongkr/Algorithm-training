#include <iostream>
#include <algorithm>
using namespace std;

int x[3];

int main()
{
	int t;

	cin >> t;
	while (t--) {
		cin >> x[0] >> x[1] >> x[2];
		sort(x, x+3);
		cout << min(x[0]+x[1], (x[0]+x[1]+x[2])/2) << '\n';
	}

	return 0;
}
