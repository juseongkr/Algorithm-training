#include <iostream>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int t, a, b;

	cin >> t;
	while (t--) {
		cin >> a >> b;
 
		int d = abs(a-b);
		int i = 0;
		while (i * (i+1) / 2 < d)
			i++;

		while (d % 2 != i * (i+1) / 2 % 2)
			i++;

		cout << i << '\n';
	}
 
	return 0;
}
