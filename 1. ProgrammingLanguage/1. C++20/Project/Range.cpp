#include <iostream>
using namespace std; 
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <ranges>

// Range 
// C# 기준 LINQ 문법이랑 비슷하다. 

int main(void)
{
	vector <int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 , 10 };

	auto results = v1 
		| std::views::filter([](int n) {return n % 2 == 0; }) // 어떤 조건에 해당한 애들만 골라가지고
		| std::views::transform([](int n) {return n * 2; })  // 변환시킨다. 
		| std::views::take(3); // 3개만 추출해줘 
		// "짝수를 추출해서 2를 곱해준다" 라는 코드가 완성


	// - Range : Range란 순회할 수 있는 아이템 그룹 (ex. STL Contrainer)
	// - View : Range에 대해서 적용할 수 있는 연산
	return 0;
}