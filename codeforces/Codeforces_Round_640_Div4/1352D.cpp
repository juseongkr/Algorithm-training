#include <iostream>
#include <deque>
using namespace std;
#define MAX 1001

int T, n;
int num;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		deque<int> deq;
		for (int i=0; i<n; ++i) {
			cin >> num;
			deq.push_back(num);
		}

		int prev = -1, cnt = 0, a = 0, b = 0;
		for (int i=0; i<n; ++i) {
			if (deq.empty())
				break;
			int cur = 0;
			if (i % 2 == 0) {
				do {
					cur += deq.front();
					deq.pop_front();
				} while (prev >= cur && !deq.empty());
				a += cur;
			} else {
				do {
					cur += deq.back();
					deq.pop_back();
				} while (prev >= cur && !deq.empty());
				b += cur;
			}
			prev = max(prev, cur);
			cnt++;
		}
		cout << cnt << " " << a << " " << b << '\n';
	}

	return 0;
}
