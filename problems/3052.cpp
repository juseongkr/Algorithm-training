#include <iostream>
using namespace std;

int map[42];

int main()
{
	int num, cnt = 0;

	for (int i=0; i<10; ++i) {
		cin >> num;
		map[num%42]++;
	}

	for (int i=0; i<42; ++i) {
		if (map[i] != 0)
			cnt++;
	}

	cout << cnt << '\n';

	return 0;
}
