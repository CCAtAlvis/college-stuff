#include <stdio.h>

void main() {
    char pt[100];
    char ct[100], ct2[100];
    char dt[100], dt2[100];
    int k, i=0, j=0, mid=0, len=0;

    printf("enter plain text: ");
    scanf("%s", &pt);

    printf("enter key: ");
    scanf("%d", &k);


    printf("------Encrypting plain text------");
    // encryption
    // substitution
    printf("\nafter substitution: ");
    while (pt[i] != '\0') {
        ct[i] = pt[i];
        ct[i] -= 65;
        ct[i] += k;
        ct[i] %= 26;
        ct[i] += 65;
        printf("%c", ct[i]);
        i++;
    }
    ct[i] = pt[i];

    mid = i/2;
    if (mid%2 == 1)
        mid++;

    // transposition
    printf("\nafter transposition: ");
    i=0;
    j=0;
    while (ct[i] != '\0') {
        if (i%2 == 0) {
            ct2[j] = ct[i];
        } else {
            ct2[mid+j] = ct[i];
            j++;
        }
        i++;
    }
    ct2[i]=ct[i];

    i=0;
    while(ct2[i] != '\0') {
        printf("%c", ct2[i]);
        i++;
    }


    printf("\n\n------Decrypting cipher text------");
    // decryption
    // transposition
    len = 0;
    while(ct2[len] != '\0')
        len++;

    i=0;
    j=0;
    while (ct[i] != '\0') {
        dt[j] = ct2[i];
        i++;
        j += 2;
        j = j%len;
    }
    dt[i]=ct[i];

    printf("\nafter transposition: ");
    i=0;
    while(dt[i] != '\0') {
        printf("%c", dt[i]);
        i++;
    }

    // decipher
    printf("\nafter substitution: ");
    i=0;
    while (dt[i] != '\0') {
        dt2[i] = dt[i];
        dt2[i] -= 65;
        dt2[i] -= k;

        if (dt2[i] < 0) {
            dt2[i] *= -1;
            dt2[i] = 26 - dt2[i];
        }

        dt2[i] %= 26;
        dt2[i] += 65;
        printf("%c", dt2[i]);
        i++;
    }
    dt2[i] = dt[i];
}