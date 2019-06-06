#include <iostream>
using namespace std;

int main()
{
	int n;

	cin >> n;
	for (int i=1; i<=n; ++i) {
		for (int j=i; j<n; ++j)
			cout << " ";
		for (int j=1; j<i*2; ++j) {
			if (j == 1 || j == i*2-1)
				cout << "*";
			else
				cout << " ";
		}
		cout << '\n';
	}

	return 0;
}
