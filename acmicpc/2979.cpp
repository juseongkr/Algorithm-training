#include <iostream>
using namespace std;

int t[101];

int main()
{
	int a, b, c, x, y;

	cin >> a >> b >> c;
	for (int i=0; i<3; ++i) {
		cin >> x >> y;
		for (int j=x; j<y; ++j)
			t[j]++;
	}
	
	int ans = 0;
	for (int i=0; i<101; ++i) {
		if (t[i] == 1)
			ans += a * t[i];
		else if (t[i] == 2)
			ans += b * t[i];
		else if (t[i] == 3)
			ans += c * t[i];
	}
	cout << ans << '\n';

	return 0;
}
