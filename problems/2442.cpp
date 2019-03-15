#include <iostream>
using namespace std;

int main()
{
	int num;

	cin >> num;

	for (int i=1; i<=num; ++i) {
		for (int j=1; j<num + i; ++j) {
			if (i + j > num)
				cout << "*";
			else
				cout << " ";
		}
		cout << '\n';
	}

	return 0;
}
