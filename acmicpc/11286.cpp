#include <iostream>
#include <queue>
using namespace std;

int main()
{
	priority_queue<pair<int, int>> que;
	int n, m;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", &m);
		if (m == 0) {
			if (que.empty()) {
				printf("0\n");
			} else {
				printf("%d\n", que.top().second * -1);
				que.pop();
			}
		} else {
			que.push({abs(m) * -1, m * -1});
		}
	}

	return 0;
}
