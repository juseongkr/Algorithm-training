#include <iostream>
#include <bitset>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	bitset<(1 << 25)> bit;
	int n;

	while (cin >> n) {
		if (!bit[n]) {
			bit[n] = 1;
			cout << n << " ";
		}
	}

	return 0;
}
