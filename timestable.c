/*
*TDQC5
*Bruce Cain
*Project 1
*Times Table
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Count the number of digits a number has
int countWidth(
    int num);

// Prints the header 
void printColumn(
    int charWidth,
    int width,
    int min);

// Prints the line between header and products
void printLine(
    int charWidth,
    int width,
    int min);

// Validates command line arguments
int inputValidation(
    int argc,
    char *argv[]);


int main(
    int argc,
    char *argv[])
{
    int row, column, max = 10, valid = 0;
    int min = 1, charWidth = 0;


    // Command line argument validation
    valid = inputValidation(argc, argv);

    if (valid == 1)
    {
        if (atoi(argv[1]) == 0)
        {
            min = 0;
        }

        max = atoi(argv[1]);
    }
    else if (valid == 2)
    {
        min = atoi(argv[1]);
        max = atoi(argv[2]);
    }
    else if (valid == 3)
    {
        printf("Too many arguements or out of bounds.\n");
        printf("Enter one integer for width up to 100\n");
        printf("Enter 2 numbers [[min] max]\n");
        exit(1);
    }

    // Get max Character width
    charWidth = countWidth(max * max) + 1;

    // Printing table lines
    printColumn(charWidth, max, min);
    printLine(charWidth, max, min);

    for (row = min; row <= max; row++)
    {
        for (column = min; column <= max; column++)
        {
            if (column == min)
            {
                printf("%*d\u2502", charWidth, row);
            }

            printf("%*d", charWidth, (row * column));
        }

        printf("\n");
    }

    return 0;
}

int countWidth(
    int num)
{
    /* Counts the number of digits a number has */

    int size = 0;

    if (num == 0)
    {
        num++;
    }

    while (num != 0)
    {
        num /= 10;
        size++;
    }

    return size;
}

void printColumn(
    int charWidth,
    int max,
    int min)
{
    /* Prints the header */
    for (int i = min; i <= max; i++)
    {
        // Checks when to put X at table corner
        if (i == min)
        {
            printf("%*s\u2502", charWidth, "X");
        }

        printf("%*d", charWidth, i);
    }

    printf("\n");
}

void printLine(
    int charWidth,
    int max,
    int min)
{
    /* Prints the line between the header numbers and the products */

    for (int i = min; i <= max + 1; i++)
    {
        for (int j = 0; j < charWidth; j++)
        {
            printf("\u2500");
        }

        // Prints the cross at the corner
        if (i == min)
        {
            printf("\u253C");
        }
    }

    printf("\n");
}

int inputValidation(
    int argc,
    char *argv[])
{
    /* Validates command line arguments */

    int digitBool = 1, valid = 0, j = 0;

    // Checks if arguments are strictly a number
    for (int i = 1; i < argc; i++)
    {
        j = 0;
        while (argv[i][j] != '\0')
        {
            if (!isdigit(argv[i][j]))
            {
                digitBool = 0;
                break;
            }

            j++;
        }

        // If first argument is not a digit dont bother 
        // checking second one
        if (!digitBool)
        {
            break;
        }
    }

    // Checks bounds and correct number of arguments
    if (digitBool && argc == 2 && (atoi(argv[1]) >= 0) && (atoi(argv[1]) <= 100))
    {
        valid = 1;
    }
    else if (digitBool && argc == 3 && (atoi(argv[1]) <= atoi(argv[2])) &&
        (atoi(argv[1]) >= 0) && (atoi(argv[2]) <= 100))
    {
        valid = 2;
    }
    else if (argc != 1 || !(digitBool))
    {
        valid = 3;
    }

    return valid;
}
