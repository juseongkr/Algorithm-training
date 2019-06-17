#include <iostream>
using namespace std;

bool num[10000001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, t;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> t;
		if (num[t-1]) {
			cout << t;
			break;
		} else {
			num[t-1] = true;
		}
	}

	return 0;
}
