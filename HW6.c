//EX1

#include <stdio.h>

void dbl(int *p) 
{
    *p *= 2;
}

int main(void) 
{
    int a;
    printf("Enter a number: ");
    if (scanf("%d", &a) != 1) 
    {
        printf("Invalid input.\n");
        return 1;
    }
    dbl(&a);
    printf("Doubled value: %d\n", a);
    return 0;
}


//EX2
#include <stdio.h>

void calc(int *p, int n, int *s, float *avg) 
{
    *s = 0;
    for (int i = 0; i < n; ++i)
    {
        *s += *(p + i);
    }
    *avg = (float)(*s) / n;
}

int main() 
{
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) 
    {
        printf("Invalid input.\n");
        return 1;
    }

    int arr[n];
    int *ptr = arr;

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", ptr + i);
    }

    int s;
    float avg;

    calc(ptr, n, &s, &avg);

    printf("Sum = %d\n", s);
    printf("Average = %.2f\n", avg);

    return 0;
}


//EX3
#include <stdio.h>

void copy(int *src, int *dst, int n) 
{
    for (int i = 0; i < n; ++i)
    {
        *(dst + i) = *(src + i);
    }
}

int main() 
{
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) 
    {
        printf("Invalid input.\n");
        return 1;
    }

    int a[n], b[n];
    int *pa = a, *pb = b;

    printf("Enter %d elements for array A:\n", n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", pa + i);
    }

    copy(pa, pb, n);

    printf("Array B after copying:\n");
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", *(pb + i));
    }

    printf("\n");
    return 0;
}


//EX4
#include <stdio.h>
#include <stdlib.h>

void push(int *stk, int *t, int v) 
{
    if (*t >= 50 - 1) {
        printf("Stack overflow!\n");
        return;
    }
    (*t)++;
    *(stk + *t) = v;
}

int pop(int *stk, int *t) 
{
    if (*t < 0) {
        printf("Stack underflow!\n");
        return -1;
    }
    int v = *(stk + *t);
    (*t)--;
    return v;
}

void show(int *stk, int t) 
{
    if (t < 0) 
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = t; i >= 0; --i)
    {
        printf("%d ", *(stk + i));
    }
    printf("\n");
}

int main() 
{
    int stk[50], t = -1, ch, v;

    do {
        printf("\n1.Push  2.Pop  3.Display  4.Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &ch) != 1) 
        {
            printf("Invalid input.\n");
            break;
        }

        switch (ch) 
        {
            case 1:
                printf("Enter value to push: ");
                if (scanf("%d", &v) != 1) 
                {
                    printf("Invalid input.\n");
                    break;
                }
                push(stk, &t, v);
                break;

            case 2:
                v = pop(stk, &t);
                if (v != -1)
                    printf("Popped: %d\n", v);
                break;

            case 3:
                show(stk, t);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (ch != 4);

    return 0;
}
