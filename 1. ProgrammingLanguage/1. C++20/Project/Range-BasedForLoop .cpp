#include <iostream>
#include <vector>
using namespace std;


struct User
{
	int id;
};

User* GerUser()
{
	return nullptr;
}

int main(void)
{
	//C++17 if/switch Initializer

	if (int a = 10; a == 10)
	{
		cout << a << endl; 
	}

	User* user = GerUser();
	if (user == nullptr || user->id == 0)
		return; 

	//- 재사용이 불편함. 
	//- User* user2 이름을 바꾸거나
	// {} local에 넣어버리거나 

	if (User* user = GerUser(); user == nullptr || user->id == 0)
		return;



	// Range-Baseed for 
	for (vector<int> vec {1, 2, 3}; auto v :vec) 
	{
		cout << v << endl;
	}
}