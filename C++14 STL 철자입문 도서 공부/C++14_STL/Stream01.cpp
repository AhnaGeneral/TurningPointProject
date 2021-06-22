#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
using std::string; 

int main()
{
	std::vector<string> words{ "Sunmee", "can" ,"successed" , "fighting" };
	
	// 일반적인 반복자 표기법을 사용해 words 컨테이너에 쓰기
	// 생성자에서 출력 스트림을 인수로 호출해서 out_iter1 스트림 반복자를 생성한다. 
	std::ostream_iterator<string> out_iter1 { std::cout }; //출력구분자 없는 반복자
    // 반복자를 역참조해서 word의 현재 값을 out_iter1을 역 참조한 결과에 복제한 뒤에 반복자를 증가시킨다. 
	
	for (const auto& word : words)
	{
		*out_iter1++ = word; //단어 쓰기
		*out_iter1++ = " ";  //구분자를 쓰기
	}
	*out_iter1++ = "\n";     // 새 줄을 쓰기
	// out_iter1 = '\n'; 컴파일 되지 않는다. 반복자가 스트림에 string객체를 쓰도록 정의되어 있으므로 
	// 다른 타입의 데이터는 쓸 수 없다. operateor=()멤버는 문자열 인수만 받아들이므로 위 문장은 컴파일 되지 않는다. 
	// operator*(), 전위 증가, 휘의 증가 연산자는 반복자에 대한 참조를 반환하는 것을 제외하면 아무것도 하지 않는다. 
	// 따라서 이러한 연산이 필요하지 않고 두 번째 루프의 문장에서처럼 이러한 연산이 없어도 같은 결과를 낼 수 있다. 
	for (const auto& word : words)
	{
		(out_iter1 = word) = " "; //단어와 구분자 쓰기
	}
	out_iter1 = "\n"; 
	// copy()를 사용해 words 컨테이너에 쓰기 
	std::ostream_iterator<string> out_iter2 {std::cout, " " }; 
	std::copy(std::begin(words), std::end(words), out_iter2);
	out_iter2 = "\n";
}
