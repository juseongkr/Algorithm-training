#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int n;
double ans;

int main()
{
	cin >> n;
	for (int i=1; i<=n; ++i)
		ans += 1.0 / i;

	cout << fixed << setprecision(10) << ans << '\n';

	return 0;
}
