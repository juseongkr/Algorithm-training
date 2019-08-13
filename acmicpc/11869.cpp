#include <iostream>
using namespace std;

int main()
{
	int m, p;

	cin >> m;
	int ans = 0;
	for (int i=0; i<m; ++i) {
		cin >> p;
		ans ^= p;
	}
	if (ans)
		cout << "koosaga\n";
	else
		cout << "cubelover\n";

	return 0;
}
