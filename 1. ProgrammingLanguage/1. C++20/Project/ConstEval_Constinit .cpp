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

	int val1 = sqrRunTime(a); // ok 
	constexpr int val2 = sqrRunOrCompileTime(a); // error 
	int val2 = sqrRunOrCompileTime(a); // ok 
	int val3 = sqrCompileTime(a); // error 

	// ��쿡 ���� ��Ÿ���ϼ� �ۿ� ���� ��Ȳ�� �ִ�. 
	return 0;
}