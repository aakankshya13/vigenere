#include <stdio.h>
#include <string.h>

int n, key, plength, k, j;
char a[40];
char ptext[50][50], dtext[50];
int i = 0, col = 0, row = 0;
int flag = 0;

int main()
{
    printf("\n Enter the plaintext: ");
    gets(a);

    printf("\n Enter the depth: ");
    scanf("%d", &key);

    plength = strlen(a);

    while (i < plength)
    {
        ptext[row][i] = a[i];

        if (row == 0)
        {
            flag = 0;
        }
        else if (row == key - 1)
        {
            flag = 1;
        }

        if (flag == 0)
        {
            row++;
        }
        else
        {
            row--;
        }
        i++;
    }

    i = 0;
    for (k = 0; k < key; k++)
    {
        for (j = 0; j < plength; j++)
        {
            if (ptext[k][j] != '\0')
            {
                dtext[i] = ptext[k][j];
                i++;
                printf("%c", ptext[k][j]);
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }

    printf("\n The encrypted text is: ");
    dtext[i] = '\0'; // null terminate
    puts(dtext);

    i = 0;
    row = 0;
    col = 0;

    printf("\n The decrypted text is: ");

    while (i < plength)
    {
        printf("%c", ptext[row][i]);

        if (row == 0)
        {
            flag = 0;
        }
        else if (row == key - 1)
        {
            flag = 1;
        }

        if (flag == 0)
        {
            row++;
        }
        else
        {
            row--;
        }
        i++;
    }

    return 0;
}
