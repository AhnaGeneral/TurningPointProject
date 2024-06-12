#include <iostream>
using namespace std;
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <ranges>

// == Designated initialization 지정 초기화 == 

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
	// * 조건 * 
	// - 직접 만든 생성자가 없어야 함. 
	// - 가상 함수 없어야 함. 
	// - private, protected, static인 데이터 변수 x 
	Pos3D pos{1, 2, 3.f /* narrowing conversion */};
	


	// < Designated initialization > -----------------------
	// * 장점 * 
	// - 원하는 얘만 채울 수 있음. 
	// - 클래스, struct 멤버 선언 순서로 해야 함.
	// - 축소 변환을 허용하지 않는다. Aggregate 보다 더 엄격함.
	Pos3D Pos2{ .x = 2, .z = 3 };
	


	return 0;
}