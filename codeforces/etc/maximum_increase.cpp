#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<long long> a;
	long long temp;
	int num, max_val = 1, cnt = 1;
	cin >> num;

	for (int i=0; i<num; ++i) {
		cin >> temp;
		a.push_back(temp);
	}

	for (int i=0; i<a.size()-1; ++i) {
		if (a[i] < a[i+1])
			cnt++;
		else
			cnt = 1;
		max_val = max(max_val, cnt);
	}
	
	cout << max_val << '\n';

	return 0;
}
