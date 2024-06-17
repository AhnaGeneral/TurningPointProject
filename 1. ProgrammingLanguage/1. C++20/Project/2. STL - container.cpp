// 1. vector, string 등에 constexpr 사용 가능
// algorithm 100개 이상 함수들이 constexpr로 바뀜.
// constexpr == 컴파일 타임에 결정된다. 

// 3. std::make_shard
#include <iostream>
using namespace std;
#include <list>
#include <vector>
#include <array>
#include <set>
#include <map>
template<typename T>
struct ArrayDeleter
{
	void operator()(const T* ptr)
	{
		delete[] ptr;
	}
};
int main(void)
{
	vector<int> a;

	// 2. std::array 만드는 방법이 추가됨 (std::to_array)
	auto ToArray = std::to_array("Hello World");
	//암시적 타입 추론 
	auto ToArray = std::to_array<int>({ 1,2,3,4,5,6 });
	//명시적 타입 추론



	// 3. std::make_shard
	int* arr3 = new int[10];
	delete[] arr3;

	std::shared_ptr<int> sp(new int[10]);
	std::shared_ptr<int> sp(new int[10], /*어떻게 삭제할지 넣는 생성자*/ ArrayDeleter<int>());

	std::shared_ptr<double[]> shared_ptr = std::make_shared<double[]>(1024);
	// 굳이 동적배열을 만들어서 shared_ptr로 관리하는 상황이 있을지 모르겠음



	// erase, erase_if
	vector<int> vec {-1, 2, 3, 4, -5, 7, -2, 3 };

	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		int value = *it;
		if (value < 0)
		{
			vec.erase(it);
		}
		else
		{

		}
	}

	// error 발생 vec.erase(it); 지워진 대상 바로 다음을 가리킴. 

	for (auto it = vec.begin(); it != vec.end();)
	{
		int value = *it;
		if (value < 0)
		{
			it = vec.erase(it);
		}
		else
		{
			it++;
		}
	}


	std::remove_if(vec.begin(), vec.end(), [](int num) {return num < 0; });
	// 슈퍼 함정 카드 : 
	// -1 , 2, -3, 4, -5 
	// 2, 4, -3, 4, 5
	auto newEnd = std::remove_if(vec.begin(), vec.end(), [](int num) {return num < 0; });
	vec.erase(newEnd, vec.end());


	// std:: c++20 erase, erase_if 
	std::erase(vec, 2);
	std::erase_if(vec, [](int num) {return num < 0; });


	// contains + perfix /suffix checking
	
	std::set s {1, 2, 3, 4, 5}; 
	auto findlt = s.find(2);
	if (findlt != s.end())
	{
		cout << "찾았다 요놈!" << endl; 
	}

	if (s.contains(2))
	{
		cout << "찾았다 요놈!" << endl; 
	}

	std::map<int, int> m {{1, 1000}, { 2, 2000 }}; 
	if (m.contains(2))
	{
		cout << "찾았다 요놈!" << endl;
	}


	//  perfix /suffix checking 접두사 접미사 체킹
	// starts_with, ends_with
	std::string str = "Hello World"; 
	std::string str2 = "Hello";
	bool a = str.starts_with("Hello"); 
	bool b = str.ends_with("World");
	bool c = str.starts_with(str2); 

	
}