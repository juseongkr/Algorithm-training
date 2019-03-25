#include <iostream>
#include <deque>
using namespace std;

int main()
{
	deque<int> que;
	int n, m, p, val;
	int head, tail, cnt = 0;

	scanf("%d %d", &n, &m);
	for (int i=1; i<=n; ++i)
		que.push_back(i);

	head = 0;
	tail = que.size()-1;

	while (m--) {
		scanf("%d", &val);

		p = 1;
		for (auto it=que.begin(); it!=que.end(); ++it, ++p)
			if (*it == val)
				break;

		head = p - 1;
		tail = que.size() - p + 1;

		if (head < tail) {
			for (int i=0; i<head; ++i) {
				que.push_back(que.at(0));
				que.pop_front();
				cnt++;
			}
		} else {
			for (int i=0; i<tail; ++i) {
				que.push_front(que.at(que.size()-1));
				que.pop_back();
				cnt++;
			}
		}
		que.pop_front();
	}

	printf("%d\n", cnt);

	return 0;
}
