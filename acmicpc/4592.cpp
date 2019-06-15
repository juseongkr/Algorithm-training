#include <iostream>
using namespace std;

int main()
{
	int n, v;

	while (1) {
		int prev = 0;

		cin >> n;
		if (n == 0)
			break;

		for (int i=0; i<n; ++i) {
			cin >> v;
			if (prev != v)
				cout << v << " ";
			prev = v;
		}
		cout << "$\n";
	}

	return 0;
}
