#include <stdio.h>
#include <string.h>

int main() {
    char a[100], b[100];
    int dp[100][100];
    int i, j;

    printf("Enter first string: ");
    scanf("%s", a);

    printf("Enter second string: ");
    scanf("%s", b);

    int m = strlen(a);
    int n = strlen(b);

    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = dp[i - 1][j] > dp[i][j - 1]
                         ? dp[i - 1][j]
                         : dp[i][j - 1];
        }
    }

    printf("Length of LCS = %d\n", dp[m][n]);

    return 0;
}
