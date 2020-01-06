#include <iostream>
using namespace std;

int main()
{
	int num;
	int array[4] = {0, };
	string str;

	cin >> num >> str;

	for (int i=0; i<num; ++i) {
		if (str[i] == 'L')
			array[0] += 1;
		else if (str[i] == 'R')
			array[1] += 1;
		else if (str[i] == 'U')
			array[2] += 1;
		else if (str[i] == 'D')
			array[3] += 1;
	}

	cout << min(array[0], array[1]) * 2 + min(array[2], array[3]) * 2 << '\n';

	return 0;
}
