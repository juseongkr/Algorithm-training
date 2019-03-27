#include <iostream>
using namespace std;

int main()
{
	int num, val;
	cin >> num;

	for (int i=0; i<num; ++i) {
		cin >> val;
		cout << val / 2 << '\n';
	}

	return 0;
}
