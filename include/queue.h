
#ifndef __QUEUE_H__
#define __QUEUE_H__

typedef struct t_que
{
    struct t_que *prev;
    struct t_que *next;
} queue_node_t;

typedef struct
{
    queue_node_t head;
    queue_node_t tail;
} queue_t;

void queue_test(void);
void queue_remove(queue_node_t *que);
void queue_insert(queue_node_t *que, queue_node_t *prev);
void queue_insert_prev(queue_node_t *que, queue_node_t *next);
void queue_list_init(queue_t *ls);
bool queue_list_check(queue_t *ls);
void queue_list_enque(queue_t *ls, queue_node_t *que);
bool queue_list_is_empty(queue_t *ls);
bool queue_list_find(queue_t *ls, queue_node_t *que);
queue_node_t *queue_list_top(queue_t *ls);
queue_node_t *queue_list_pop(queue_t *ls);
void queue_list_print(queue_t *ls);

#endif // __QUEUE_H__