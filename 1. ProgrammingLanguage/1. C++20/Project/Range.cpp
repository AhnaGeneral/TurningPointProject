#include <iostream>
using namespace std; 
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <ranges>

// Range 
// C# ���� LINQ �����̶� ����ϴ�. 

int main(void)
{
	vector <int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 , 10 };

	auto results = v1 
		| std::views::filter([](int n) {return n % 2 == 0; }) // � ���ǿ� �ش��� �ֵ鸸 �������
		| std::views::transform([](int n) {return n * 2; })  // ��ȯ��Ų��. 
		| std::views::take(3); // 3���� �������� 
		// "¦���� �����ؼ� 2�� �����ش�" ��� �ڵ尡 �ϼ�


	// - Range : Range�� ��ȸ�� �� �ִ� ������ �׷� (ex. STL Contrainer)
	// - View : Range�� ���ؼ� ������ �� �ִ� ����
	return 0;
}