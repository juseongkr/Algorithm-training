#include <iostream>
using namespace std;

int main()
{
	int n, m, cnt = 0;

	scanf("%d" ,&n);
	for (int i=0; i<5; ++i) {
		scanf("%d", &m);
		if (m == n)
			cnt++;
	}

	printf("%d\n", cnt);
}
