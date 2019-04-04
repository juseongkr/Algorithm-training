#include <iostream>
#include <queue>
using namespace std;

int main()
{
	priority_queue<int> que;
	int n, v;
	
	scanf("%d", &n);
	for (int i=0; i<n*n; ++i) {
		scanf("%d", &v);
		que.push(v * -1);
		if (que.size() > n)
			que.pop();
	}

	printf("%d\n", que.top() * -1);

	return 0;
}
