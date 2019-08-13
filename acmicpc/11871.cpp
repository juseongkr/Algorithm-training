#include <iostream>
using namespace std;

int main()
{
	int n, p;

	cin >> n;
	int ans = 0;
	for (int i=0; i<n; ++i) {
		cin >> p;
		if (p % 2 == 0)
			p = (p/2)-1;
		else
			p = (p+1)/2;
		ans ^= p;
	}

	if (ans)
		cout << "koosaga\n";
	else
		cout << "cubelover\n";

	return 0;
}
