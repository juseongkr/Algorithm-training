#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	priority_queue<int, vector<int>, greater<int>> room;
	pair<int, int> time[200002];
	int n;

	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d %d", &time[i].first, &time[i].second);

	sort(time, time + n);
	
	room.push(time[0].second);
	for (int i=1; i<n; ++i) {
		if (room.top() <= time[i].first) {
			room.pop();
			room.push(time[i].second);
		} else {
			room.push(time[i].second);
		}
	}

	printf("%lu\n", room.size());

	return 0;
}
