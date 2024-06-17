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
// constexpr: 최대한 컴파일 타임
constexpr int sqrRunOrCompileTime(int n)
{
	return n * n;
}

// c++20
// consteval: 100% 컴파일 타임
consteval int sqrCompileTime(int n)
{
	return n * n;
}

int main(void)
{
	// 일반 vs constexpr vs consteval 

	// CompileTime vs RunTime 
	// Build --> Compile (컴파일러가 번역해서 바이너리 파일로 ..)
	// --> Link --> 실행파일(exe) --> RunTime 실질적으로 실행)
	
	// compile : 실행파일이 만들어지는 과정이므로 오래 걸리더라도 RunTime때 계산이 없다면 게임이 빨리 실행 된다.

	int val1 = sqrRunTime(10);
	int val2 = sqrRunOrCompileTime(10);
	int val3 = sqrCompileTime(10);

	// 컴파일 타임이 만들어지는지 런타임에서 만들어지는지 가장 확실하게 볼 수 있는 방법은 ? 
	// == 디버깅을 해보는 것 
	// 디버킹 -> 창 -> 디스어셈블러
	
	int a = 10;  // <- Stack

	int val1 = sqrRunTime(a); // ok 
	constexpr int val2 = sqrRunOrCompileTime(a); // error 
	int val2 = sqrRunOrCompileTime(a); // ok 
	int val3 = sqrCompileTime(a); // error 

	// 경우에 따라서 런타임일수 밖에 없는 상황이 있다. 
	return 0;
}