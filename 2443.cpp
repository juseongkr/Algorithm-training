#include <iostream>
using namespace std;

int main()
{	
	int n;

	cin >> n;
	for (int i=n-1; i>=0; i--) {
		for (int j=1; j<=n+i; ++j) {
			if (n > i + j)
				cout << " ";
			else
				cout << "*";
		}
		cout << '\n';
	}

	return 0;
}
