#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int arr[10];
	int sum = 0, flag = 0;

	for (int i=0; i<9; ++i) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	
	sort(arr, arr + 9);

	for (int i=0; i<9; ++i) {
		for (int j=0; j<9; ++j) {
			if (i == j)
				continue;
			if (sum - (arr[i] + arr[j]) == 100) {
				arr[i] = 0;
				arr[j] = 0;
				flag = 1;
				break;
			}
		}
		if (flag)
			break;
	}

	for (int i=0; i<9; ++i)
		if (arr[i] != 0)
			printf("%d\n", arr[i]);

	return 0;
}
