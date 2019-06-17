#include <iostream>
using namespace std;

int main()
{
	double a, b, c, d, max = 0;
	int ans;

	cin >> a >> b >> c >> d;
	for (int i=0; i<4; ++i) {
		double val;
		if (i == 0)
			val = a/c + b/d;
		else if (i == 1)
			val = c/d + a/b;
		else if (i == 2)
			val = d/b + c/a;
		else
			val = b/a + d/c;
		if (max < val) {
			max = val;
			ans = i;
		}
	}
	cout << ans << '\n';

	return 0;
}
