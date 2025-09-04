#include <stdio.h>
#include <string.h>
#include <ctype.h>

int i;
char ctext[50];
char ch;
int key;
char ptext[50];

void encrypt()
{
    for (i = 0; i < strlen(ptext); i++)
    {
        ch = ptext[i];
        if (isalpha(ch))
        {
            if (islower(ch))
            {
                ch = (ch - 'a' + key) % 26 + 'a';
            }
            else if (isupper(ch))
            {
                ch = (ch - 'A' + key) % 26 + 'A';
            }
        }
        ctext[i] = ch;
    }
    ctext[i] = '\0'; // terminate string properly
    printf("\nEncrypted text: %s\n", ctext);
}

void decrypt()
{
    for (i = 0; i < strlen(ctext); i++)
    {
        ch = ctext[i];
        if (isalpha(ch))
        {
            if (islower(ch))
            {
                ch = (ch - 'a' - key + 26) % 26 + 'a';
            }
            else if (isupper(ch))
            {
                ch = (ch - 'A' - key + 26) % 26 + 'A';
            }
        }
        ptext[i] = ch;
    }
    ptext[i] = '\0'; // terminate string properly
    printf("\nDecrypted text: %s\n", ptext);
}

int main()
{
    printf("Enter the text you want to encrypt: ");
    fgets(ptext, sizeof(ptext), stdin);  // safer than gets()
    ptext[strcspn(ptext, "\n")] = '\0'; // remove newline if present

    printf("Enter the key: ");
    scanf("%d", &key);

    if (key >= 26)
    {
        key = key % 26;
    }

    printf("\nYour plaintext: %s\n", ptext);
    encrypt();
    decrypt();

    return 0;
}
