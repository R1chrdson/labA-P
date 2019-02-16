#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> STACK;
	string commands[6] = { "push", "pop", "back", "size", "clear", "exit" };
	while (true)
	{
		string tmp;
		cin >> tmp;
		/*
		* This loop will check each element of array `commands` and if user typed right command, do it.
		* I've used this method to avoid a lot of "if (tmp == "push") {...} else if (tmp == "pop") {...} else if ...  "
		*/
		for (int i = 0; i < 6; i++)
		{
			if (tmp == commands[i])
			{
				switch (i)
				{
					// push
				case 0:
				{
					int value;
					cin >> value;
					STACK.push_back(value);
					cout << "ok" << endl;
					break;
				}
				// pop
				case 1:
				{
					cout << STACK.back() << endl;
					STACK.pop_back();
					break;
				}
				// back
				case 2:
				{
					cout << STACK.back() << endl;
					break;
				}
				// size
				case 3:
				{
					cout << STACK.size() << endl;
					break;
				}
				// clear
				case 4:
				{
					STACK.clear();
					cout << "ok" << endl;
					break;
				}
				// exit
				default:
				{
					cout << "bye" << endl;
					return 0;
				}
				}
			}
		}
	}
}