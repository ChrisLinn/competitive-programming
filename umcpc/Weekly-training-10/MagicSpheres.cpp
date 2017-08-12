#include <stdio.h>

int main() {
    int a, b, c, x, y, z;
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d %d %d", &x, &y, &z);

    int ra = a - x;
    int rb = b - y;
    int rc = c - z;

    ra = ra>=0?ra/2:ra;
    rb = rb>=0?rb/2:rb;
    rc = rc>=0?rc/2:rc;

    if((ra+rb+rc)>=0)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}