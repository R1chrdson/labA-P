#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;
    int matrix[n][m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int weight;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if (i == 0 && j != 0)
            {
                matrix[i][j] += matrix[i][j - 1];
            }
            else if (i != 0 && j == 0)
            {
                matrix[i][j] += matrix[i -1][j];
            }
            else if(i != 0 && j != 0)
            {
                int top = matrix[i - 1][j];
                int left = matrix[i][j - 1];
                int minimal = min(top, left);
                matrix[i][j] += minimal;
            }      
        }
    }
    cout << matrix[n - 1][m - 1] << endl;
}