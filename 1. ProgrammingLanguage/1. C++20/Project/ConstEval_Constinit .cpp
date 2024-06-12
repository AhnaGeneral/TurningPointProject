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
// 특징
// - 조건부 jump, loop 가능
// - 다수의 명령어로 구성 가능
// - constexpr 함수 호출 가능 
// - static, thread_local 안 됨 
// - try, goto 안 됨
// - non-consteval 함수 호출 안 됨
// - non-constexpr 데이터 사용 안 됨
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

	enum MyEnum // <- enum은 compile Time에 확정되어야 한다.
	{
		VAL_1 = sqrRunTime(10),						//error 
		VAL_2 = sqrRunOrCompileTime(10),			//ok
		VAL_3 = sqrCompileTime(10),				//ok
	};

	int val1 = sqrRunTime(a);						// ok 
	constexpr int val2 = sqrRunOrCompileTime(a); // error 
	int val2 = sqrRunOrCompileTime(a);			// ok 
	int val3 = sqrCompileTime(a);					// error 

	// 경우에 따라서 런타임일수 밖에 없는 상황이 있다. 



	// 변수 
	// const vs constexpr vs constinit
	// 1. const 
	// - 컴파일타임/런타임 + constness(절대로 변하면 안된다. 상수성)필요
	// - const 변수의 초기화는 런타임까지 지연시킬 수 있다. 
	const int constintval = sqrRunTime(10);
	//constintval++; //error
	// 2. constexpr 
	// - 컴파일타임 + constness 
	// constexpr 함수에 붙으면 런타임 혹은 컴파일 타임 모두 되지만 
	// constexpr 변수에 붙으면 컴.파.일 타임 
	constexpr int constExprVal = sqrCompileTime(10);
	constExprVal++; //error

	// 3. constinit 
	// - 컴파일타임 + constness(x) + static/thread_local
	// - global 변수, static 변수, thread_local 변수를 대상으로 사용 
	// - 프로그램 시작 시 메모리 할당, 프로그램이 끝나면 메모리 해제
	// - thread_local 변수는 thread에 종속성, 특정 thread가 해당 데이터를 사용할 때 생성됨. 

	constinit thread_local int constlnitVal = sqrRunOrCompileTime(10);
	return 0;
}