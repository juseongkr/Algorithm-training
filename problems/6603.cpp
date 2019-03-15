#include <iostream>
using namespace std;

int arr[13];
int num[13];
int k;

void dfs(int start, int depth)
{
	if (depth == 6) {
		for (int i=0; i<6; ++i)
			printf("%d ", num[i]);
		printf("\n");
		return;
	}

	for (int i=start; i<k; ++i) {
		num[depth] = arr[i];
		dfs(i+1, depth+1);
	}
}

int main()
{
	while (scanf("%d", &k) && k != 0) {
		for (int i=0; i<k; ++i)
			scanf("%d", &arr[i]);

		dfs(0, 0);
		printf("\n");
	}

	return 0;
}
