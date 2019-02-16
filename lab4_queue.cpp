#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> QUEUE;
	string commands[6] = { "push", "pop", "front", "size", "clear", "exit" };
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
					QUEUE.push_back(value);
					cout << "ok" << endl;
					break;
				}
				// pop
				case 1:
				{
					cout << QUEUE.front() << endl;
					QUEUE.erase(QUEUE.begin());
					break;
				}
				// front
				case 2:
				{
					cout << QUEUE.front() << endl;
					break;
				}
				// size
				case 3:
				{
					cout << QUEUE.size() << endl;
					break;
				}
				// clear
				case 4:
				{
					QUEUE.clear();
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