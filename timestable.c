/*
TDQC5
Bruce Cain
*/

#include <stdio.h>

int countWidth(int num);
void printColumn(int charWidth, int width);
void printLine(int charWidth, int width);


int main(void)
{
    int row, column, height = 100, width = 30;
    int charWidth = countWidth(height * width) + 1;

    printColumn(charWidth, width);
    printLine(charWidth, width);

    for (row = 1; row <= height; row++)
    {
        for (column = 0; column <= width; column++)
        { 
            if (0 == column)
            {
                printf("%*d |", charWidth, row);
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

void printColumn(int charWidth, int width)
{
    for (int i = 0; i <= width; i++)
    {
        if (0 == i)
        {
            printf("%*s |", charWidth, "X");
        }
        else
        {
            printf("%*d", charWidth, i);
        }
    }

    printf("\n");
}

void printLine(int charWidth, int width)
{
    int totalLines = (width * charWidth) + charWidth;
    for (int i = 0; i <= totalLines; i++)
    {
        printf("-");
    }

    printf("-\n");
}
