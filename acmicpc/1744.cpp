#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int num[10001];
	int n, l, r, sum = 0;

	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d", &num[i]);

	sort(num, num + n);

	for (l=0; l<n-1; l+=2) {
		if (num[l] < 1 && num[l+1] < 1)
			sum += num[l] * num[l+1];
		else
			break;
	}

	for (r=n-1; r>0; r-=2) {
		if (num[r] > 1 && num[r-1] > 1)
			sum += num[r] * num[r-1];
		else 
			break;
	}

	for (int i=l; i<=r; i++)
		sum += num[i];

	printf("%d\n", sum);

	return 0;
}
