#include <iostream>
#include <queue>
using namespace std;

int main()
{
	priority_queue<int> que;
	int n, m;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", &m);
		if (m == 0) {
			if (que.empty()) {
				printf("0\n");
			} else { 
				printf("%d\n", que.top());
				que.pop();
			}
		} else {
			que.push(m);
		}
	}
	return 0;
}
