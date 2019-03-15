#include <iostream>
using namespace std;

int main()
{	
	int y_time = 0, m_time = 0;
	int num, time;
	
	cin >> num;
	for (int i=0; i<num; ++i) {
		cin >> time;
		y_time += (time/30) * 10 + 10;
		m_time += (time/60) * 15 + 15;
	}

	if (y_time > m_time)
		cout << "M " << m_time << '\n';
	else if (y_time == m_time)
		cout << "Y M " << y_time << '\n';
	else
		cout << "Y " << y_time << '\n';

	return 0;
}
