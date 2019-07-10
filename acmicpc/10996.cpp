#include <iostream>
using namespace std;

int main()
{
	int n;

	cin >> n;
	for (int i=0; i<n*2; ++i) {
		for (int j=0; j<n; ++j) {
			if (i % 2 == 0) {
				if (j % 2 == 0)
					cout << "*";
				else
					cout << " ";
			} else {
				if (j % 2 == 0)
					cout << " ";
				else
					cout << "*";
			}
		}
		cout << '\n';
	}

	return 0;
}
