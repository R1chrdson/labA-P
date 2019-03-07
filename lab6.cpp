#include <stdio.h>
#include <iostream>
using namespace std;

#define HASH_SIZE 1000000

typedef struct node 
{
    string word;
    struct node* next;
} 
node;
node* hashTable[HASH_SIZE];

int hashing(string word)
{
    int sum = 0;
    for(int i = 0; i < word.length(); i++)
    {
        sum += (sum << 2) ^ word[i];
    }
    return sum % HASH_SIZE;
}

int check(string word)
{
    int index = hashing(word);
    node* cursor = hashTable[index];
    while(cursor)
    {
        if(cursor->word == word)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

int add(string word)
{
    if(check(word))
    {
        return true;
    }
    else
    {
        node *newNode = new node;
        newNode->word = word;
        newNode->next = NULL;
        
        int index = hashing(newNode->word);
        node *head = hashTable[index];
        if(!head)
        {
            hashTable[index] = newNode;
        }
        else
        {
            newNode->next = hashTable[index];
            hashTable[index] = newNode;
        }
    }
    return true;
}

int main(void)
{

    while(true)
    {
        char cmd;
        string word;
        cin >> cmd;
        switch(cmd)
        {
            case '+':
            {
                cin >> word;
                add(word);
                break;
            }
            case '?':
            {
                cin >> word;
                printf("%s\n", check(word)?"YES":"NO");
                break;
            }
            default:
                return 0;
        }
    }
}