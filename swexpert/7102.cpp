#include <iostream>
using namespace std;

int main()
{
	int t, a, b;

	cin >> t;
	for (int i=1; i<=t; ++i) {
		cin >> a >> b;

		int dict[41];
		fill(dict, dict+41, 0);
		for (int j=1; j<=a; ++j)
			for (int k=1; k<=b; ++k)
				dict[j+k]++;

		int val = 0;
		for (int j=0; j<41; ++j)
			val = max(val, dict[j]);

		cout << "#" << i << " ";
		for (int j=0; j<41; ++j)
			if (dict[j] == val)
				cout << j << " ";
		cout << '\n';
	}

	return 0;
}
