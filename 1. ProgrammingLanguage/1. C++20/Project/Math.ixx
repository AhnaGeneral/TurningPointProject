module; // global module fragment
// ���� �ܺ� ��� �߰�
#include <vector>
#include <list>
// module ����!
export module Math;

// import module 
// submodule �ΰ����� ���
// math_time�� import�ؼ� �ٽ� math ��⿡ �����ؼ� export�ض� 
export import Math_Time;

// fragment module

// 1. �Լ� �տ��ٰ� export : ���� ����̴�
// ** export�� ���ٸ� ? 
// int Add(int a, int b)
// �� ixx ��� ��[����]������ ����ϴ� �Լ��̴�.
// �ۿ��� ���� ������ �ϸ� ������ �߻��Ѵ�. 

export int Add(int a, int b)
{
	return a + b;
}
// 2. export�ϰ� ���� �ֵ��� ���� �����ִ� ����� �ִ�
export
{
	void TextExport()
	{
		
	}
}

// 3. namespace�� �����ϴ� ��
export namespace test
{
	void TestExport2()
	{
		
	}
}
