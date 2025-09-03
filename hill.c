#include <stdio.h>
#include <math.h>

int l, i, j;
int temp1, temp2, temp3, n, m, count, flag, k1;
int k[3][3];   // Key matrix
int p[3][1];   // Plaintext vector
int c[3][1];   // Ciphertext vector
char ch;
char pi[50];   // plaintext input
int choice;

// Function to check how many bogus chars are needed
int check(int x, int n)
{
    if (x % n == 0)
        return 0;
    return n - (x % n);
}

int main()
{
    printf("\nThe Cipher has a key of length 4 and 9. Example :- A 3*3 matrix, A 2*2 matrix ");
    printf("\nPress 3 for 3*3 matrix and Press 2 for 2*2 matrix : ");
    scanf("%d", &n);

    printf("\nEnter the key (as characters): \n");
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            scanf(" %c", &ch);   // space before %c avoids newline issue
            if (ch >= 'A' && ch <= 'Z')
                k[i][j] = ch - 'A';
            else
                k[i][j] = ch - 'a';
        }
    }

    printf("\nKey Matrix:\n");
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            printf("%d ", k[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter the length of string to be encoded (without spaces): ");
    scanf("%d", &l);

    temp1 = check(l, n);
    if (temp1 > 0)
        printf("You have to enter %d bogus characters.\n", temp1);

    printf("\nEnter the string : ");
    scanf("%s", pi);  // read string directly (no spaces allowed)

    // Add bogus characters if needed
    for (i = l; i < l + temp1; i++)
        pi[i] = 'x';   // padding with 'x'
    pi[l + temp1] = '\0';

    m = (l + temp1) / n;
    flag = 0;

    printf("\n\nThe Encoded Cipher is : ");

    while (m > 0)
    {
        count = 0;

        for (i = flag; i < flag + n; ++i)
        {
            if (pi[i] >= 'A' && pi[i] <= 'Z')
                temp3 = pi[i] - 'A';
            else
                temp3 = pi[i] - 'a';

            p[count][0] = temp3;
            count++;
        }

        for (i = 0; i < n; ++i)
            c[i][0] = 0;

        // Multiply key matrix with plaintext vector
        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < 1; ++j)
            {
                for (k1 = 0; k1 < n; ++k1)
                    c[i][j] += k[i][k1] * p[k1][j];
            }
        }

        for (i = 0; i < n; ++i)
        {
            c[i][0] = c[i][0] % 26;
            printf("%c", (char)(c[i][0] + 'A'));
        }

        m = m - 1;
        flag = flag + n;
    }

    printf("\n");
    return 0;
}
