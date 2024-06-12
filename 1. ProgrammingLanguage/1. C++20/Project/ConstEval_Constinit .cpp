#include <iostream>
using namespace std;
#include <list>
#include <vector>
#include <map>
#include <algorithm>

int sqrRunTime(int n)
{
	return n * n; 
}

// c++11
// constexpr: �ִ��� ������ Ÿ��
constexpr int sqrRunOrCompileTime(int n)
{
	return n * n;
}

// c++20
// consteval: 100% ������ Ÿ��
// Ư¡
// - ���Ǻ� jump, loop ����
// - �ټ��� ��ɾ�� ���� ����
// - constexpr �Լ� ȣ�� ���� 
// - static, thread_local �� �� 
// - try, goto �� ��
// - non-consteval �Լ� ȣ�� �� ��
// - non-constexpr ������ ��� �� ��
consteval int sqrCompileTime(int n)
{
	return n * n;
}

int main(void)
{
	// �Ϲ� vs constexpr vs consteval 

	// CompileTime vs RunTime 
	// Build --> Compile (�����Ϸ��� �����ؼ� ���̳ʸ� ���Ϸ� ..)
	// --> Link --> ��������(exe) --> RunTime ���������� ����)
	
	// compile : ���������� ��������� �����̹Ƿ� ���� �ɸ����� RunTime�� ����� ���ٸ� ������ ���� ���� �ȴ�.

	int val1 = sqrRunTime(10);
	int val2 = sqrRunOrCompileTime(10);
	int val3 = sqrCompileTime(10);

	// ������ Ÿ���� ����������� ��Ÿ�ӿ��� ����������� ���� Ȯ���ϰ� �� �� �ִ� ����� ? 
	// == ������� �غ��� �� 
	// ���ŷ -> â -> �𽺾����
	
	int a = 10;  // <- Stack

	enum MyEnum // <- enum�� compile Time�� Ȯ���Ǿ�� �Ѵ�.
	{
		VAL_1 = sqrRunTime(10),						//error 
		VAL_2 = sqrRunOrCompileTime(10),			//ok
		VAL_3 = sqrCompileTime(10),				//ok
	};

	int val1 = sqrRunTime(a);						// ok 
	constexpr int val2 = sqrRunOrCompileTime(a); // error 
	int val2 = sqrRunOrCompileTime(a);			// ok 
	int val3 = sqrCompileTime(a);					// error 

	// ��쿡 ���� ��Ÿ���ϼ� �ۿ� ���� ��Ȳ�� �ִ�. 



	// ���� 
	// const vs constexpr vs constinit
	// 1. const 
	// - ������Ÿ��/��Ÿ�� + constness(����� ���ϸ� �ȵȴ�. �����)�ʿ�
	// - const ������ �ʱ�ȭ�� ��Ÿ�ӱ��� ������ų �� �ִ�. 
	const int constintval = sqrRunTime(10);
	//constintval++; //error
	// 2. constexpr 
	// - ������Ÿ�� + constness 
	// constexpr �Լ��� ������ ��Ÿ�� Ȥ�� ������ Ÿ�� ��� ������ 
	// constexpr ������ ������ ��.��.�� Ÿ�� 
	constexpr int constExprVal = sqrCompileTime(10);
	constExprVal++; //error

	// 3. constinit 
	// - ������Ÿ�� + constness(x) + static/thread_local
	// - global ����, static ����, thread_local ������ ������� ��� 
	// - ���α׷� ���� �� �޸� �Ҵ�, ���α׷��� ������ �޸� ����
	// - thread_local ������ thread�� ���Ӽ�, Ư�� thread�� �ش� �����͸� ����� �� ������. 

	constinit thread_local int constlnitVal = sqrRunOrCompileTime(10);
	return 0;
}