/*
 * que.h
 *
 *  Created on: 2019/03/06
 *      Author: AshGarden
 *
 */

#ifndef QUE_H_
#define QUE_H_

#include <stdbool.h>

typedef struct queue{
	 struct queue *nxt;
	 struct queue *pre;
} que_t;


extern inline void que_init(que_t* obj)
{
	obj->pre = obj->nxt = obj;
}

extern inline void que_add(que_t* que_mng, que_t* obj)
{
	obj->pre = que_mng->pre;
	obj->nxt = que_mng;
	que_mng->pre->nxt = obj;
	que_mng->pre = obj;
}


extern inline que_t* que_dell(que_t* obj)
{
	obj->pre->nxt = obj->nxt;
	obj->nxt->pre = obj->pre;
	return obj;
}

extern inline bool que_mng_empty(que_t* que_mng)
{
	if (que_mng->nxt == que_mng) {
		return(true);
	}
	else{
		return(false);
	}
}

extern inline que_t* que_get(que_t* que_mng)
{
	if( que_mng->nxt == que_mng)
	{
		return 0;
	}
	else{
		return que_dell(que_mng->nxt);
	}
}

extern inline int32_t	que_count(que_t* que_mng)
{
	int32_t	__count__;
	que_t*	tmp = que_mng;
	__count__ = 0;
	while( que_mng != tmp->nxt)
	{
		__count__++;
		tmp = tmp->nxt;
	}
	return __count__;
}

#define FOREACH_Q( obj , que_mng ) 	\
	for( obj = ((que_t*)que_mng)->nxt; \
		 obj != que_mng; \
		 obj = ((que_t*)obj)->nxt)

#define FOREACH_GET_Q( obj , que_mng ) 	\
	for( obj = ((que_t*)que_get(((que_t*)que_mng))); \
		 obj != 0; \
		 obj = ((que_t*)que_get(((que_t*)que_mng))))

#endif /* QUE_H_ */
