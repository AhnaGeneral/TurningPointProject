#include <iostream>
#include <vector>
using namespace std;

// Attributes : �����Ϸ����� �ٿ��ִ� �ּ����� ����
//[[noreturn]] // c++11 �Լ��� �������� �ʴ´� 
//[[deprecated]]
//[[nodiscard]] // ������ �ʴ´�. C++17 �����ڿ����� ���� �� ���� C++20 �����ڿ��� ���� �� ����
[[nodiscard("error code ����ϼ���.")]] // C++20 ������ ���� �� �� �ִ� .

// [[likely]] [[unlikely]] - ����ȭ�� �߿�
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
			[[likely]] //���Ⱑ �� ���� ���ð� ����.
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
	// �����Ϸ����� ��Ʈ�� �ִ°Ŵ� /
	// nuique_addres�� �ʿ䰡 ����/
	// NoUniqueAddress��ü�� 100�� ������� Em�� ����(���� �ּ�)���� ����ϸ� �ȴ� 
	// - Static�̶� �����
	// �� �ּҷ� ������ ���� ���� �ʿ� ����!!
	Em e; 
};

int main(void)
{
	Func(); // �츮�� ������� �ʴ´�. 
	int val = Func() // nodiscard error (x)

}