#include <iostream>
#include <deque>
using namespace std;

int n, k;
deque<pair<int, int>> deq;

int main()
{
	cin >> n;
	for (int i=1; i<=n; ++i) {
		cin >> k;
		deq.push_back({k, i});
	}

	int next = deq.front().first;
	cout << deq.front().second << ' ';
	deq.pop_front();

	while (!deq.empty()) {
		if (next > 0) {
			for (int i=0; i<next; ++i) {
				auto t = deq.front();
				deq.push_back(t);
				deq.pop_front();
			}
			next = deq.back().first;
			cout << deq.back().second << ' ';
			deq.pop_back();
		} else {
			for (int i=0; i<abs(next); ++i) {
				auto t = deq.back();
				deq.push_front(t);
				deq.pop_back();
			}
			next = deq.front().first;
			cout << deq.front().second << ' ';
			deq.pop_front();
		}
	}

	return 0;
}
