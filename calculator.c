#include <stdio.h>
#include <float.h>
#include <stdbool.h>

bool isInputValid(int* input)
{
    return ((*input) >= -1 && (*input) <= 4);
}

void get_operands(double* firstOperand, double* secondOperand)
{
    printf("Please enter the first operand: ");
    scanf("%lf", firstOperand);
    printf("Please enter the second operand: ");
    scanf("%lf", secondOperand);
}

bool check_calculation(double operationResult, double* resultStorage)
{
    if (operationResult > DBL_MAX)
    {
        printf("Number overflow\n\n");
        return false;
    }
    else if (operationResult < DBL_MIN)
    {
        printf("Number underflow\n\n");
        return false;
    }

    *resultStorage = operationResult;
    return true;
}

void perform_operation(int* operation, double* firstOperand, double* secondOperand)
{
    double result;
    switch (*operation)
    {
        case 1:
            check_calculation(*firstOperand + *secondOperand, &result);
            break;
        case 2:
            result = *firstOperand - *secondOperand;
            break;
        case 3:
            check_calculation(*firstOperand * *secondOperand, &result);
            break;
        case 4:
            if (*secondOperand == 0)
            {
                printf("Division by zero\n\n");
                return;
            }
            result = *firstOperand / *secondOperand;
            break;
    }
    printf("\nResult: %lf\n\n", result);
}

void request_user_action(int* user_action)
{
    printf("Choose one of the following operations:\n");
    printf("\tAdd (1)\n");
    printf("\tSubtract (2)\n");
    printf("\tMultiply (3)\n");
    printf("\tDivide (4)\n");
    printf("\tStop program (-1)\n");
    do
    {
        if (!isInputValid(user_action))
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
            perform_operation(&user_input, &first_number, &second_number);
        }
    }
    while(user_input != -1);

    return 0;
}
