#ifndef INC_TASKSCHEDULER_H_
#define INC_TASKSCHEDULER_H_
#include "ram_maneger.h"

typedef struct  { // Одиниці задачі

} Task ;

struct Node;
typedef struct Node Node ;

struct Node { // Контейнер нод для таска
	Task *task;
	Node * pNext;
	uint_8 size;         //1bajt
};

void push_back ( Node *node, Task *task );
void push_front ( Node *node, Task *task );
void remove_node ( Node *node, unsigned int index );
void pop_front ( Node *node );
void pop_back ( Node *node );
Task *back ( Node *node );
Task *take_from_index ( Node *node, unsigned int index );

#endif /* INC_TASKSCHEDULER_H_ */
