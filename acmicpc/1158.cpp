#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> q;
	int n, m;

	scanf("%d %d", &n, &m);
	for (int i=1; i<=n; ++i)
		q.push(i);

	printf("<");
	while (q.size() != 1) {
		for (int i=1; i<m; ++i) {
			q.push(q.front());
			q.pop();
		}
		printf("%d, ", q.front());
		q.pop();
	}
	printf("%d>\n", q.front());

	return 0;
}
