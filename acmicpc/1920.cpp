#include <iostream>
#include <algorithm>
using namespace std;

int number[100001] = {0 ,};
int find[100001] = {0, };
int n, m;

int search(int find)
{
	int head = 0, mid, tail = n -1;

	while (1) {
		mid = (head + tail) / 2;
		
		if (number[head] == find)
			return 1;
		else if (number[mid] == find)
			return 1;
		else if (number[tail] == find)
		       return 1;

		if (number[mid] > find)
			tail = mid - 1;
		else
			head = mid + 1;

		if (tail <= head)
			return 0;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d", &number[i]);

	sort(number, number + n);

	scanf("%d", &m);
	for (int i=0; i<m; ++i) {
		int find;
		scanf("%d", &find);
		printf("%d\n", search(find));
	}

	return 0;
}
