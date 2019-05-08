#include <iostream>
using namespace std;

#define MAX 300001
int root[MAX], visit[MAX];

int find(int n)
{
	if (n == root[n])
		return n;
	root[n] = find(root[n]);
	return root[n];
}

void uni(int a, int b)
{
	int x = find(a);
	int y = find(b);
	root[x] = y;
	printf("LADICA\n");
}

int main()
{
	int n, l, a, b;

	scanf("%d %d", &n, &l);
	for (int i=1; i<=l; ++i)
		root[i] = i;

	for (int i=0; i<n; ++i) {
		scanf("%d %d", &a, &b);
		if (!visit[a]) {
			visit[a] = 1;
			uni(a, b);
		} else if (!visit[b]) {
			visit[b] = 1;
			uni(b, a);
		} else if (!visit[find(a)]) {
			visit[find(a)] = 1;
			uni(a, b);
		} else if (!visit[find(b)]) {
			visit[find(b)] = 1;
			uni(b, a);
		} else {
			printf("SMECE\n");
		}
	}

	return 0;
}
