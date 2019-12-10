#include <iostream>
using namespace std;

int x, y;
long long ans;

int main()
{
	cin >> x >> y;
	if (x == y) {
		cout << "0\n";
		return 0;
	}

	int i = 1;
	while (1) {
		ans += (i+1)/2;
		if (ans >= y-x) {
			cout << i;
			return 0;
		}
		i++;
	}

	return 0;
}
