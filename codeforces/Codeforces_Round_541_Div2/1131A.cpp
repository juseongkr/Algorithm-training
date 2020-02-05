#include <iostream>
using namespace std;

int w1, w2, h1, h2;

int main()
{
	cin >> w1 >> h1 >> w2 >> h2;

	int ans = (h1*2 + w1 + 2) + (h2*2 + w2 + 2);
	if (w1 > w2)
		ans += w1-w2;
	cout << ans << '\n';

	return 0;
}
