module; // global module fragment
// 각종 외부 헤더 추가
#include <vector>
#include <list>
// module 시작!
export module Math;

// import module 
// submodule 부가적인 모듈
// math_time을 import해서 다시 math 모듈에 포함해서 export해라 
export import Math_Time;

// fragment module

// 1. 함수 앞에다가 export : 수출 대상이다
// ** export를 뺀다면 ? 
// int Add(int a, int b)
// 이 ixx 모듈 안[내부]에서만 사용하는 함수이다.
// 밖에서 꺼내 쓰려고 하면 에러가 발생한다. 

export int Add(int a, int b)
{
	return a + b;
}
// 2. export하고 싶은 애들을 따로 묶어주는 방법이 있다
export
{
	void TextExport()
	{
		
	}
}

// 3. namespace를 지정하는 법
export namespace test
{
	void TestExport2()
	{
		
	}
}
