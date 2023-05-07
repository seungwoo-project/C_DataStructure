#include <stdio.h>
#include <stdlib.h>

#define BUCKETS 10 // 큐 크기
#define DIGITS 10 // 자릿수
#define MAX_SIZE 100000
#define MAX_QUEUE_SIZE 100000

typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void init_queue(QueueType* q)
{
    q->front = q->rear = 0;
}

int is_empty(QueueType* q)
{
    return (q->front == q->rear);
}

int is_full(QueueType* q)
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, int item)
{
    if (is_full(q))
        return;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

int dequeue(QueueType* q)
{
    if (is_empty(q))
        return;
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

int list[MAX_SIZE];
QueueType queues[BUCKETS];
// 기수정렬은 큐를 쓴다
void radix_sort(int list[], int n) {
    int i, b, d, factor = 1;
    for (b = 0; b < BUCKETS; b++)
        init_queue(&queues[b]);
    for (d = 0; d < DIGITS; d++) { // 자릿수만큼 반복
        for (i = 0; i < n; i++)
            enqueue(&queues[(list[i] / factor) % 10], list[i]); // 1의 자리를 큐에 넣음
        for (b = i = 0; b < BUCKETS; b++) // 큐를 뺀다. -> 정렬이 됨
            while (!is_empty(&queues[b]))
                list[i++] = dequeue(&queues[b]);
        factor *= 10; // 1의자리 정렬했으면 다음 10의자리 정렬하러
    }
}


int main(void)
{
    int n;
    int i = 0, input;

    scanf("%d", &n);

    while (scanf("%d", &input) != EOF) {
        list[i] = input;
        i++;
    }

    radix_sort(list, n);

    for (int i = 0; i < n; i++)
        printf("%d\n", list[i]);
    return 0;
}