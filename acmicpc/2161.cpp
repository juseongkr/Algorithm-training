#include <iostream>
#include <queue>
using namespace std;

int main()
{
	deque<int> que;
	int n;

	cin >> n;
	for (int i=1; i<=n; ++i)
		que.push_back(i);

	for (int i=0; i<n-1; ++i) {
		cout << que.front() << ' ';
		que.pop_front();
		que.push_back(que.front());
		que.pop_front();
	}
	cout << que.front() << '\n';

	return 0;
}
