// -----------------------CLI Based Calculator----------------------------//
#include <math.h>   // For math functions like sin, cos, tan, pow, log, etc.
#include <stdio.h>  // For input/output functions
#include <stdlib.h> // For strtof, exit, etc.
#include <string.h> // For string comparison (strcmp)

// Define PI if not already defined (for degree-to-radian conversion)
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// ------------------ Function Declarations ------------------ //
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);
float modulo(float a, float b);
float power(float a, float b);
float floor_division(float a, float b);
float square_root(float a);
float log_base_10(float a);
float natural_log(float a);
float absolute(float a);
float cosine(float a);
float sine(float a);
float tangent(float a);
float exponential(float a);
void print_result(float result);
int calculate_single_operand(char *operation, char *value);
int calculate_dual_operands(char *num1_str, char *operator_str, char *num2_str);

// -------------- Entry Point --------------------//
int main(int argc, char *argv[])
{
    // Determine if it's a single-operand or dual-operand operation
    if (argc == 3)
    {
        return calculate_single_operand(argv[1], argv[2]);
    }
    else if (argc == 4)
    {
        return calculate_dual_operands(argv[1], argv[2], argv[3]);
    }
    else
    {
        // Invalid argument count
        printf("Error: Invalid number of arguments.\n");
        printf("Usage: ./cli-calculator <num1> <operator> <num2>\n");
        printf("Or: ./cli-calculator <operation> <num>\n");
        printf("Supported single operations: sqrt, log, ln, abs, cos, sin, tan, exp\n");
        return 1;
    }
}

// ---------------------- Logic for Dual Operand ---------------------- //
int calculate_dual_operands(char *num1_str, char *operator_str, char *num2_str)
{
    // Convert string arguments to float values
    char *endptr1, *endptr2;
    float num1 = strtof(num1_str, &endptr1);
    float num2 = strtof(num2_str, &endptr2);

    // Check for invalid input
    if (*endptr1 != '\0' || *endptr2 != '\0')
    {
        printf("Error: Invalid number format.\n");
        return 4;
    }

    // Check for division or modulo by zero
    if ((strcmp(operator_str, "/") == 0 || strcmp(operator_str, "%") == 0) && num2 == 0)
    {
        printf("Error: Division or modulo by zero.\n");
        return 3;
    }

    float result;

    // Handle power operation separately (**)
    if (strcmp(operator_str, "**") == 0)
    {
        result = power(num1, num2);
    }
    else
    {
        // Handle other dual-operand operators
        char operator = operator_str[0];
        switch (operator)
        {
            case '+':
                result = add(num1, num2);
                break;
            case '-':
                result = subtract(num1, num2);
                break;
            case '*':
                result = multiply(num1, num2);
                break;
            case '/':
                result = divide(num1, num2);
                break;
            case '%':
                result = modulo(num1, num2);
                break;
            default:
                printf("Error: Invalid Operator\n");
                return 2;
        }
    }

    print_result(result);
    return 0;
}

// ---------------------- Logic for Single Operand ---------------------- //
int calculate_single_operand(char *operation, char *value)
{
    // Convert input string to float
    char *endptr;
    float num = strtof(value, &endptr);

    // Check for invalid input
    if (*endptr != '\0')
    {
        printf("Error: Invalid number format.\n");
        return 4;
    }

    float result;

    // Handle different single-operand operations
    if (strcmp(operation, "sqrt") == 0)
    {
        if (num < 0)
        {
            printf("Error: Square root of negative number.\n");
            return 5;
        }
        result = square_root(num);
    }
    else if (strcmp(operation, "log") == 0)
    {
        if (num <= 0)
        {
            printf("Error: Logarithm of non-positive number.\n");
            return 6;
        }
        result = log_base_10(num);
    }
    else if (strcmp(operation, "ln") == 0)
    {
        if (num <= 0)
        {
            printf("Error: Natural log of non-positive number.\n");
            return 7;
        }
        result = natural_log(num);
    }
    else if (strcmp(operation, "abs") == 0)
    {
        result = absolute(num);
    }
    else if (strcmp(operation, "cos") == 0)
    {
        result = cosine(num);
    }
    else if (strcmp(operation, "sin") == 0)
    {
        result = sine(num);
    }
    else if (strcmp(operation, "tan") == 0)
    {
        result = tangent(num);
    }
    else if (strcmp(operation, "exp") == 0)
    {
        result = exponential(num);
    }
    else
    {
        printf("Error: Invalid single operand operation.\n");
        return 2;
    }

    print_result(result);
    return 0;
}

// ---------------------- Print Result ---------------------- //
void print_result(float result)
{
    // Treat very small values as zero
    if (fabsf(result) < 1e-6)
        result = 0.0;

    // Print without decimals if it's a whole number
    if (result == (int) result)
        printf("%.0f\n", result);
    else
        printf("%g\n", result); // Print floating point with trimmed zeros
}

// ---------------------- Math Operations ---------------------- //
float add(float a, float b)
{
    return a + b;
}

float subtract(float a, float b)
{
    return a - b;
}

float multiply(float a, float b)
{
    return a * b;
}

float divide(float a, float b)
{
    return a / b;
}

float modulo(float a, float b)
{
    return fmod(a, b); // Floating-point remainder
}

float power(float a, float b)
{
    return powf(a, b); // a^b
}

float floor_division(float a, float b)
{
    return floor(a / b); // Not used directly, but defined
}

float square_root(float a)
{
    return sqrtf(a);
}

float log_base_10(float a)
{
    return log10f(a);
}

float natural_log(float a)
{
    return logf(a); // ln(a)
}

float absolute(float a)
{
    return fabsf(a);
}

float cosine(float a)
{
    return cosf(a * (M_PI / 180.0f)); // Convert degrees to radians
}

float sine(float a)
{
    return sinf(a * (M_PI / 180.0f)); // Convert degrees to radians
}

float tangent(float a)
{
    // Check for undefined tangent values at 90, 270, etc.
    if (fmodf(fabsf(a), 180.0f) == 90.0f)
    {
        printf("Error: Tangent undefined at %g degrees.\n", a);
        exit(8); // Exit with specific error code
    }

    return tanf(a * (M_PI / 180.0f)); // Convert degrees to radians
}

float exponential(float a)
{
    return expf(a); // e^a
}
