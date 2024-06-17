// 1. vector, string � constexpr ��� ����
// algorithm 100�� �̻� �Լ����� constexpr�� �ٲ�.
// constexpr == ������ Ÿ�ӿ� �����ȴ�. 

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

	// 2. std::array ����� ����� �߰��� (std::to_array)
	auto ToArray = std::to_array("Hello World");
	//�Ͻ��� Ÿ�� �߷� 
	auto ToArray = std::to_array<int>({ 1,2,3,4,5,6 });
	//����� Ÿ�� �߷�



	// 3. std::make_shard
	int* arr3 = new int[10];
	delete[] arr3;

	std::shared_ptr<int> sp(new int[10]);
	std::shared_ptr<int> sp(new int[10], /*��� �������� �ִ� ������*/ ArrayDeleter<int>());

	std::shared_ptr<double[]> shared_ptr = std::make_shared<double[]>(1024);
	// ���� �����迭�� ���� shared_ptr�� �����ϴ� ��Ȳ�� ������ �𸣰���



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

	// error �߻� vec.erase(it); ������ ��� �ٷ� ������ ����Ŵ. 

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
	// ���� ���� ī�� : 
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
		cout << "ã�Ҵ� ���!" << endl; 
	}

	if (s.contains(2))
	{
		cout << "ã�Ҵ� ���!" << endl; 
	}

	std::map<int, int> m {{1, 1000}, { 2, 2000 }}; 
	if (m.contains(2))
	{
		cout << "ã�Ҵ� ���!" << endl;
	}


	//  perfix /suffix checking ���λ� ���̻� üŷ
	// starts_with, ends_with
	std::string str = "Hello World"; 
	std::string str2 = "Hello";
	bool a = str.starts_with("Hello"); 
	bool b = str.ends_with("World");
	bool c = str.starts_with(str2); 

	
}