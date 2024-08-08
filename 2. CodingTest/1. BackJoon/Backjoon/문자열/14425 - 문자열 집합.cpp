#include <iostream>
using namespace std; 
#define ALPHABETS 26

int char_to_index(char c)
{
	return c - 'a';
}

class Trie
{
	bool is_end; 
	Trie* children[ALPHABETS];

public:
	Trie() 
	{
		is_end = false;
		memset(children, 0, sizeof(children));
	}

	~Trie()
	{
		for (int i = 0; i < ALPHABETS; ++i)
		{
			if (children[i])
				delete children[i];
		}
	}


	void insert(const char* key)
	{
		if (*key == '\0')
		{
			is_end = true;
		}
		else
		{
			int idx = char_to_index(*key);
			
			if (children[idx] == nullptr)
			{
				children[idx] = new Trie();
				children[idx]->insert(key + 1);
			}
			else
			{
				children[idx]->insert(key + 1);
			}

		}
	}

	Trie* find(const char* key)
	{
		if (*key == 0)
		{
			return this;
		}
		int idx = char_to_index(*key);

		if (children[idx] == 0)
		{
			return nullptr;
		}

		return children[idx]->find(key + 1); 
	}


	bool string_exit(const char* key)
	{
		if (*key == '\0')
		{
			return is_end;
		}

		int idx = char_to_index(*key);

		if (children[idx] == 0)
		{
			return false;
		}

		return children[idx]->string_exit(key + 1);
	}

};


int main(void)
{
	Trie* root = new Trie(); 

	int n, m; 
	cin >> n >> m; 

	while (n--)
	{
		string str; 
		cin >> str; 

		root->insert(str.c_str());
	}

	int cnt = 0;
	while (m--)
	{
		string str;
		cin >> str;
		if (root->string_exit(str.c_str()))
		{
			//cout << str << endl; 
			++cnt;
		}
	}

	cout << cnt;
	return 0;
}