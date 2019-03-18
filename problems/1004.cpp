#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int t, x1, x2, y1, y2, n, a, b, r, cnt;
	double dist1, dist2;

	scanf("%d", &t);
	for (int i=0; i<t; ++i) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf("%d", &n);
		cnt = 0;
		
		for (int j=0; j<n; ++j) {
			scanf("%d %d %d", &a, &b, &r);

			dist1 = sqrt(pow(double(x1 - a), 2) + pow(double(y1 - b), 2));
			dist2 = sqrt(pow(double(x2 - a), 2) + pow(double(y2 - b), 2));

			if (dist1 <= r && dist2 <= r)
				continue;
			else if (dist1 <= r)
				cnt++;
			else if (dist2 <= r)
				cnt++;
		}
		printf("%d\n", cnt);
	}

	return 0;
}
