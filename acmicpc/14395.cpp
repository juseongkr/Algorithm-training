#include <iostream>
#include <queue>
#include <set>
using namespace std;
#define MAX 1000000000

int main()
{
	long long s, t;

	cin >> s >> t;

	set<long long> st;
	queue<pair<long long, string>> que;
	st.insert(s);
	que.push({s, ""});

	while (!que.empty()) {
		auto [x, str] = que.front();
		que.pop();

		if (x == t) {
			if (str == "")
				cout << "0\n";
			else
				cout << str << '\n';
			return 0;
		}

		if (0 <= x*x && x*x <= MAX && !st.count(x*x)) {
			que.push({x*x, str+"*"});
			st.insert(x*x);
		}

		if (0 <= x+x && x+x <= MAX && !st.count(x+x)) {
			que.push({x+x, str+"+"});
			st.insert(x+x);
		}

		if (0 <= x-x && x-x <= MAX && !st.count(x-x)) {
			que.push({x-x, str+"-"});
			st.insert(x-x);
		}

		if (x != 0 && x/x >= 0 && x/x <= MAX && !st.count(x/x)) {
			que.push({x/x, str+"/"});
			st.insert(x/x);
		}
	}
	cout << "-1\n";

	return 0;
}
