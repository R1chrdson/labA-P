#include <stdio.h>
#include <iostream>

using namespace std;

int *heap;

int sift_up(int index)
{
    int tmp;
    while (heap[index] >= heap[(index - 1)/2] && index != 0)
    {
        tmp = heap[(index - 1)/2];
        heap[(index - 1)/2] = heap[index];
        heap[index] = tmp;
        index = (index - 1) / 2;
    }
    return ++index;
}

int main(void)
{
    // init heap
    int size;
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
        heap[index - 1] += value;
        printf("%i\n", sift_up(index - 1));
    }

    // print heap
    for(int i = 0; i < size; i++)
    {
        printf("%i ", heap[i]);
    }
    printf("\n");
}