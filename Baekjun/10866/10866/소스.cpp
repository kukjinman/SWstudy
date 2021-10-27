#include <iostream>
using namespace std;


int N;

typedef struct s_node { 
	int data; 
	struct s_node* before; 
	struct s_node* after; 
}node;


void push_front(const int val)
{


}

void CmdReader(string cmd_)
{

	if (cmd_ == "push_front")
	{
		int temp_val;
		cin >> temp_val;


	}
	else if (cmd_ == "push_back")
	{



	}
	else if (cmd_ == "pop_front")
	{



	}
	else if (cmd_ == "pop_bacl")
	{



	}
	else if (cmd_ == "size")
	{



	}
	else if (cmd_ == "empty")
	{



	}
	else if (cmd_ == "front")
	{



	}
	else if (cmd_ == "back")
	{



	}

}
void input()
{
	cin >> N;
	int counter = 1;
	while (counter <= N)
	{
		string cmd;
		cin >> cmd;
		CmdReader(cmd);

		counter++;
	}

}






int main()
{

	input();

	return 0;
}
