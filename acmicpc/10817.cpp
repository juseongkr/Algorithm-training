#include <stdio.h>
#include <queue>

int main()
{
	std::priority_queue<int> q;
	int num;

	for (int i=0; i<3; ++i) {
		scanf("%d", &num);
		q.push(num);
	}

	q.pop();
	printf("%d\n", q.top());

	return 0;
}
