#include <iostream>
using namespace std;

int main()
{
	int t, n;
	
	scanf("%d", &t);

	for (int i=0; i<t; ++i) {
		scanf("%d", &n);

		for (int j=0; j<30; ++j) {
			if (n & (1 << j))
				printf("%d ", j);
		}
	}

	return 0;
}
