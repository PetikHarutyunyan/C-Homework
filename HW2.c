// Ex 3-2
#include <stdio.h>

int encode_vis(char out[], char in[])
{
    int inIdx = 0, outIdx = 0;
    for (inIdx = 0; in[inIdx] != '\0'; ++inIdx)
    {
        char curr = in[inIdx];
        if (curr == '\n')
        {
            out[outIdx++] = '\\';
            out[outIdx++] = 'n';
        } 
        else if (curr == '\t')
        {
            out[outIdx++] = '\\';
            out[outIdx++] = 't';
        } 
        else if (curr == '\\')
        {
            out[outIdx++] = '\\';
            out[outIdx++] = '\\';
        } 
        else
        {
            out[outIdx++] = curr;
        }
    }
    out[outIdx] = '\0';
    return outIdx;
}

int decode_vis(char out[], char in[])
{
    int readIdx = 0, writeIdx = 0;
    while (in[readIdx] != '\0') 
    {
        if (in[readIdx] == '\\') 
        {
            char nextCh = in[readIdx + 1];
            if (nextCh == 'n') 
            {
                out[writeIdx++] = '\n';
                readIdx += 2;
            } 
            else if (nextCh == 't') 
            {
                out[writeIdx++] = '\t';
                readIdx += 2;
            } 
            else if (nextCh == '\\') 
            {
                out[writeIdx++] = '\\';
                readIdx += 2;
            } 
            else if (nextCh == '\0') 
            {
                out[writeIdx++] = '\\';
                readIdx++;
            } 
            else 
            {
                out[writeIdx++] = '\\';
                out[writeIdx++] = nextCh;
                readIdx += 2;
            }
        } 
        else 
        {
            out[writeIdx++] = in[readIdx++];
        }
    }
    out[writeIdx] = '\0';
    return writeIdx;
}

int main() 
{
    int inputChar;
    int pos = 0;
    char buffer[150];

    printf("Enter text (Ctrl+D to end):\n");
    while ((inputChar = getchar()) != EOF && pos < (int)sizeof(buffer) - 1) 
    {
        buffer[pos++] = (char)inputChar;
    }
    buffer[pos] = '\0';

    char encoded[300];
    char decoded[150];

    encode_vis(encoded, buffer);
    printf("Escaped: %s\n", encoded);

    decode_vis(decoded, encoded);
    printf("Unescaped: %s\n", decoded);

    return 0;
}
// Ex 3-3
#include <stdio.h>
#include <ctype.h>

void unfold(char in[], char out[]) 
{
    int readPos = 0, writePos = 0;
    char leftCh, rightCh;

    while (in[readPos] != '\0') 
    {
        if (in[readPos] == '-' && readPos > 0 && in[readPos + 1] != '\0') 
        {
            leftCh = in[readPos - 1];
            rightCh = in[readPos + 1];

            if ((isdigit(leftCh) && isdigit(rightCh) && leftCh < rightCh) ||
                (islower(leftCh) && islower(rightCh) && leftCh < rightCh) ||
                (isupper(leftCh) && isupper(rightCh) && leftCh < rightCh)) 
            {
                for (char step = leftCh + 1; step <= rightCh; step++) 
                {
                    out[writePos++] = step;
                    readPos++;
                }
            } 
            else 
            {
                out[writePos++] = '-';
            }
        } 
        else 
        {
            out[writePos++] = in[readPos];
        }
        readPos++;
    }
    out[writePos] = '\0';
}

int main() 
{
    char input[100], output[500];

    printf("Enter shorthand: ");
    fgets(input, sizeof(input), stdin);

    unfold(input, output);

    printf("Expanded: %s\n", output);
    return 0;
}
// Ex 3-5
#include <stdio.h>
#include <string.h>

static void flip(char buf[]) 
{
    int left = 0, right = (int)strlen(buf) - 1;
    while (left < right) 
    {
        char tmp = buf[left];
        buf[left++] = buf[right];
        buf[right--] = tmp;
    }
}

void num_to_base(int value, char out[], int base) 
{
    if (base < 2 || base > 36) 
    { 
        out[0] = '\0'; 
        return; 
    }

    unsigned int valUnsigned;
    if (value < 0) 
        valUnsigned = (unsigned int)(-(long)value);
    else 
        valUnsigned = (unsigned int)value;

    int outPos = 0;

    do 
    {
        int digit = valUnsigned % base;
        out[outPos++] = (digit < 10) ? ('0' + digit) : ('A' + (digit - 10));
        valUnsigned /= base;
    } while (valUnsigned > 0);

    if (value < 0 && base == 10) 
        out[outPos++] = '-';

    out[outPos] = '\0';

    flip(out);
}

int main() 
{
    int num, base;
    char result[100];

    printf("Enter an integer: ");
    if (scanf("%d", &num) != 1) 
    {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter base (2-36): ");
    if (scanf("%d", &base) != 1 || base < 2 || base > 36) 
    {
        printf("Invalid base.\n");
        return 1;
    }

    num_to_base(num, result, base);

    printf("Number %d in base %d is: %s\n", num, base, result);

    return 0;
}
