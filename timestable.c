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
int countWidth(int num);
// Prints the line between row header and products
void printColumn(int charWidth, int width);
// Prints the line between header and products
void printLine(int charWidth, int width);
// Validates command line arguments
int inputValidation(int argc, char *argv[]);


int main(int argc, char *argv[])
{
    int row, column, height = 10, width = 10, valid = 0;
    int charWidth = countWidth(height * width) + 1;

    // Command line argument validation
    valid = inputValidation(argc, argv);
    if (valid == 1)
    {
        width = atoi(argv[1]);
        height = atoi(argv[1]);
        charWidth = countWidth(height * width) + 1;
    }
    else if (valid == 2)
    {
        printf("Too many arguements or out of bounds.\n");
        printf("Enter one integer for width 1 to 32\n");
        exit(0);
    }

    // Printing table lines
    printColumn(charWidth, width);
    printLine(charWidth, width);

    for (row = 1; row <= height; row++)
    {
        for (column = 0; column <= width; column++)
        { 
            if (column == 0)
            {
                printf("%*d \u2502", charWidth, row);
            }
            else
            {
                printf("%*d", charWidth, (row * column));
            }
        }

        printf("\n");
    }
    return 0;
}

// Counts the number of digits a number has
int countWidth(int num)
{
    int size = 0;

    while (num != 0)
    {
        num /= 10;
        size++;
    }

    return size;
}

// Prints the line between the row header and the products
void printColumn(int charWidth, int width)
{
    for (int i = 0; i <= width; i++)
    {
        // Checks when to put X at table corner
        if (i == 0)
        {
            printf("%*s \u2502", charWidth, "X");
        }
        else
        {
            printf("%*d", charWidth, i);
        }
    }

    printf("\n");
}

// Prints the line between the header numbers and the products
void printLine(int charWidth, int width)
{
    int totalLines = (width * charWidth) + charWidth;
    for (int i = 0; i <= totalLines; i++)
    {
        printf("\u2500");
        
        // Prints the cross at the corner
        if (i == charWidth)
        {
            printf("\u253C");
        }
    }

    printf("\n");
}

// Validates command line arguments
int inputValidation(int argc, char *argv[])
{
    int isDigit = 1, valid = 0, j = 0;

    // Checks if arguments are strictly a number
    for (int i = 1; i < argc; i++)
    {
        j = 0;
        while (argv[i][j] != '\0')
        {
            if (! (isdigit(argv[i][j])))
            {
                isDigit = 0;
                break;
            }

            j++;
        }

        // If first argument is not a digit dont bother 
        // checking second one
        if (!isDigit)
        {
            break;
        }
    }

    // Checks bounds and correct number of arguments
    if (isDigit && argc == 2 && (atoi(argv[1]) >= 1) && (atoi(argv[1]) <= 32))
    {
        valid = 1;
    }
    else if (argc != 1 || !(isDigit))
    {
        valid = 2;
    }

    return valid;
}
