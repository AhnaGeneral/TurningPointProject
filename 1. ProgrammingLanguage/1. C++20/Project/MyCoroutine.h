#pragma once
#include <coroutine>
#include <iostream>
using namespace std; 

template<typename T>
class Future
{
public:
	Future(shared_ptr<T> value) : _value(value) {}
	T get() { return *_value; }
	
private:
	shared_ptr<T> _value; 

public:
	struct promise_type
	{
		Future get_return_object() { return Future<T>(_ptr); }
		void return_value(T value) { *_ptr = value; }
		std::suspend_never initial_suspend() const noexcept { return {}; }
		std::suspend_never final_suspend() const noexcept { return {}; }
		void unhandled_exception() {}

		shared_ptr<T> _ptr = make_shared<T>();
	};
};
