#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int i, j;
    char temp;

    scanf("%s", s);
    j = strlen(s) - 1;

    for (i = 0; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

    printf("%s", s);
    return 0;
}
