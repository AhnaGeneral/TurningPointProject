#include <iostream>
using namespace std;
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <ranges>


// 오늘의 주제 : Three-Way Comparsion 연산자

struct MyInt
{
	MyInt(int value) : _value(value)
	{
	}


	//  [ '<' '<=' '>' '>=' '==' '!=' : 6개]의 operator를 만들지 않아도 되는게 새로 나왔다
	
	//auto operator <=>(const MyInt& rhs) const { return _value <=> rhs._value; }
	auto operator <=>(const MyInt& rhs) const = default;
	// 현재 비교가 int 밖에 없기 때문에 strong_ordering을 뱉음.
	// 다르게 동작하고 싶은 부호가 있다면 따로 부호를 열어서 정의 해주면 된다. 
	// < <= > >= == !=
	// 직접 재정의 하는게 Three-Way Comparsion 연산자 보다 우선순위가 높다
	bool operator<(const MyInt& rhs/*RightHandSize*/) const
	{
		return _value < rhs._value;
	}
	int _value;
};


// - strong ordering 
// relational(o), equivalence(o), comparable(o) 모두 만족
struct Strong
{
	std::strong_ordering operator <=> (const Strong& rhs) const = default;
};

// - weak ordering
// relational(o), equivalence(x), comparable(o) 
struct Weak
{
	std::weak_ordering operator <=> (const Weak& rhs) const = default;
};

// - partical ordering 
// relational(o), equivalence(x), comparable(x) 
struct Partial
{
	std::partial_ordering operator <=> (const Partial& rhs) const = default;
};


struct Test
{
	auto operator <=> (const Test&) const = default;
	// Parital 인데 Weak로 바꾸면 ? 
	// -- 출혼된 기본 및 멤버 중에서 공통 범주보다 강력한 비교 범주를 반환하도록 기본 비교함수를 선언할 수 없습니다

	Strong s;
	Weak w;
	Partial p; 
	// ↑
	// 때문에 Strong 이나 waak로 ordering이 만들어 질 수 없다는 제약이 생긴다.
	// ex ) 롤 LOL 일 때 Strong: 다이아,  Weak: 에메랄드 Partial: 골드 --> 랭크 불가능 
};
int main()
{
	MyInt a = 1; 
	MyInt b = 2; 

	bool test = a < b; 
	bool test2 = a > b;
	bool test3 = a <= b;





	// 비교 (relational, equivalence, comparable)
	// - 6종 비교 연산자 지원 
	// - 모든 

	// comparable
	// - a < b , a==b , a > b 중 하나는 참이다. (하나라도 참이면 comparable 조건 을 만족한다.)


	//

	int a1 = 100; 
	int a2 = 200; 

	auto ret = (a1 <=> a2);

	if (ret < 0)
	{
		cout << "a<b" << endl; 
	}
	else if (ret == 0)
	{
		cout << "a==b" << endl;
	}
	else if (ret > 0)
	{
		cout << "a>b" << endl; 
	}
}
