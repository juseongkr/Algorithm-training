#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int num, val;
	queue<int> que;
	string str;
	cin >> num;

	for (int i=0; i<num; ++i) {
		cin >> str;
		if (str == "push") {
			cin >> val;
			que.push(val);
		} else if (str == "pop") {
			if (que.empty()) {
				cout << "-1\n";
			} else {
				cout << que.front() << '\n';
				que.pop();
			}
		} else if (str == "size") {
			cout << que.size() << '\n';
		} else if (str == "empty") {
			if (que.empty())
				cout << "1\n";
			else
				cout << "0\n";
		} else if (str == "front") {
			if (que.empty())
				cout << "-1\n";
			else
				cout << que.front() << '\n';
		} else if (str == "back") {
			if (que.empty())
				cout << "-1\n";
			else
				cout << que.back() << '\n';
		}
	}

	return 0;
}

