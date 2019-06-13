#include <iostream>
#include <queue>
using namespace std;

int main()
{
	priority_queue<int> que;
	int t, n;

	cin >> t;
	while (t--) {
		for (int i=0; i<10; ++i) {
			cin >> n;
			que.push(n);
		}

		for (int i=0; i<2; ++i)
			que.pop();

		cout << que.top() << '\n';

		while (!que.empty())
			que.pop();
	}

	return 0;
}
