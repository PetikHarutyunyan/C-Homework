#include <stdio.h>
#include <string.h>

int main() {

// Ex 13
    char input_line[1000];

    while (fgets(input_line, sizeof(input_line), stdin) != NULL)
    {
        int line_length = strlen(input_line) - 1;   // exclude '\n'

        printf("Len: %d ", line_length);

        for (int star_index = 0; star_index < line_length; star_index++)
        {
            printf("*");
        }

        printf("\n");
    }

    // Ex 17
    
    char input_line[1000];

    while (fgets(input_line, sizeof(input_line), stdin) != NULL)
    {
        if (strlen(input_line) > 80)
        {
            printf("%s", input_line);
        }
    }
    

// Ex 19
    
    char input_line[1000];

    while (fgets(input_line, sizeof(input_line), stdin) != NULL)
    {
        int original_length = strlen(input_line);

        input_line[original_length - 1] = '\0';  // remove '\n'
        original_length--;

        for (int left_index = 0, right_index = original_length - 1;
             left_index < right_index;
             left_index++, right_index--)
        {
            char temp_char = input_line[left_index];
            input_line[left_index] = input_line[right_index];
            input_line[right_index] = temp_char;
        }

        if (strlen(input_line) > 0)
        {    
            printf("%s\n", input_line);
        }
    }
    

    return 0;
}