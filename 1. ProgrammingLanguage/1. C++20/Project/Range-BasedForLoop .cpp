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

	//- ������ ������. 
	//- User* user2 �̸��� �ٲٰų�
	// {} local�� �־�����ų� 

	if (User* user = GerUser(); user == nullptr || user->id == 0)
		return;



	// Range-Baseed for 
	for (vector<int> vec {1, 2, 3}; auto v :vec) 
	{
		cout << v << endl;
	}
}