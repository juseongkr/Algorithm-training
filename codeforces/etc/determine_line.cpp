#include <iostream>
using namespace std;

int main()
{
	int num, t, l;
	int array[1000] = {0, };

	cin >> num;
	for (int i=0; i<num; ++i) {
		cin >> t;
		for (int j=0; j<t; ++j) {
			cin >> l;
			array[l] += 1;
		}
	}

	for (int i=0; i<1000; ++i) {
		if (num == array[i])
			cout << i << " ";
	}
	cout << '\n';

	return 0;
}
