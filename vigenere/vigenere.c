#include <stdio.h>
#include <string.h>
#include <ctype.h>

void decryption(char a[], char key[]) {
    char b[50];
    int i;
    for (i = 0; i < strlen(a); i++) {
        b[i] = (a[i] - key[i] + 26) % 26 + 'A';
    }
    b[i] = '\0';
    printf("\nPlaintext:\n%s\n", b);
}

void encryption(char a[], char key[]) {
    char encrypt[50];
    int i;
    for (i = 0; i < strlen(a); i++) {
        encrypt[i] = (a[i] + key[i] - 2 * 'A') % 26 + 'A';
    }
    encrypt[i] = '\0';
    printf("\nEncrypted Text:\n%s\n", encrypt);
    decryption(encrypt, key);
}

int main() {
    char a[50];
    char key[50];
    
    printf("Enter the String: ");
    fgets(a, sizeof(a), stdin);
    printf("Enter the Key: ");
    fgets(key, sizeof(key), stdin);

    // Remove newline characters if any
    a[strcspn(a, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';

    // Convert to uppercase
    for (int i = 0; i < strlen(a); i++) {
        a[i] = toupper(a[i]);
    }
    for (int i = 0; i < strlen(key); i++) {
        key[i] = toupper(key[i]);
    }

    // Extend the key if necessary
    if (strlen(a) > strlen(key)) {
        int j = 0;
        for (int i = strlen(key); i < strlen(a); i++) {
            key[i] = key[j++];
        }
        key[strlen(a)] = '\0';
    }

    printf("\nModified Key:\n%s\n", key);

    encryption(a, key);

    return 0;
}
