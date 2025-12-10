#include <stdio.h>
#include <string.h>

int main() 
{
    int n;
    printf("Enter number of names: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 50) 
    {
        printf("Error\n");
        return 1;
    }

    char arr[50][50];

    for (int i = 0; i < n; ++i) 
    {
        scanf("%49s", arr[i]);
    }

    print
#include <stdio.h>

int main() 
{
    int r, c;
    printf("Enter number of rows and columns: ");
    if (scanf("%d %d", &r, &c) != 2 || r <= 0 || c <= 0 || r > 50 || c > 50) 
    {
        printf("Invalid input.\n");
        return 1;
    }

    int mat[50][50], tmat[50][50];

    printf("Enter elements of the matrix:\n");

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            tmat[j][i] = mat[i][j];
        }
    }

    printf("\nTranspose of the matrix:\n");

    for (int i = 0; i < c; ++i) 
    {
        for (int j = 0; j < r; ++j)
        {
            printf("%d ", tmat[i][j]);
        }
        printf("\n");
    }

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    int n = 10;

    if (argc == 2 && argv[1][0] == '-') 
    {
        n = atoi(argv[1] + 1);
        if (n <= 0) n = 10;
    }

    char buf[500][50];
    int cnt = 0;

    printf("Enter text (Ctrl+D to end input):\n");

    while (cnt < 500 && fgets(buf[cnt], 50, stdin) != NULL) 
    {
        cnt++;
    }

    int start = (cnt - n) > 0 ? cnt - n : 0;

    printf("\nLast %d lines:\n", n);

    for (int i = start; i < cnt; ++i) 
    {
        printf("%s", buf[i]);
    }

    return 0;
}
#include <stdio.h>
#include <string.h>

void sort_strings(char arr[][100], int n, int (*cmp)(const char*, const char*)) 
{
    char tmp[100];

    for (int i = 0; i < n - 1; ++i) 
    {
        for (int j = i + 1; j < n; ++j) 
        {
            if (cmp(arr[i], arr[j]) > 0) 
            {
                strcpy(tmp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], tmp);
            }
        }
    }
}

int alpha_cmp(const char *a, const char *b) 
{
    return strcmp(a, b);
}

int main() 
{
    int n;
    char arr[100][100];

    printf("Enter number of strings: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 100) 
    {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter %d strings:\n", n);

    for (int i = 0; i < n; ++i) 
    {
        scanf("%49s", arr[i]);
    }

    sort_strings(arr, n, alpha_cmp);

    printf("\nSorted strings:\n");

    for (int i = 0; i < n; ++i) 
    {
        printf("%s\n", arr[i]);
    }

    return 0;
}
