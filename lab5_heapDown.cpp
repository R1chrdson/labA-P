#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int *heap;
int size;

int sift_down(int index)
{
    int tmp;
    while(true)
    {
        if(2*(index + 1) < size)
        {
            if(max(heap[2*(index + 1) - 1], heap[2*(index + 1)]) > heap[index])
            {
                int leaf = heap[2*(index + 1) - 1] > heap[2*(index + 1)]?-1:0;
                tmp = heap[2*(index + 1) + leaf];
                heap[2*(index + 1) + leaf] = heap[index];
                heap[index] = tmp;
                index = 2*(index + 1) + leaf;                
            }
            else
            {
                break;
            }
        }
        else if(2*(index + 1) - 1 < size)
        {
            if(heap[2*(index + 1) - 1] > heap[index])
            {
                tmp = heap[2*(index + 1) - 1];
                heap[2*(index + 1) - 1] = heap[index];
                heap[index] = tmp;
                index = 2*(index + 1) - 1;
            }
            else
            {
                break;
            }
            
        }
        else
        {
            break;
        }
    }
    
    return ++index;
}

int main(void)
{
    // init heap
    scanf("%i", &size);
    heap = new int[size];

    // fill heap
    for(int i = 0; i < size; i++)
    {
        scanf("%i", &heap[i]);
    }

    // read queries
    int query;
    scanf("%i", &query);
    for(int i = 0; i < query; i++)
    {
        int index, value;
        scanf("%i%i", &index, &value);
        heap[index - 1] -= value;
        printf("%i\n", sift_down(index - 1));
    }

    // print heap
    for(int i = 0; i < size; i++)
    {
        printf("%i ", heap[i]);
    }
    printf("\n");
}