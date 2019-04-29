#include <iostream>
using namespace std;

int main()
{
	int h, m, t;

	scanf("%d %d %d", &h, &m, &t);
	h += t/60;
	m += t%60;

	if (m >= 60) {
		h++;
		m %= 60;
	}
	if (h >= 24)
		h %= 24;

	printf("%d %d\n", h, m);

	return 0;
}
