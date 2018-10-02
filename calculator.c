/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: 2DHIF
 * ---------------------------------------------------------
 * Exercise Number: 2
 * Title:			Calculator
 * Author:			David Kraus
 * ----------------------------------------------------------
 * Description:
 * A basic calculator with basic functionalities,
 * e.g. addition, subtraction, multiplication and division
 * The calculator is also able to calculate the power of
 * a number.
 * ----------------------------------------------------------
*/

#include <stdio.h>
#include <float.h>
#include <stdbool.h>

#define SELECTION_MAX        5
#define CALCULATION_SUCCEDED 0
#define OVERFLOW_ERROR      -1
#define UNDERFLOW_ERROR     -2

bool isInputValid(int* input)
{
    return ((*input) >= -1 && (*input) <= SELECTION_MAX);
}

void get_operands(double* firstOperand, double* secondOperand)
{
    printf("Please enter the first operand: ");
    scanf("%lf", firstOperand);
    printf("Please enter the second operand: ");
    scanf("%lf", secondOperand);
}

int perform_power_calculation(double *firstOperand, double* secondOperand, double* result)
{
    *result = 1;
    for (int i = 0; i < *secondOperand; i++)
    {
        if (*result * *firstOperand > DBL_MAX) return OVERFLOW_ERROR;
        if (*result * *firstOperand < -DBL_MAX) return UNDERFLOW_ERROR;
        *result *= *firstOperand;
    }
    return 0;
}

int perform_operation(int* operation, double* firstOperand, double* secondOperand)
{
    double result = 0.0;
    int status = 0;
    switch (*operation)
    {
        case 1:
            if (*firstOperand + *secondOperand > DBL_MAX) { return OVERFLOW_ERROR;  }
            if (*firstOperand + *secondOperand < -DBL_MAX) { return UNDERFLOW_ERROR; }
            result = *firstOperand + *secondOperand;
            break;
        case 2:
            if (*firstOperand - *secondOperand > DBL_MAX) { return OVERFLOW_ERROR;  }
            if (*firstOperand - *secondOperand < -DBL_MAX) { return UNDERFLOW_ERROR; }
            result = *firstOperand - *secondOperand;
            break;
        case 3:
            if (*firstOperand * *secondOperand > DBL_MAX) { return OVERFLOW_ERROR;  }
            if (*firstOperand * *secondOperand < -DBL_MAX) { return UNDERFLOW_ERROR; }
            result = *firstOperand * *secondOperand;
            break;
        case 4:
            if (*firstOperand / *secondOperand > DBL_MAX) { return OVERFLOW_ERROR;  }
            if (*firstOperand / *secondOperand < -DBL_MAX) { return UNDERFLOW_ERROR; }
            result = *firstOperand / *secondOperand;
            break;
        case 5:
            status = perform_power_calculation(firstOperand, secondOperand, &result);
            if (status != CALCULATION_SUCCEDED) { return status; }
            break;
    }
    printf("\nResult: %4.3lf\n\n", result);
    return CALCULATION_SUCCEDED;
}

void request_user_action(int* user_action)
{
    printf("Choose one of the following operations:\n");
    printf("\tAdd (1)\n");
    printf("\tSubtract (2)\n");
    printf("\tMultiply (3)\n");
    printf("\tDivide (4)\n");
    printf("\tPower (5)\n");
    printf("\tStop program (-1)\n");
    do
    {
        if (user_action != NULL && !isInputValid(user_action))
        {
            printf("Input not allowed, please try again\n\n");
        }
        printf("Enter your choice: ");
        scanf("%d", user_action);
    } while (!isInputValid(user_action));
}

int main(int argc, const char *argv[])
{
    int user_input;
    double first_number;
    double second_number;
    do
    {
        request_user_action(&user_input);
        if (user_input != -1)
        {
            get_operands(&first_number, &second_number);
            int calculation_status = perform_operation(&user_input, &first_number, &second_number);
            if (calculation_status == OVERFLOW_ERROR)
            {
                printf("Number overflow\n");
            }
            else if (calculation_status == UNDERFLOW_ERROR)
            {
                printf("Number underflow\n");
            }
        }
    }
    while(user_input != -1);

    return 0;
}
