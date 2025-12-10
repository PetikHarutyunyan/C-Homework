// Ex 1
#include <stdio.h>

void int_to_string(int input_number, char output_str[]) 
{
    int temp_number = input_number;
    int index = 0;
    int is_negative = 0;

    if (input_number < 0) 
    {
        is_negative = 1;
        temp_number = -temp_number;
    }

    int digit_count = 0;
    int digit_counter = temp_number;

    do 
    {
        digit_counter /= 10;
        digit_count++;
    } while (digit_counter != 0);

    int total_length = digit_count + is_negative;

    output_str[total_length] = '\0';
    index = total_length - 1;

    while (digit_count--) 
    {
        output_str[index--] = (temp_number % 10) + '0';
        temp_number /= 10;
    }

    if (is_negative)
    {
        output_str[0] = '-';
    }
}

int main() 
{
    int input_value;
    char result_string[50];

    printf("Input: ");

    if (scanf("%d", &input_value) != 1) 
    {
        printf("Error\n");
        return 1;
    }

    int_to_string(input_value, result_string);

    printf("String: %s\n", result_string);
    return 0;
}


// Ex 2
#include <stdio.h>

int main() 
{
    int menu_choice;
    float first_number, second_number, result_value;

    while (1) 
    {
        printf("1. Add\n2. Sub\n3. Mult\n4. Div\n5. Quit\n");
        printf("Choose: ");

        if (scanf("%d", &menu_choice) != 1) 
        {
            printf("Error\n");
            return 1;
        }

        if (menu_choice == 5) 
        {
            printf("...\n");
            break;
        }

        if (menu_choice < 1 || menu_choice > 5) 
        {
            printf("Error\n");
            continue;
        }

        printf("Input first: ");
        if (scanf("%f", &first_number) != 1) 
        {
            printf("Error\n");
            return 1;
        }

        printf("Input second: ");
        if (scanf("%f", &second_number) != 1) 
        {
            printf("Error\n");
            return 1;
        }

        switch (menu_choice) 
        {
            case 1:
                result_value = first_number + second_number;
                printf("Result: %.3f\n", result_value);
                break;

            case 2:
                result_value = first_number - second_number;
                printf("Result: %.3f\n", result_value);
                break;

            case 3:
                result_value = first_number * second_number;
                printf("Result: %.3f\n", result_value);
                break;

            case 4:
                if (second_number == 0) 
                {
                    printf("Error\n");
                } 
                else 
                {
                    result_value = first_number / second_number;
                    printf("Result: %.3f\n", result_value);
                }
                break;
        }
    }

    return 0;
}


// Ex 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    int user_guess;
    int target_number;

    srand((unsigned int)time(NULL));
    target_number = rand() % 100 + 1;

    printf("Guess 1-100: ");

    while (1) 
    {
        if (scanf("%d", &user_guess) != 1) 
        {
            printf("Error\n");
            return 1;
        }

        if (user_guess < target_number) 
        {
            printf("Low try again: ");
        } 
        else if (user_guess > target_number) 
        {
            printf("High try again: ");
        } 
        else 
        {
            printf("You are right\n");
            break;
        }
    }

    return 0;
}
