// Conner Jordan
// CST 334
// 7/18/2023
// Lab 4, FIFO page replacement algorithm that exports data to a .csv file

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

int main(int argc, char *argv[])
{
    int C_SIZE = atoi(argv[1]);
    struct queue *cache = queue_create();
    char pageCache[100];

    int totalRequests = 0;
    int totalFaults = 0;
    int page_num;

    while (fgets(pageCache, 100, stdin))
    {
        page_num = atoi(pageCache);
        totalRequests++;

        struct node *foundNode = queue_find(cache, page_num);
        if (foundNode == NULL)
        {
            totalFaults++;

            if (queue_length(cache) == C_SIZE)
            {
                dequeue(cache);
            }

            enqueue(cache, page_num);
        }
    }

    int hits = totalRequests - totalFaults;
    double hitRate = ((double)hits / totalRequests) * 100;
    double missRate = ((double)totalFaults / totalRequests) * 100;

    printf("Cache Size: %d\n", C_SIZE);
    printf("Total requests: %d\n", totalRequests);
    printf("Total Page Faults: %d\n", totalFaults);
    printf("Hits: %d\n", hits);
    printf("Hit Rate: %.2f%%\n", hitRate);
    printf("Miss Rate: %.2f%%\n", missRate);

    FILE *fp;
    fp = fopen("results.csv", "a");
    if (fp == NULL)
    {
        perror("Error opening file");
        return -1;
    }

    fprintf(fp, "%d,%d,%d,%d,%.2f,%.2f\n", C_SIZE, totalRequests, totalFaults, hits, hitRate, missRate);

    fclose(fp);

    queue_destroy(cache);

    return 0;
}