//� Ŭ���� Ÿ���̶� ��Ʈ�� �ݺ��ڸ� ����Ϸ��� ���� ������(<<)�� ���� ������(>>)�� �ݵ�� �����ε� �ؾ��Ѵ�.
//�ʿ��� public, private������ ����� �����ϴ� get, set�Լ����� ����� �ǰ�, �ƴϸ� ������ �Լ��� friend �Լ��� 
//�������൵ �ȴ�. 
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
//Name ��ü�� ���� ����(>>)������
inline std::istream& operator>>(std::istream* in, Name name)
{
	return in >> name.first_name >> name.second_name;
}