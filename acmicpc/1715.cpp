#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	priority_queue<int, vector<int>, greater<int>> que;
	int n, val, a, b, sum = 0;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", &val);
		que.push(val);
	}

	while (que.size() != 1) {
		a = que.top();
		que.pop();
		b = que.top();
		que.pop();
		sum += a + b;
		que.push(a + b);
	}

	printf("%d\n", sum);

	return 0;
}
