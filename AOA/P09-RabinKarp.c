#include <stdio.h>
#include <string.h>

void main () {
    int i, j, m, n, hashP=0, hashT=0, h=1, d=256, q=11;
    char p[10], t[100];

    printf("enter the text string: ");
    scanf("%s", t);

    printf("enter the patter to match: ");
    scanf("%s", p);

    m = strlen(p);
    n = strlen(t);

    for (i=0; i<m-1; ++i)
        h = (h*d)%q;

    for (j=0; j<m; ++j) {
        hashP = (d*hashP + (int)p[i])%q;
        hashT = (d*hashT + (int)t[i])%q;
    }

    printf("hash of pattern: %d\n", hashP);
    printf("hash of text: %d\n", hashT);

    for (i=0; i<=n-m; ++i) {
        if (hashP == hashT) {
            for (j=0; j<m; ++j)
                if (t[i+j] != p[j])
                    break;

            if (m==j)
                printf("pattern found at i = %d\n", i);
        }

        if (i<n-m) {
            hashT = (d*(hashT - (int)t[i]*h) + (int)t[i+m])%q;
            if (hashT<0)
                hashT += q;
        }

        printf("hash of text: %d\n", hashT);
    }
}
