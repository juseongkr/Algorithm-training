#include <iostream>
#include <queue>
#include <tuple>
#include <set>
using namespace std;
#define MAX 201

int visit[MAX][MAX][MAX];

int main()
{
	queue<tuple<int, int, int>> que;
	set<int> s;
	int a, b, c;

	cin >> a >> b >> c;
	que.push({0, 0, c});
	while (!que.empty()) {
		auto [A, B, C] = que.front();
		que.pop();
		if (!visit[A][B][C]) {
			visit[A][B][C] = 1;

			if (A+C > a)
				que.push({a, B, A+C-a});
			else
				que.push({A+C, B, 0});
	
			if (A+C > c)
				que.push({A+C-c, B, c});
			else
				que.push({0, B, A+C});

			if (A+B > a)
				que.push({a, A+B-a, C});
			else
				que.push({A+B, 0, C});

			if (A+B > b)
				que.push({A+B-b, b, C});
			else
				que.push({0, A+B, C});

			if (B+C > b)
				que.push({A, b, B+C-b});
			else
				que.push({A, B+C, 0});
			
			if (B+C > c)
				que.push({A, B+C-c, C});
			else
				que.push({A, 0, B+C});
	
			if (!A)
				s.insert(C);
		}
	}

	for (auto it : s)
		cout << it << " ";

	return 0;
}
