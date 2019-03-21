#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{
    
    int n, m;
    cin >> n >> m;
    int matrix[n][m];
    int result[n][m];
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
            if(i == 0 && j == 0)
            {
                result[i][j] = matrix[i][j];
            }
            else if (i == 0)
            {
                result[i][j] = matrix[i][j] + result[i][j - 1];
            }
            else if (j == 0)
            {
                result[i][j] = matrix[i][j] + result[i -1][j];
            }
            else
            {
                int top = result[i - 1][j];
                int left = result[i][j - 1];
                int minimal = min(top, left);
                result[i][j] = matrix[i][j] + minimal;
            }
            
        }
    }
    cout << result[n - 1][m - 1] << endl;
}