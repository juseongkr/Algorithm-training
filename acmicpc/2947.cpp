#include <iostream>
using namespace std;

int n, num[5];

void print()
{
	for (int i=0; i<5; ++i)
		cout << num[i] << " ";
	cout << '\n';
}

int main()
{
	for (int i=0; i<5; ++i)
		cin >> num[i];

	while (1) {
		bool flag = true;
		for (int i=0; i<4; ++i) {
			if (num[i] > num[i+1]) {
				flag = false;
				swap(num[i], num[i+1]);
				print();
			}
		}

		if (flag)
			break;
	}

	return 0;
}
