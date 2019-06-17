#include <iostream>
using namespace std;

int main()
{
	int t, b, c;
	char k;

	cin >> t;
	for (int l=1; l<=t; ++l) {
		cin >> b;
		cout << "Case #" << l << ": ";
		for (int i=0; i<b; ++i) {
			c = 0;
			for (int j=7; j>=0; j--) {
				cin >> k;
				if (k == 'I')
					c += (1 << j);
			}
			cout << char(c);
		}
		cout << '\n';
	}

	return 0;
}
