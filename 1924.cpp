#include <iostream>
using namespace std;

int main()
{
	string day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	int m, d, cnt = 0;

	cin >> m >> d;

	for (int i=1; i<m; ++i) {
		if (i == 4 || i == 6 || i == 9 || i == 11)
			cnt += 30;
		else if (i == 2)
			cnt += 28;
		else
			cnt += 31;
	}
	cnt += d;
	cout << day[cnt % 7] << '\n';

	return 0;
}
