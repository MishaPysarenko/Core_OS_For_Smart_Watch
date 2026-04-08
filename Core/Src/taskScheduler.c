#include "taskScheduler.h"
/*
 * taskScheduler.c
 *
 *  Created on: Mar 9, 2026
 *      Author: Mike
 */


void push_back ( Node *node, Task *task ){

	if (node == nullptr){
		node = malloc ( sizeof (Node) );
		node -> task = task ;
		return ;
	}

	Node *curent = node ;
	while(curent -> pNext != nullptr){
		curent = curent -> pNext ;
	}

	curent -> pNext = malloc ( sizeof (Node) );

	curent -> pNext -> task = task ;

}

void push_front ( Node *node, Task *task ) {

	if ( node == nullptr){
		node = malloc ( sizeof (Node) );
		node -> task = task ;
		return ;
	}

	Node *curent = node ;

	node = malloc ( sizeof (Node) );
	node -> pNext = curent ;
	node -> task = task ;

}

void remove_node ( Node *node, Task *task ) {

}

void pop_front ( Node *node ) {

}

void pop_back ( Node *node ) {

}

Task *back ( Node *node ) {

}

Task *take_from_index ( Node *node, unsigned int index ) {

}
