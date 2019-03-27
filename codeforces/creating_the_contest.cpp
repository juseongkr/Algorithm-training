#include <iostream>
using namespace std;

int main()
{
	long long num, cur, prev = 0, cnt = 0, result = 0;

	cin >> num;
	for (long long i=0; i<num; ++i) {
		cin >> cur;
		if (prev * 2 >= cur)
			cnt++;
		else
			cnt = 1;
		
		result = max(result, cnt);
		prev = cur;
	}
	
	cout << result << '\n';

	return 0;
}
