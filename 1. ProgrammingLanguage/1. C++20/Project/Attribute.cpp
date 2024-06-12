#include <iostream>
#include <vector>
using namespace std;

// Attributes : 컴파일러에게 붙여주는 주석같은 느낌
//[[noreturn]] // c++11 함수라 리턴하지 않는다 
//[[deprecated]]
//[[nodiscard]] // 버리지 않는다. C++17 생성자에서는 붙일 수 없음 C++20 생성자에서 붙일 수 있음
[[nodiscard("error code 사용하세요.")]] // C++20 사유를 적어 둘 수 있다 .

// [[likely]] [[unlikely]] - 최적화에 중요
// [[no_unique_address]] 

int Func()
{
	return 10;
}

class Knight
{
public:
	Knight(int hp) : _hp(hp)
	{

	}
	int _hp = 100; 
};

enum class MyErrorCode
{
	None, 
	Warning, 
	Critical, 
};

int Sum(vector<int>& v)
{
	int ret = 0; 
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] < 0)
		{
			[[likely]] //여기가 더 많이 들어올거 같다.
			ret -= v[i];
		}
		else
		{
			ret += v[i];
		}

	}
}
MyErrorCode GetError()
{
	return MyErrorCode::Critical;
}


struct Em
{
};

struct NoUniqueAddress
{
	int d; 
	[[no_nuique_address]]
	// 컴파일러에게 힌트로 주는거다 /
	// nuique_addres일 필요가 없다/
	// NoUniqueAddress객체를 100개 만들더라도 Em은 공용(같은 주소)으로 사용하면 된다 
	// - Static이랑 비슷함
	// 각 주소로 영역을 따로 만들 필요 없다!!
	Em e; 
};

int main(void)
{
	Func(); // 우리가 사용하지 않는다. 
	int val = Func() // nodiscard error (x)

}