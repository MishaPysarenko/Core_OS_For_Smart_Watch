#ifndef INC_TASKSCHEDULER_H_
#define INC_TASKSCHEDULER_H_
#include "ram_maneger.h"

typedef struct  { // Одиниці задачі

} Task ;

struct Node { // Контейнер нод для таска
	Task *task;
	struct Node * pNext;
	uint_8 size;         //1bajt
};

void push_back ( struct Node node, Task *task );
void push_front ( struct Node node, Task *task );
void remove_node ( struct Node node, unsigned int index );
void pop_front ( struct Node node );
void pop_back ( struct Node node );
Task *back ( struct Node node );
Task *take_from_index ( struct Node node, unsigned int index );

#endif /* INC_TASKSCHEDULER_H_ */
