#include <iostream>
using namespace std;

int main()
{
	int a, b, m, u, v;

	cin >> a >> b >> m;
	int ans = a/2 + b/2;
	for (int i=0; i<m; ++i) {
		cin >> u >> v;
		if (a % 2 && b % 2 && u % 2 && v % 2) {
			ans++;
			break;
		}
	}
	cout << ans << '\n';

	return 0;
}
