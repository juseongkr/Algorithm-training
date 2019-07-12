#include <iostream>
using namespace std;

int main()
{
	int n, r, c;

	cin >> n >> r >> c;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			if ((i + j) % 2 == (r + c) % 2)
				cout << 'v';
			else
				cout << '.';
		}
		cout << '\n';
	}

	return 0;
}
