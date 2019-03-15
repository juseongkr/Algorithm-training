#include <iostream>
using namespace std;

int main()
{	
	int num, max_val = 0;
	int pos_x, pos_y;

	for (int i=1; i<=9; ++i) {
		for (int j=1; j<=9; ++j) {
			scanf("%d", &num);

			if (max_val < num) {
				max_val = num;
				pos_x = i;
				pos_y = j;
			}
		}
	}

	printf("%d\n", max_val);
	printf("%d %d\n", pos_x, pos_y);

	return 0;
}
