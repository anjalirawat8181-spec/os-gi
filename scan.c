#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, size, total = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];

    printf("Enter request sequence: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &size);

    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if(req[i] > req[j]) {
                int temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }

    int pos = 0;

    while(pos < n && req[pos] < head)
        pos++;

    printf("\nOrder:\n");

    for(int i = pos; i < n; i++) {
        total += abs(head - req[i]);
        head = req[i];
        printf("%d ", head);
    }

    total += abs(head - (size - 1));
    head = size - 1;

    for(int i = pos - 1; i >= 0; i--) {
        total += abs(head - req[i]);
        head = req[i];
        printf("%d ", head);
    }

    printf("\n\nTotal Head Movement = %d", total);

    return 0;
}