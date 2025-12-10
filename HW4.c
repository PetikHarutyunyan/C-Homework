// Ex 7
#include <stdio.h>

int main() 
{
    int n;
    printf("Input: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 50) 
    {
        printf("Error\n");
        return 1;
    }

    int arr[50];
    int *ptr = arr;

    for (int i = 0; i < n; ++i) 
    {
        printf(" el - %d : ", i);
        if (scanf("%d", ptr + i) != 1) 
        {
            printf("Error\n");
            return 1;
        }
    }

    printf(" : \n");
    for (int i = 0; i < n; ++i) 
    {
        printf(" el - %d : %d \n", i, *(ptr + i));
    }

    return 0;
}
// Ex 8
#include <stdio.h>
#include <string.h>

void swap_chars(char *a, char *b) 
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char *str, int left, int right) 
{
    if (left == right) 
    {
        printf("%s  ", str);
    } 
    else 
    {
        for (int i = left; i <= right; ++i) 
        {
            swap_chars(&str[left], &str[i]);
            permute(str, left + 1, right);
            swap_chars(&str[left], &str[i]);
        }
    }
}

int main() 
{
    char text[50];
    printf("Input: ");
    if (scanf("%49s", text) != 1) return 0;

    int len = (int)strlen(text);
    printf("\nPermutations:\n");

    permute(text, 0, len - 1);

    printf("\n\n");
    return 0;
}
// Ex 14
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int n;
    printf("Ptr sort:\n\n");
    printf("n: ");

    if (scanf("%d", &n) != 1 || n <= 0) 
    {
        printf("Error\n");
        return 1;
    }

    int arr[n];
    int *ptr = arr;
    int i, j, temp;

    printf("values:\n");
    for (i = 0; i < n; ++i) 
    {
        printf("%d: ", i + 1);
        if (scanf("%d", ptr + i) != 1) 
        {
            printf("Invalid input.\n");
            return 1;
        }
    }

    for (i = 0; i < n; ++i) 
    {
        for (j = i + 1; j < n; ++j) 
        {
            if (*(ptr + i) > *(ptr + j)) 
            {
                temp = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = temp;
            }
        }
    }

    printf("\nsorted:\n");
    for (i = 0; i < n; ++i) 
    {
        printf("%d: %d\n", i + 1, *(ptr + i));
    }

    return 0;
}
// Ex 21
#include <stdio.h>

int main() 
{
    char arr[26];
    char *p = arr;
    int i;

    for (i = 0; i < 26; ++i)
    {
        *(p++) = 'A' + i;
    }

    p = arr;

    for (i = 0; i < 26; ++i) 
    {
        printf("%c ", *(p++));
    }

    putchar('\n');
    return 0;
}
// Ex 22
#include <stdio.h>
#include <string.h>

int main() 
{
    char src[200], dest[200];
    char *rp = src, *wp = dest;
    int len;

    printf("Input: ");
    if (!fgets(src, sizeof(src), stdin)) 
    {
        return 0;
    }

    len = (int)strlen(src);
    if (len > 0 && src[len - 1] == '\n') 
    {
        src[--len] = '\0';
    }

    rp = src + len;
    while (rp > src) 
    {
        --rp;
        *wp++ = *rp;
    }

    *wp = '\0';

    printf("Reversed: %s\n", dest);
    return 0;
}
