#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, head, total = 0;
    printf("Enter number of requests: ");
    scanf("%d", &n);
    int req[n], visited[n];

    printf("Enter request sequence: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
        visited[i] = 0;
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nOrder of servicing:\n");

    for(int i = 0; i < n; i++) {

        int min = 100000;
        int index = -1;

        for(int j = 0; j < n; j++) {

            if(!visited[j]) {
                int distance = abs(head - req[j]);

                if(distance < min) {
                    min = distance;
                    index = j;
                }
            }
        }

        visited[index] = 1;
        total += min;
        head = req[index];

        printf("%d ", head);
    }

    printf("\n\nTotal Head Movement = %d", total);

    return 0;
}