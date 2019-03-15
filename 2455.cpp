#include <iostream>
using namespace std;

int main()
{
	int x, y, ret = 0, max_val = 0;

	for (int i=0; i<4; ++i) {
		cin >> x >> y;
		ret = ret - x + y;
		max_val = max(max_val, ret);
	}
	cout << max_val << '\n';

	return 0;
}
