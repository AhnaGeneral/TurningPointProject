#include <iostream>
using namespace std; 

import Math; 

// 모듈 module 
// 빌드 속도를 빠르게 할 수 있다. 
// - 불 필요하게 반복적으로 빌드하는 곳이 너무 많다. (substitution)
// - 매크로 (#define)
// - 심볼 중복 주의 
// 전처리 #include , #define
// 컴파일 오브젝트 파일 .obj
// 링크 


// Module 
// 모듈은 딱 한번만 import된다
// import 순서에 상관없음
// 심볼 중복 정의 
// 모듈의 이름도 지정 가능 
// 인터페이스 / 구현부 분리 관리할 필요 없음 
// C++ 모듈 인터페이스 단위 .ixx

int main()
{
	Add(1, 2);
}