#include <iostream>
#include <queue>
using namespace std;
#define MAX 1000001

long long ans[MAX];
queue<long long> que;

int main()
{
	int n;

	cin >> n;
	if (n == 0) {
		cout << "0\n";
		return 0;
	}
	for (int i=1; i<10; ++i) {
		que.push(i);
		ans[i] = i;
	}

	int cnt = 9;
	while (cnt <= n) {
		if (que.empty())
			break;
		long long num = que.front();
		que.pop();

		for (int i=0; i<num%10; ++i) {
			long long next = num * 10 + i;
			que.push(next);
			ans[++cnt] = next;
		}
	}

	if (ans[n])
		cout << ans[n] << '\n';
	else
		cout << "-1\n";

	return 0;
}
