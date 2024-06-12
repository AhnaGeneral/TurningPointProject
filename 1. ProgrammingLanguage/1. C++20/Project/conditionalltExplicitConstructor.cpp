#include <iostream>
using namespace std;

struct A
{
	A() = default; 
	explicit A(int n) //explicit 명확하다. 명시적이다. 
	{
		cout << n << endl;
	}
};

void TestA(A a)
{
	
}

struct B
{
	B() = default;

	// explicit : 원하지 않은 형변환이 일어나지 않도록 제한한다. 
	template<typename T>
	explicit B(T n)
	{
		cout << n << endl;
	}
};

void TestB(B b)
{

}

struct C
{
	C() = default;

	// condition explicit : 조건 부로 원하지 않은 형변환이 일어나지 않도록 제한한다. 
	template<typename T>
	explicit (!std::is_same < T, bool>::value) C( T n)
	{
		cout << n << endl;
	}
};

void TestB(B b)
{

}


int main(void)
{
	A a; 
	TestA(a);
	TestA(10); 
	// - explicit A(int n) 생성자 : error
	// - A (int n) 생성자 : ok 임시객체를 만들어서 통과 시켜줌

	B b;
	TestB(b);
	TestB(10);
	TestB("string");

	return 0;
}