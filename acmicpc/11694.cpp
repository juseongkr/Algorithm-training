#include <iostream>
using namespace std;

int main()
{
	int n, p;

	cin >> n;
	int ans = 0;
	bool flag = false;
	for (int i=0; i<n; ++i) {
		cin >> p;
		if (p == 1)
			flag = true;
		ans ^= p;
	}

	if (flag)
		ans--;

	if (ans)
		cout << "koosaga\n";
	else
		cout << "cubelover\n";

	return 0;
}
