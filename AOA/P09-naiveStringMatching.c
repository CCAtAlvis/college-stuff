#include <stdio.h>
#include <string.h>

void main () {
    int i, j, m, n;
    char p[10], t[100];

    printf("enter the text string: ");
    scanf("%s", t);

    printf("enter the patter to match: ");
    scanf("%s", p);

    m = strlen(p);
    n = strlen(t);

    for (i=0; i<n-m; ++i) {
        for (j=0; j<m; ++j) {
            if (t[i+j] != p[j]) {
                break;
            }
        }

        if (m==j) {
            printf("pattern found at i = %d\n", i);
        }
    }
}
