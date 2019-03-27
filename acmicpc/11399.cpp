#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int arr[1001] = {0, };
	int n, ret = 0;

	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d", &arr[i]);

	sort(arr, arr + n);

	for (int i=0; i<n; ++i)
		ret += arr[i] * (n-i);

	printf("%d\n", ret);

	return 0;
}
