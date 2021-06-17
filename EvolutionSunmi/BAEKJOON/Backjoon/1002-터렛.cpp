// Baekjoon - 1002번, 터렛 
// 원의 방정식, 직선의 방정식

#include <iostream> 
#include <cmath>
int Result(int _x1, int _y1, int _r1, int _x2, int _y2, int _r2); 

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie(); 
	
	int caseCount = 0; 
	std::cin >> caseCount;

	int x1, y1, r1, x2, y2, r2; 
	while (caseCount--)
	{ 
		std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2; 
		std:: cout << Result(x1, y1, r1, x2, y2, r2); 
	}
}

int Result(int _x1, int _y1, int _r1, int _x2, int _y2, int _r2)
{
	if ((_x1 == _x2) && (_y1 == _y2) && (_r1 == _r2))
		return -1; 

	int Dist = sqrt(pow(_x2 - _x1, 2) + pow(_y2 - _y1, 2)); 
	int sub = _r1 > _r2 ? (_r1 - _r2) : (_r2 - _r1); 

	if (Dist == (_r1 + _r2)) return 1;

	else if (Dist < (_r1 +_r2))
	{
		if (sub == Dist) return 1;
		else if (sub < Dist) return 2;
		else if (sub > Dist) return 0;
	}
	else return 0; 
}
