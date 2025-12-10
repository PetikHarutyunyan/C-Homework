// Ex 1
#include <stdio.h>

int main() 
{
    int input_n;
    unsigned long long previous_value = 0, current_value = 1, next_value;

    printf("Enter: ");
    if (scanf("%d", &input_n) != 1 || input_n < 0) 
    {
        printf("Invalid input\n");
        return 1;
    }

    if (input_n == 0) 
    {
        printf("Fibonacci %d = 0\n", input_n);
        return 0;
    } 
    else if (input_n == 1) 
    {
        printf("Fibonacci %d = 1\n", input_n);
        return 0;
    }

    for (int index = 2; index <= input_n; index++) 
    {
        next_value = previous_value + current_value;
        previous_value = current_value;
        current_value = next_value;
    }

    printf("Fibonacci %d = %llu\n", input_n, current_value);
    return 0;
}


// Ex 2
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void clean_string(const char source_str[], char cleaned_str[]) 
{
    int clean_index = 0;

    for (int src_index = 0; source_str[src_index] != '\0'; src_index++) 
    {
        if (isalnum(source_str[src_index])) 
        {
            cleaned_str[clean_index++] = tolower(source_str[src_index]);
        }
    }
    cleaned_str[clean_index] = '\0';
}

int is_palindrome(const char processed_str[]) 
{
    int left_index = 0;
    int right_index = strlen(processed_str) - 1;

    while (left_index < right_index) 
    {
        if (processed_str[left_index] != processed_str[right_index]) 
        {
            return 0;
        }
        left_index++;
        right_index--;
    }
    return 1;
}

int main() 
{
    char input_text[100];
    char cleaned_text[100];

    printf("Enter text: ");
    if (!fgets(input_text, sizeof(input_text), stdin)) 
    {
        printf("Input error.\n");
        return 1;
    }

    size_t input_length = strlen(input_text);
    if (input_length > 0 && input_text[input_length - 1] == '\n') 
    {
        input_text[input_length - 1] = '\0';
    }

    clean_string(input_text, cleaned_text);

    if (is_palindrome(cleaned_text)) 
    {
        printf("'%s' is a palindrome.\n", input_text);
    } 
    else 
    {
        printf("'%s' is not a palindrome.\n", input_text);
    }

    return 0;
}


// Ex 3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

double calc_stack[200];
int stack_top = 0;

void push_value(double value) 
{
    calc_stack[stack_top++] = value;
}

double pop_value() 
{
    return calc_stack[--stack_top];
}

int main() 
{
    char input_line[1000];

    printf("Postfix Calculator (+ - * / %%).\n");
    printf("Enter expressions in postfix notation (Ctrl+D to exit).\n");

    while (printf("> "), fgets(input_line, sizeof(input_line), stdin) != NULL) 
    {
        char *current_token = strtok(input_line, " \t\n");
        stack_top = 0;

        while (current_token != NULL) 
        {
            if (isdigit(current_token[0]) || (current_token[0] == '-' && isdigit(current_token[1])))
            {
                push_value(atof(current_token));
            } 
            else 
            {
                if (stack_top < 2) 
                {
                    printf("Error: insufficient operands for '%s'\n", current_token);
                    break;
                }

                double operand_b = pop_value();
                double operand_a = pop_value();

                switch (current_token[0]) 
                {
                    case '+': 
                        push_value(operand_a + operand_b); 
                        break;

                    case '-': 
                        push_value(operand_a - operand_b); 
                        break;

                    case '*': 
                        push_value(operand_a * operand_b); 
                        break;

                    case '/':
                        if (operand_b != 0) 
                        {
                            push_value(operand_a / operand_b);
                        }
                        else 
                        {
                            printf("Error: division by zero\n");
                            stack_top = 0;
                        }
                        break;

                    case '%':
                        if ((int)operand_b != 0) 
                        {
                            push_value((int)operand_a % (int)operand_b);
                        }
                        else 
                        {
                            printf("Error: modulo by zero\n");
                            stack_top = 0;
                        }
                        break;

                    default:
                        printf("Error: unknown operator '%s'\n", current_token);
                        stack_top = 0;
                        break;
                }
            }

            current_token = strtok(NULL, " \t\n");
        }

        if (stack_top == 1) 
        {
            printf("Result: %.2f\n", pop_value());
        } 
        else if (stack_top > 1) 
        {
            printf("Error: too many operands left on stack\n");
        }
    }

    printf("\nExiting calculator.\n");
    return 0;
}
