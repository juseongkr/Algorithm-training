#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, a, b, c;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a >> b >> c;
		cout << max(a-b, a-c) + 1 << '\n';
	}
	
	return 0;
}
