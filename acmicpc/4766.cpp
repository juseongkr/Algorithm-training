#include <iostream>
using namespace std;

int main()
{
	double cur, prev, n;

	cin >> n;
	prev = n;
	while (1) {
		cin >> cur;
		if (cur == 999)
			break;
		printf("%.2f\n", cur - prev);
		prev = cur;
	}

	return 0;
}
