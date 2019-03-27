#include <iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;
	
	cout << num / 2 << '\n';

	while (num > 3) {
		cout << "2 ";
		num -= 2;
	}

	cout << num << '\n';

	return 0;
}
