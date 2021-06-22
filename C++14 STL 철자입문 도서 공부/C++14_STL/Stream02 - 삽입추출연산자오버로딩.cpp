//어떤 클래스 타입이라도 스트림 반복자를 사용하려면 삽입 연산자(<<)와 추출 연산자(>>)를 반드는 오버로딩 해야한다.
//필요한 public, private데이터 멤버에 접근하는 get, set함수들을 만들면 되고, 아니면 연산자 함수를 friend 함수로 
//지정해줘도 된다. 
#include <iostream>
#include <string>
using std::string;
class Name
{
private: 
	string first_name{}; 
	string second_name{};
public:
	Name() = default; 
	Name(const std::string& first, const std::string& second) : first_name{ first }, second_name{ second } {}
	friend std::istream& operator>>(std::istream& in, Name name); 
	friend std::ostream& operator<<(std::ostream& out, const Name& name); 
};
//Name 객체를 위한 추출(>>)연산자
inline std::istream& operator>>(std::istream* in, Name name)
{
	return in >> name.first_name >> name.second_name;
}