#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n, m;
	queue<int> que;

	cin >> n >> m;

	for (int i=1; i<=n; ++i)
		que.push(i);

	cout << '<';
	while (que.size() != 1) {
		for (int i=0; i<m-1; ++i) {
			que.push(que.front());
			que.pop();
		}
		cout << que.front() << ", ";
		que.pop();
	}
	cout << que.front() << ">\n";

	return 0;
}
