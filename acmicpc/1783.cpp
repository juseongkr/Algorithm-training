#include <iostream>
using namespace std;

int main()
{
	int n, m, ans;

	scanf("%d %d", &n, &m);
	if (n == 1)
		ans = 1;
	else if (n == 2)
		ans = min((m+1)/2, 4);
	else if (n >= 3 && m >= 7)
		ans = m-2;
	else
		ans = min(m, 4);

	printf("%d\n", ans);

	return 0;
}
