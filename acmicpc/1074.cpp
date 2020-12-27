#include <iostream>
#include <cmath>
using namespace std;

int n, r, c, pos, ans;

int main()
{
	cin >> n >> r >> c;
	for (int i=n, k=0; i>0; i--, c%=k, r%=k) {
		k = (2 << (i-1)) / 2;
		if (c >= k && r < k)
			pos = 1;
		else if (c < k && r >= k)
			pos = 2;
		else if (c >= k && r >= k)
			pos = 3;
		else
			pos = 0;

		ans += (k * k * pos);
	}

	cout << ans << '\n';

	return 0;
}
