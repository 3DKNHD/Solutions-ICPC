#include <stdio.h>

int main() {
    int n, m, q;
    int mat[101][101];
    scanf("%d %d %d", &n, &m, &q);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    while(q--) {
        int t;
        scanf("%d", &t);
        
        if (t == 1) {
            int r;
            scanf("%d", &r);
            r--;
            for (int j = 0; j < m / 2; j++) {
                int aux = mat[r][j];
                mat[r][j] = mat[r][m - 1 - j];
                mat[r][m - 1 - j] = aux;
            }
        }
        else if (t == 2) {
            int c;
            scanf("%d", &c);
            c--;
            for (int i = 0; i < n / 2; i++) {
                int aux = mat[i][c];
                mat[i][c] = mat[n - 1 - i][c];
                mat[n - 1 - i][c] = aux;
            }
        }
        else{
            int r, c;
            scanf("%d %d", &r, &c);
            r--; c--;
            printf("%d\n", mat[r][c]);
        }
    }
    return 0;
}