#include <stdio.h>
#include <queue>

int main()
{
	std::priority_queue<int> q;
	int num, tmp;
	long double max, sum = 0;

	scanf("%d", &num);

	for (int i=0; i<num; ++i) {
		scanf("%d", &tmp);
		q.push(tmp);
	}
	
	max = q.top();
	while (!q.empty()) {
		sum += (q.top() / max) * 100;
		q.pop();
	}
	sum /= num;

	printf("%.2Lf\n", sum);

	return 0;
}
