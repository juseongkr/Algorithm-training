#include <iostream>
using namespace std;
#define MAX 3001

int main()
{
	int num[MAX], visit[MAX];
	int n;

	while (scanf("%d", &n) != EOF) {
		bool flag = false;
		fill(visit, visit+MAX, 0);
		for (int i=0; i<n; ++i)
			cin >> num[i];

		for (int i=0; i<n-1; ++i) {
			int t = abs(num[i]-num[i+1]);
			if (t == 0 || t >= n || visit[t]) {
				flag = true;
				break;
			}
			visit[t] = 1;
		}
		if (flag)
			cout << "Not jolly\n";
		else
			cout << "Jolly\n";
	}

	return 0;
}
