// Ex 1

#include <stdio.h>

typedef struct 
{
    int h, m, s;
} Time;

Time sum(Time t1, Time t2) 
{
    Time result;
    result.s = t1.s + t2.s;
    result.m = t1.m + t2.m + result.s / 60;
    result.s %= 60;
    result.h = t1.h + t2.h + result.m / 60;
    result.m %= 60;
    return result;
}

int main() 
{
    Time t1, t2, t_sum;

    printf("Enter first time (hh mm ss): ");
    if (scanf("%d %d %d", &t1.h, &t1.m, &t1.s) != 3) 
    {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter second time (hh mm ss): ");
    if (scanf("%d %d %d", &t2.h, &t2.m, &t2.s) != 3) 
    {
        printf("Invalid input.\n");
        return 1;
    }

    t_sum = sum(t1, t2);

    printf("Sum of times: %02d:%02d:%02d\n", t_sum.h, t_sum.m, t_sum.s);
    return 0;
}

// ex 2

#include <stdio.h>

typedef struct {
    float real;
    float imag;
} Complex;

Complex complex_add(Complex a, Complex b) 
{
    Complex res;
    res.real = a.real + b.real;
    res.imag = a.imag + b.imag;
    return res;
}

Complex complex_mul(Complex a, Complex b) 
{
    Complex res;
    res.real = a.real * b.real - a.imag * b.imag;
    res.imag = a.real * b.imag + a.imag * b.real;
    return res;
}

int main() 
{
    Complex num1, num2, sum, product;

    printf("Enter first complex number (real imag): ");
    if (scanf("%f %f", &num1.real, &num1.imag) != 2) 
    {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter second complex number (real imag): ");
    if (scanf("%f %f", &num2.real, &num2.imag) != 2) 
    {
        printf("Invalid input.\n");
        return 1;
    }

    sum = complex_add(num1, num2);
    product = complex_mul(num1, num2);

    printf("Sum: %.2f + %.2fi\n", sum.real, sum.imag);
    printf("Product: %.2f + %.2fi\n", product.real, product.imag);

    return 0;
}

// Ex 3

#include <stdio.h>

typedef union 
{
    int temperature;
    float pressure;
    float humidity;
} SensorData;

int main() 
{
    SensorData sensor;
    int choice;

    printf("Select sensor type:\n1. Temperature\n2. Pressure\n3. Humidity\n");
    printf("Enter choice: ");

    if (scanf("%d", &choice) != 1) 
    {
        printf("Invalid input.\n");
        return 1;
    }

    switch (choice) 
    {
        case 1:
            printf("Enter temperature (int): ");
            if (scanf("%d", &sensor.temperature) != 1) 
            {
                printf("Invalid input.\n");
                return 1;
            }
            printf("Sensor Type: Temperature\nReading: %d\n", sensor.temperature);
            break;

        case 2:
            printf("Enter pressure (float): ");
            if (scanf("%f", &sensor.pressure) != 1) 
            {
                printf("Invalid input.\n");
                return 1;
            }
            printf("Sensor Type: Pressure\nReading: %.2f\n", sensor.pressure);
            break;

        case 3:
            printf("Enter humidity (float): ");
            if (scanf("%f", &sensor.humidity) != 1) 
            {
                printf("Invalid input.\n");
                return 1;
            }
            printf("Sensor Type: Humidity\nReading: %.2f\n", sensor.humidity);
            break;

        default:
            printf("Invalid choice!\n");
            return 1;
    }

    return 0;
}
