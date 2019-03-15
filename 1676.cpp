#include <iostream>
using namespace std;

int main()
{
	int num, cnt = 0;
	
	cin >> num;

	while (num) {
		num /= 5;
		cnt += num;
	}

	cout << cnt << '\n';

	return 0;
}
