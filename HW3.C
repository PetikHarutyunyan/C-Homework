// Ex 1
#include <stdio.h>

int prime_check(int num) 
{
    if (num < 2) return 0;

    for (int d = 2; d * d <= num; ++d)
    {
        if (num % d == 0)
            return 0;
    }
    return 1;
}

void find_prime_pairs(int target) 
{
    int found = 0;

    for (int left = 2; left <= target / 2; ++left) 
    {
        int right = target - left;

        if (prime_check(left) && prime_check(right)) 
        {
            printf("%d + %d = %d\n", left, right, target);
            found = 1;
        }
    }

    if (!found)
        printf("No combination to %d.\n", target);
}

int main() 
{
    int input;

    printf("Enter positive integer: ");
    if (scanf("%d", &input) != 1 || input <= 0) 
    {
        printf("Error\n");
        return 1;
    }

    printf("Sum: %d\n", input);
    find_prime_pairs(input);

    return 0;
}
// Ex 2
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    char buf[256];
    int lhs, rhs;
    char op;

    printf("Enter: \n");

    while (fgets(buf, sizeof(buf), stdin) != NULL) 
    {
        if (sscanf(buf, " %d %c %d", &lhs, &op, &rhs) == 3) 
        {
            switch (op) 
            {
                case '+':
                    printf("= %d\n", lhs + rhs);
                    break;

                case '-':
                    printf("= %d\n", lhs - rhs);
                    break;

                case '*':
                    printf("= %d\n", lhs * rhs);
                    break;

                case '/':
                    if (rhs == 0)
                        printf("Error\n");
                    else
                        printf("= %d\n", lhs / rhs);
                    break;

                case '%':
                    if (rhs == 0)
                        printf("Error\n");
                    else
                        printf("= %d\n", lhs % rhs);
                    break;

                default:
                    printf("Error '%c'\n", op);
                    break;
            }
        }
        else 
        {
            printf("Error: invalid expression\n");
        }
    }

    printf("Exiting calculator.\n");
    return 0;
}

// Ex 3
#include <stdio.h>

void build_pyramid(int height) 
{
    int row, spaces, stars;

    for (row = 1; row <= height; ++row) 
    {
        for (spaces = 1; spaces <= height - row; ++spaces)
            putchar(' ');

        for (stars = 1; stars <= row; ++stars)
            printf("* ");

        putchar('\n');
    }
}

int main() 
{
    int count;

    printf("Input number of rows: ");
    if (scanf("%d", &count) != 1 || count <= 0) 
    {
        printf("Invalid input.\n");
        return 1;
    }

    build_pyramid(count);
    return 0;
}

