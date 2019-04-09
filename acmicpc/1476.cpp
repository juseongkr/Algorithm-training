#include <iostream>
using namespace std;

int main()
{
	int e, s, m, year = 1;

	scanf("%d %d %d", &e, &s, &m);
	while (1) {
		int next_e = ((year-1) % 15) + 1;
		int next_s = ((year-1) % 28) + 1;
		int next_m = ((year-1) % 19) + 1;

		if (e == next_e && s == next_s && m == next_m) {
			printf("%d\n", year);
			break;
		}
		year++;
	}
	return 0;
}
