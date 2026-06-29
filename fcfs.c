#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, total = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];

    printf("Enter request sequence: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nOrder of servicing:\n");

    for(int i = 0; i < n; i++) {
        printf("%d ", req[i]);
        total += abs(head - req[i]);
        head = req[i];
    }

    printf("\n\nTotal Head Movement = %d", total);

    return 0;
}