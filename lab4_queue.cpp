#include <stdio.h>
#include <iostream>

/*
* This method I've get from https://codelessons.ru/cplusplus/ochered-queue-v-c-realizaciya-i-chto-eto-voobshhe-takoe.html
* To clear queue I've used this method https://stackoverflow.com/questions/40201711/how-can-i-clear-a-stack-in-c-efficiently/40201896
*/
#include <queue>

using namespace std;

int main(void)
{
    queue<int> QUEUE;
    string commands[6] = {"push", "pop", "front", "size", "clear", "exit"};
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
                        QUEUE.push(value);
                        cout << "ok" << endl;
                        break;
                    }
                    // pop
                    case 1:
                    {
                        cout << QUEUE.front() << endl;
                        QUEUE.pop();
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
                        queue<int>().swap(QUEUE);
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