#include <iostream>
using namespace std;

int main()
{
	int s[1001];
	int num, val = 0, max_val = 0;
	
	cin >> num;
	for (int i=0; i<num; ++i)
		cin >> s[i];

	for (int i=0; i<num-1; ++i) {
		if (s[i] < s[i+1])
			val += s[i+1] - s[i];
		else
			val = 0;
		
		max_val = max(max_val, val);
	}

	cout << max_val << '\n';
	
	return 0;
}
