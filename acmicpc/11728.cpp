#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int arr[2000001];
	int n, m;

	scanf("%d %d", &n, &m);
	for (int i=0; i<n+m; ++i)
		scanf("%d", &arr[i]);

	sort(arr, arr+n+m);

	for (int i=0; i<n+m; ++i)
		printf("%d ", arr[i]);
	printf("\n");
	
	return 0;
}
