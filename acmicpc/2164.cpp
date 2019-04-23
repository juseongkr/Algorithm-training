#include <iostream>
#include <deque>
using namespace std;

int main()
{
	deque<int> q;
	int n;

	scanf("%d", &n);
	for (int i=1; i<=n; ++i)
		q.push_back(i);

	while (q.size() != 1) {
		q.pop_front();
		int t = q.front();
		q.pop_front();
		q.push_back(t);
	}

	printf("%d\n", q.front());

	return 0;
}
