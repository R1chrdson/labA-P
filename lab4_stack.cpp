#include <stdio.h>
#include <iostream>

/*
* This method I've get from https://www.geeksforgeeks.org/stack-push-and-pop-in-c-stl/
* Method of clearing stack from  https://stackoverflow.com/questions/40201711/how-can-i-clear-a-stack-in-c-efficiently/40201896
*/
#include <stack>

using namespace std;

int main(void)
{
    stack<int> STACK;
    string commands[6] = {"push", "pop", "back", "size", "clear", "exit"};
    while(true)
    {
        string tmp; 
        cin >> tmp;
        /* 
        * This loop will check each element of array `commands` and if user typed right command, do it.
        * I've used this method to avoid a lot of "if (tmp == "push") {...} else if (tmp == "pop") {...} else if ...  "
        */
        for (int i = 0; i < 6; i++)
        {
            if(tmp == commands[i])
            {
                switch(i)
                {
                    // push
                    case 0:
                    {
                        int value;
                        cin >> value;
                        STACK.push(value);
                        cout << "ok" << endl;
                        break;
                    }
                    // pop
                    case 1:
                    {
                        cout << STACK.top() << endl;
                        STACK.pop();
                        break;   
                    }
                    // back
                    case 2:
                    {
                        cout << STACK.top() << endl;
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
                        STACK = stack<int>();
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