#include <iostream>
using namespace std;

enum class Color
{
	Red,
	Green,
	Blue,
};
using enum Color; 
int main(void)
{
	Color color = Color::Blue; 

	switch (color)
	{
	case Red: //using enum Color; �̰� ���� 
		break;
	case Color::Green:
		break;
	case Color::Blue:
		break;
	default:
		break;
	}
	switch (color)
	{
	using enum Color; // Local�� ���� �� �ִ� 

	case Red: 
		break;
	case Color::Green:
		break;
	case Color::Blue:
		break;
	default:
		break;
	}
	return 0;
}