#include<stdio.h>

int main() {
    int arr[2][3] = { 10,20,30,40,50,60 };
    /* Above array can be initialized as below also
      arr[0][0] = 10; // Initializing array
      arr[0][1] = 20;
      arr[1][0] = 30;
      arr[1][1] = 40; */

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // Accessing variables
            printf("value of arr[%d][%d] : %d\n", i, j, arr[i][j]);
        }
    }

    return 0;
}