#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <concepts>
#include <coroutine>
#include "MyCoroutine.h"
// Coroutine 
// ����Ƽ != �ڷ�ƾ
// - C#���� �ִ� �ڷ�ƾ ������ ����Ƽ���� ���������� ä���ؼ� ����
// - �Լ��� �츮�� ������ ȣ���ߴ��� ������ �ϰ� �Ͻ������ϰ� �̾ ȣ���� �� �ִ� ��� [������ ó��]


// ���� ������ --> �������� �κ��丮�� ���´�
// 1. ���͸� ����.
// 2. DB ���� ���� --> callback���� ���� ����. 
// 3. ������ ���� + �κ��丮�� �߰�.

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
	// yield ��� : ���� ��Ȳ�� ��� ������ ä�� �̾ �����ϱ�
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


	bool next() //�簳�� �ض�. ���� �ܰ�� �Ѿ��. 
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
	// �Լ� ��ü�� ���� �������� ������ �����ߴ����� ��� �����ϰ� �ֱ� ������ 
	// ������ ���������� ȣ���ߴ� ���¸� ������ ä�� �� �������� �ڵ尡 ��� ���������.
	int now = start; 

	while (true)
	{
		co_yield now; 
		now += delta; 
	}
}
void VeryDifficultFunc()
{
	// �Լ��� �ڷ�ƾ�� �Ƿ���.. ig
	// - co_return
	// - co_yield
	// - co_await
	// �ڷ�ƾ�� ����� �� �ִ� Framework�� �����Ѵ� 
	// 3���� ��ҷ� ���� 
	// - promise ��ü 
	// - �ڷ�ƾ �ڵ� (�ۿ��� �ڷ�ƾ resume / destory �� �� ���. ������ ������)
	// - �ڷ�ƾ ������ (promise ��ü, �ڷ�ƾ�� ���� ���� �����ϴ� heap �Ҵ� ��ü)

}