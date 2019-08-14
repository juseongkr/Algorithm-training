#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int m, n;

	cin >> m >> n;
	m = ceil(sqrt(m));
	n = floor(sqrt(n));

	int ans = 0;
	for (int i=m; i<=n; ++i)
		ans += i*i;

	if (ans)
		cout << ans << '\n' << m * m;
	else
		cout << "-1\n";

	return 0;
}
