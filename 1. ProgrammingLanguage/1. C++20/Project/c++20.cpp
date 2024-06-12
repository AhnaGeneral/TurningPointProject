#include <iostream>
#include <list>
#include <algorithm>
using namespace std; 

// 2024.05.28 
// Concept (컨셉)
// C#에 Generic, where 문법과 같이 추가적인 조건으로 제한을 걸어주는 함수


// 1. Requires Clause(절) -------------------------------
template<typename T>
requires std::integral<T>
void TestConcept1(T number)
{
	cout << number << endl; 
}

// 2. Trailing Requires Clause (뒤에 붙는 ~) -------------
template<typename T>
void TestConcept2(T number) requires std::integral<T>
{
	cout << number << endl;
}

// 3. constrained Template Parameter (강요된) -------------
template<std::integral T>
void TestConcept3(T number) 
{
	cout << number << endl;
}

// 4. Abbreviated Function Template  ----------------------
void TestConcept4(std::integral auto number)
{
	cout << number << endl;
}

//함수 실행을 할 때 런 타임에서 결정되어 가지고 return 함.


class GameObject
{
	int mId;
};

class Knight : public GameObject
{

};

class Orc : public GameObject
{

};

template<typename T>
requires std::derived_from<T, GameObject>
void TestObj(T* obj)
{
	
}

// 새로운 컨셉을 추가 할 수 있다. 
// 반드시 컴파일 타임에 꼭 만들어져야 한다. 
template <typename T>
concept MyConceptAddAble = requires(T a, T b)
{
	a + b;
	// a+b가 가능해야함.
}; 

template <typename T>
concept MyEquality = requires(T a, T b)
{
	{a == b } -> std::convertible_to<bool>; 
	{a != b } -> std::convertible_to<bool>;
};
//---------------------------------------------------------------
int main()
{
	//TestConcept1(10.3f); --> requires
	TestConcept2(10.4f);
	TestConcept3(10.5f);
	TestConcept4(10.6f);

	// _Is_any_of_v<int, short, int, long long> 
	// 컴파일 타임에 결정됨. 빌드할 때는 느려질 수 있으나 프로그램 실행 될 때는 빠르다. 
	// C# where 문법과 비슷한 컨셉인 derived_from이 가장 비슷하다. 

	list<int> li;
	std::sort(li.begin(), li.end()); 
	// 임의 접근(random_access_iterator)이 안되기 때문에 컴파일 하면 오류남. 
}
