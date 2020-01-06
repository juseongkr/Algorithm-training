#include <iostream>
#include <queue>
using namespace std;

int main()
{	
	priority_queue<pair<int, int>> q;
	string bracket;
	int ret = 0;
	int cnt = 0;
	int open, close;

	cin >> bracket;

	if (bracket.size() % 2 != 0)
		return -1;

	for (int i=0; i<bracket.size(); ++i) {
		if (bracket[i] == '(') {
			cnt++;
		} else if (bracket[i] == ')') {
			cnt--;
		} else {
			cin >> open >> close;
			ret += close;
			bracket[i] = ')';
			cnt--;
			q.push({close - open, i});
		}
	}

	while (cnt < 0 && !q.empty()) {
		pair<int, int> temp = q.top();
		q.pop();
		ret -= temp.first;
		bracket[temp.second] = '(';
		cnt += 2;
	}

	cout << ret << '\n' << bracket << '\n';

	return 0;
}
