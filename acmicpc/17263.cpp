#include <iostream>
#include <queue>
using namespace std;

int main()
{
	priority_queue<int> que;
	int n, t;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> t;
		que.push(t);
	}

	cout << que.top();

	return 0;
}
