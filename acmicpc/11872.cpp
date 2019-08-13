#include <iostream>
using namespace std;

int main()
{
	int n, p;

	cin >> n;
	int ans = 0;
	for (int i=0; i<n; ++i) {
		cin >> p;
		if (p % 4 == 0)
			p--;
		else if (p % 4 == 3)
			p++;
		ans ^= p;
	}
	if (ans)
		cout << "koosaga\n";
	else
		cout << "cubelover\n";

	return 0;
}
