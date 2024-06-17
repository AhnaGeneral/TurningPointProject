#include <iostream>
using namespace std;
#include <list>
#include <vector>
#include <span>
#include <algorithm>

void PrintArray(int* arr)
{

}

void PrintSpan(std::span<int> container)
{
	cout << "container size() = " << container.size() << endl; 
	for (int idx = 0; idx < container.size(); ++idx)
	{
		cout << container[idx] << endl;
	}

	
	for (auto& At : container)
	{
		cout << At << endl; 
	}
}
int main()
{
	//std::span = c타입 배열, std::array, std::vector, std::string등의 
	//연이은 객체 시퀀스(contiguous sequence of objects)를 참조(refer)
	//c타입 배열, std::array, std::vector, std::string 등을 인자로 넘기지 않고
	//std::span이란 애로 넘기겠다라는이야기ㅇ

	//왜 굳이 ? 
	//일단 치명적인 문제는 고전적인 배열에 대한 문제먼저 확인
	int arr[] = { 1,2,3,4,5 }; 
	const int size = sizeof(arr); //20 
	const int len = sizeof(arr) / sizeof(int); //5

	PrintArray(arr); 
	// 여기는 그냥 포인터 주소값이니 주소값만 넘겨준거다. 
	// 배열에 대한 정보는 추가적으로 넘기지 않았음. 
	// 그래서 항상 추가적으로 int len와 같이 매개변수를 추가하며 추가적인 정보를 넘겼다. 


	//std::span 
	// static_extent = 컴파일 타임에 크기가 정해짐 //배열, array
	// dynamic_extent = vector와 같이 동적으로 크기가 변하는 
	// 포인터 + 크기 
	vector<int> myVec {1, 2, 3, 4, 5}; 
	vector<int> myVec2 {6, 7, 8, 9, 10}; 
	std::span<int> dynamic_span(myVec2); 
	std::span<int, 5> static_span(myVec);

	PrintSpan(dynamic_span); 
	PrintSpan(static_span);

	dynamic_span = static_span; 
	static_span = dynamic_span; //error 
	//고정적인 크기에 가변적인 크기를 덮어쓰는거 불가. 

	//포인터/사이즈를 이용하여 span 생성
	std::span<int> span1(myVec.data(), myVec.size()); 
	// 부분적으로 잘라서 만들기
	std::span<int> span2(span1.subspan(1, span1.size() - 2);

	std::transform(span1.begin(), span1.end(), span1.begin(), [](int i) {return i * i; });
	PrintSpan(span1); 

	//span은 복사하는것이 아닌 참조이므로 원본 데이터가 수정이 된다. 

}


//_EXPORT_STD template <class _Ty /*어떤 타입인지*/, size_t _Extent /*요소 크기*/ = dynamic_extent>
//class span : private _Span_extent_type<_Ty, _Extent>
//
//_EXPORT_STD inline constexpr size_t dynamic_extent = static_cast<size_t>(-1); //무한대로 큰 값이 잡혀 있음.