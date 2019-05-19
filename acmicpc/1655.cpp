#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int, vector<int>, greater<int>> min_heap;
	priority_queue<int> max_heap;
	int n, t;

	cin >> n >> t;
	max_heap.push(t);
	cout << t << '\n';
	for (int i=1; i<n; ++i) {
		cin >> t;
		if (i % 2 != 0) {
			if (t > max_heap.top()) {
				min_heap.push(t);
			} else {
				max_heap.push(t);
				min_heap.push(max_heap.top());
				max_heap.pop();
			}
		} else {
			if (t < min_heap.top()) {
				max_heap.push(t);
			} else {
				min_heap.push(t);
				max_heap.push(min_heap.top());
				min_heap.pop();
			}
		}
		cout << max_heap.top() << '\n';
	}

	return 0;
}
