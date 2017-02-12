# include "queue.h"

struct queue *queue_init()
{
  struct queue *queue = calloc(1, sizeof(struct queue));
  queue->store = calloc(1, sizeof(struct list));
  return queue;
}

void queue_push(struct queue *queue, int player, int X, int Y, time_t time)
{
  struct list *list = malloc(sizeof(struct list));
  list->pl = player;
  list->X = X;
  list->Y = Y;
  list->time = time;
  
  if(queue->size == 0)
  {
    queue->store = list;
    list->next = list;
  }

  else
  {
    list->next = queue->store->next;
    queue->store->next = list;
    queue->store = list;
  }
  ++queue->size;
}

struct list *queue_pop(struct queue *queue)
{
  if (queue->size == 0)
    return NULL;

  --queue->size;
  struct list *list = queue->store->next

  queue->store->next = queue->store->next->next;

  return list;
}

void freeQueue(struct queue *queue)
{
  struct list *list = NULL;
  while(queue->size > 0)
  {
    list = queue->store;
    queue->store = queue->store->next;
    free(list);
    --queue->size;
  }
}
