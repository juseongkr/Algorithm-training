#include <iostream>
using namespace std;

int main()
{
	int a[10], b[10];
	int x = 0, y = 0;

	for (int i=0; i<10; ++i)
		cin >> a[i];
	for (int i=0; i<10; ++i)
		cin >> b[i];

	for (int i=0; i<10; ++i) {
		if (a[i] > b[i])
			x++;
		if (a[i] < b[i])
			y++;
	}

	if (x > y)
		cout << "A\n";
	else if (x < y)
		cout << "B\n";
	else
		cout << "D\n";

	return 0;
}
