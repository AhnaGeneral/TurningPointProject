#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <concepts>
#include <coroutine>
#include "MyCoroutine.h"
// Coroutine 
// 유니티 != 코루틴
// - C#에서 있는 코루틴 문법을 유니티에서 적극적으로 채용해서 제공
// - 함수를 우리가 어디까지 호출했는지 저장을 하고 일시정지하고 이어서 호출할 수 있는 기능 [리모컨 처럼]


// 몬스터 잡으면 --> 아이템이 인벤토리에 들어온다
// 1. 몬스터를 잡음.
// 2. DB 먼저 적용 --> callback으로 던저 줬음. 
// 3. 아이템 생성 + 인벤토리에 추가.

struct CoroutineObject
{
	struct promise_type
	{
		CoroutineObject get_return_object() { return {}; }
		std::suspend_never initial_suspend() const noexcept { return {}; }
		std::suspend_never final_suspend() const noexcept { return {}; }
		void return_void() {}
		void unhandled_exception() {}
	};
};

Future<int> CreateFuture()
{

}

CoroutineObject HelloCoroutine()
{
	co_return;
}

// co_await flow 
// awaitable.await_ready : false = suspend_always , true = suspend_never


template<typename T>
class Generator
{
	// yield 기능 : 이전 상황을 계속 저장한 채로 이어서 실행하기
public:
	struct promise_type;
	using handle_type = coroutine_handle<promise_type>;

	Generator(handle_type handle) : _handle(handle) {}
	~Generator()
	{
		if (_handle)
			_handle.destory();
	}
	
	T get() { return _handle.promise()._value; }


	bool next() //재개를 해라. 다음 단계로 넘어가라. 
	{
		_handle.resume();
		return !_handle.done();
	}

	private:
		handle_type _handle; 
public :

	struct promise_type
	{
		Generator get_return_object() { return Generator(handle_type::from_promise(*this)); }
		std::suspend_always initial_suspend() const noexcept { return {}; }
		std::suspend_always final_suspend() const noexcept { return {}; }
		std::suspend_always return_void() {}
		std::suspend_always yield_value(const T value) { _value = value; return {}; }
		void unhandled_exception() {}

		T _value; 
	};

};


Generator<int> GenNumbers(int start = 0, int delta = 1)
{
	// 함수 자체를 내가 마지막에 어디까지 실행했는지를 계속 저장하고 있기 때문에 
	// 이전에 마지막으로 호출했던 상태를 유지한 채로 그 다음으로 코드가 계속 만들어진다.
	int now = start; 

	while (true)
	{
		co_yield now; 
		now += delta; 
	}
}
void VeryDifficultFunc()
{
	// 함수가 코루틴이 되려면.. ig
	// - co_return
	// - co_yield
	// - co_await
	// 코루틴을 사용할 수 있는 Framework를 제공한다 
	// 3가지 요소로 구성 
	// - promise 객체 
	// - 코루틴 핸들 (밖에서 코루틴 resume / destory 할 때 사용. 일종의 리모컨)
	// - 코루틴 프레임 (promise 객체, 코루틴이 인자 등을 포함하는 heap 할당 객체)

}