#include <iostream>
#include <queue>
using namespace std;

int n, k;
string s;
queue<int> que;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> s;
		if (s == "push") {
			cin >> k;
			que.push(k);
		} else if (s == "front") {
			if (que.empty())
				cout << "-1\n";
			else
				cout << que.front() << '\n';
		} else if (s == "back") {
			if (que.empty())
				cout << "-1\n";
			else
				cout << que.back() << '\n';
		} else if (s == "size") {
			cout << que.size() << '\n';
		} else if (s == "empty") {
			cout << que.empty() << '\n';
		} else {
			if (que.empty()) {
				cout << "-1\n";
			} else {
				cout << que.front() << '\n';
				que.pop();
			}
		}
	}

	return 0;
}
