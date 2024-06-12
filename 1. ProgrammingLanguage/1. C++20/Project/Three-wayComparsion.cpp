#include <iostream>
using namespace std;
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <ranges>


// ������ ���� : Three-Way Comparsion ������

struct MyInt
{
	MyInt(int value) : _value(value)
	{
	}


	//  [ '<' '<=' '>' '>=' '==' '!=' : 6��]�� operator�� ������ �ʾƵ� �Ǵ°� ���� ���Դ�
	
	//auto operator <=>(const MyInt& rhs) const { return _value <=> rhs._value; }
	auto operator <=>(const MyInt& rhs) const = default;
	// ���� �񱳰� int �ۿ� ���� ������ strong_ordering�� ����.
	// �ٸ��� �����ϰ� ���� ��ȣ�� �ִٸ� ���� ��ȣ�� ��� ���� ���ָ� �ȴ�. 
	// < <= > >= == !=
	// ���� ������ �ϴ°� Three-Way Comparsion ������ ���� �켱������ ����
	bool operator<(const MyInt& rhs/*RightHandSize*/) const
	{
		return _value < rhs._value;
	}
	int _value;
};


// - strong ordering 
// relational(o), equivalence(o), comparable(o) ��� ����
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
	// Parital �ε� Weak�� �ٲٸ� ? 
	// -- ��ȥ�� �⺻ �� ��� �߿��� ���� ���ֺ��� ������ �� ���ָ� ��ȯ�ϵ��� �⺻ ���Լ��� ������ �� �����ϴ�

	Strong s;
	Weak w;
	Partial p; 
	// ��
	// ������ Strong �̳� waak�� ordering�� ����� �� �� ���ٴ� ������ �����.
	// ex ) �� LOL �� �� Strong: ���̾�,  Weak: ���޶��� Partial: ��� --> ��ũ �Ұ��� 
};
int main()
{
	MyInt a = 1; 
	MyInt b = 2; 

	bool test = a < b; 
	bool test2 = a > b;
	bool test3 = a <= b;





	// �� (relational, equivalence, comparable)
	// - 6�� �� ������ ���� 
	// - ��� 

	// comparable
	// - a < b , a==b , a > b �� �ϳ��� ���̴�. (�ϳ��� ���̸� comparable ���� �� �����Ѵ�.)


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
