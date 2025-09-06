#include <stdio.h>
#include <string.h>

int i, j, key_len, flag;
char key[30], p1[60], p[30], cipher_text[60];  // increased p1 and cipher_text size
int count = 0, count1 = 0, length = 0, l = 0;
char table[5][5];
int r1, r2, c1, c2, k1;
int val = 97;

int check(char k)
{
    int i, j;
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
        {
            if (table[i][j] == k)
                return 0;
        }
    return 1;
}

int main(void)
{
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            table[i][j] = '0';

    printf("\n*** Playfair Cipher ***\n");

    printf("Enter the Key without spaces (in lowercase) : ");
    scanf("%s", key);
    key_len = strlen(key);

    for (i = 0; i < key_len; i++)
    {
        if (key[i] == 'j')
            key[i] = 'i';
    }

    // inserting the key into the table
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            flag = 0;
            while (flag != 1)
            {
                if (count >= key_len)
                    goto l1;
                flag = check(key[count]);
                count++;
            }
            table[i][j] = key[(count - 1)];
        }
    }

l1:
    // inserting other alphabets
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (!(table[i][j] >= 'a' && table[i][j] <= 'z'))
            {
                flag = 0;
                while (flag != 1)
                {
                    if ('j' == (char)val)
                        val++;
                    flag = check((char)val);
                    val++;
                }
                table[i][j] = (char)(val - 1);
            }
        }
    }

    printf("\nThe table is as follows : \n");
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%c ", table[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter the Plain text without spaces (in lowercase): ");
    scanf("%s", p);
    l = strlen(p);

    for (i = 0; i < l; ++i)
    {
        if (p[i] == 'j')
            p[i] = 'i';
    }

    // inserting bogus characters
    i = 0;
    while (i < l)
    {
        p1[count1] = p[i];
        if (i == (l - 1))
        {
            if (p1[count1] == 'x')
                p1[count1 + 1] = 'z';
            else
                p1[count1 + 1] = 'x';
            count1 += 2;
            break;
        }
        else if (p[i] == p[i + 1])
        {
            if (p[i] == 'x')
                p1[count1 + 1] = 'z';
            else
                p1[count1 + 1] = 'x';
            count1 += 2;
            i++;
        }
        else
        {
            p1[count1 + 1] = p[i + 1];
            count1 += 2;
            i += 2;
        }
    }

    p1[count1] = '\0'; // ensure string termination
    length = strlen(p1);

    printf("\nThe final text is : %s", p1);

    // Conversion to ciphertext
    for (k1 = 0; k1 < length; k1 += 2)
    {
        for (i = 0; i < 5; ++i)
        {
            for (j = 0; j < 5; ++j)
            {
                if (table[i][j] == p1[k1])
                {
                    r1 = i;
                    c1 = j;
                }
                else if (table[i][j] == p1[k1 + 1])
                {
                    r2 = i;
                    c2 = j;
                }
            }
        }

        if (r1 == r2)
        {
            cipher_text[k1] = table[r1][(c1 + 1) % 5];
            cipher_text[k1 + 1] = table[r1][(c2 + 1) % 5];
        }
        else if (c1 == c2)
        {
            cipher_text[k1] = table[(r1 + 1) % 5][c1];
            cipher_text[k1 + 1] = table[(r2 + 1) % 5][c1];
        }
        else
        {
            cipher_text[k1] = table[r1][c2];
            cipher_text[k1 + 1] = table[r2][c1];
        }
    }

    cipher_text[length] = '\0';

    printf("\n\nThe Cipher text is : %s\n", cipher_text);

    getchar(); // wait for input before exit
    return 0;
}
