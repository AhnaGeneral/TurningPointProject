#include <iostream>
using namespace std;
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <ranges>

// == Designated initialization ���� �ʱ�ȭ == 

struct Pos2D
{
	int x; 
	int y; 
};

struct Pos3D
{
public :
	int x;
	int y;
	int z;
};

int main(void)
{
	//Pos3D pos;
	//pos.x = 0; 
	//pos.y = 1;
	//pos.z = 2;
	

	// < Aggregate Initialization > ------------------------
	// * ���� * 
	// - ���� ���� �����ڰ� ����� ��. 
	// - ���� �Լ� ����� ��. 
	// - private, protected, static�� ������ ���� x 
	Pos3D pos{1, 2, 3.f /* narrowing conversion */};
	


	// < Designated initialization > -----------------------
	// * ���� * 
	// - ���ϴ� �길 ä�� �� ����. 
	// - Ŭ����, struct ��� ���� ������ �ؾ� ��.
	// - ��� ��ȯ�� ������� �ʴ´�. Aggregate ���� �� ������.
	Pos3D Pos2{ .x = 2, .z = 3 };
	


	return 0;
}