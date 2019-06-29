#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

pair<int, int> s;

double dist(pair<int, int> a, pair<int, int> b)
{
	return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

int main()
{
	pair<int, int> p[3];
	double ans = 10000;

	cin >> s.first >> s.second;
	for (int i=0; i<3; ++i)
		cin >> p[i].first >> p[i].second;

	for (int i=0; i<3; ++i)
		for (int j=0; j<3; ++j)
			for (int k=0; k<3; ++k)
				if (i != j && j != k && i != k)
					ans = min(ans, dist(s, p[i]) + dist(p[i], p[j]) + dist(p[j], p[k]));
	
	cout << int(ans) << '\n';

	return 0;
}
