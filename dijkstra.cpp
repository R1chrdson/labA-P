#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n, s, f;
    cin >> n >> s >> f;
    s--; f--;
    vector<vector<int>> graph;
    graph.reserve(n);
    bool visited[n];
    int distances[n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int integer;
            scanf("%i", &integer);
            graph[i].push_back(integer == -1?INT16_MAX:integer);
        }
    }
    for(int i = 0; i < n; i++)
    {
        distances[i] = graph[s][i];
        visited[i] = false;
    }
    distances[s] = 0;
    int index;
    for(int i = 0; i < n; i++)
    {
        int min = INT16_MAX;
        for(int j = 0; j < n; j++)
        {
            if(!visited[j] && distances[j] < min)
            {
                min = distances[j];
                index = j;
            }
        }
        visited[index] = true;
        distances[s] = 0;
        for(int j = 0; j < n; j++)
        {
            if(!visited[j] && graph[index][j] != INT16_MAX && distances[index] != INT16_MAX && (distances[index]+graph[index][j] < distances[j]))
            {
                distances[j] = distances[index]+graph[index][j];
            }
        }
    }
    printf("%i", distances[f] != INT16_MAX?distances[f]:-1);
}