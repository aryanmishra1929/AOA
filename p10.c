#include <stdio.h>
#include <string.h>

#define d 256
#define q 101

int main()
{
    char text[100], pattern[100];
    int i, j, n, m, h1 = 0, h2 = 0, h = 1;

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern: ");
    scanf("%s", pattern);

    n = strlen(text);
    m = strlen(pattern);

    if (m > n)
    {
        printf("Pattern not found");
        return 0;
    }

    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < m; i++)
    {
        h1 = (d * h1 + text[i]) % q;
        h2 = (d * h2 + pattern[i]) % q;
    }

    for (i = 0; i <= n - m; i++)
    {
        if (h1 == h2)
        {
            for (j = 0; j < m; j++)
                if (text[i + j] != pattern[j])
                    break;

            if (j == m)
                printf("Pattern found at index %d\n", i);
        }

        if (i < n - m)
        {
            h1 = (d * (h1 - text[i] * h) + text[i + m]) % q;

            if (h1 < 0)
                h1 += q;
        }
    }

    return 0;  }
