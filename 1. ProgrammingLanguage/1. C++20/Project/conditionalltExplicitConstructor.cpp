#include <iostream>
using namespace std;

struct A
{
	A() = default; 
	explicit A(int n) //explicit ��Ȯ�ϴ�. ������̴�. 
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

	// explicit : ������ ���� ����ȯ�� �Ͼ�� �ʵ��� �����Ѵ�. 
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

	// condition explicit : ���� �η� ������ ���� ����ȯ�� �Ͼ�� �ʵ��� �����Ѵ�. 
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
	// - explicit A(int n) ������ : error
	// - A (int n) ������ : ok �ӽð�ü�� ���� ��� ������

	B b;
	TestB(b);
	TestB(10);
	TestB("string");

	return 0;
}