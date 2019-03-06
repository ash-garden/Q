/*
 * test.c
 *
 *  Created on: 2019/03/06
 *      Author: AshGarden
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "que.h"


typedef struct{
	que_t que;
	char data[256];
}TestData_T;

#define MAX_QUE_OBJ 3

int main(void)
{
	TestData_T data[MAX_QUE_OBJ];
	que_t mng_unuse;
	que_t mng_use;
	int i = 0;

	TestData_T* tmp;

	que_init((que_t*)&mng_unuse);
	que_init((que_t*)&mng_use);

	for (i = 0;i <MAX_QUE_OBJ; i++){
		que_init((que_t*)&data[i]);
	}

	for (i = 0;i <MAX_QUE_OBJ; i++){
		que_add(&mng_unuse,&data[i]);
	}

	printf("unused_que:%d\n",que_count(&mng_unuse));
	printf("used_que:%d\n",que_count(&mng_use));

	i=1;
	while( (tmp = que_get(&mng_unuse)) != 0  )
	{
		sprintf( &tmp->data,"%d",i);
		que_add(&mng_use,tmp);
		i++;
	}

	printf("unused_que:%d\n",que_count(&mng_unuse));
	printf("used_que:%d\n",que_count(&mng_use));

	//tmp = &mng_use;
	while( (tmp = que_get(&mng_use)) != 0  )
	{
		printf("%s\n",(TestData_T*)tmp->data);
		que_add(&mng_unuse,tmp);
	}
	printf("unused_que:%d\n",que_count(&mng_unuse));
	printf("used_que:%d\n",que_count(&mng_use));



	i=101;
	while( (tmp = que_get(&mng_unuse)) != 0  )
	{
		sprintf( &tmp->data,"%d",i);
		que_add(&mng_use,tmp);
		i++;
	}

	tmp = que_get(&mng_use);
	printf("%s\n",((TestData_T*)(tmp))->data);
	que_add(&mng_unuse,tmp);

	i=201;
	while( (tmp = que_get(&mng_unuse)) != 0  )
	{
		sprintf( &tmp->data,"%d",i);
		que_add(&mng_use,tmp);
		i++;
	}

	FOREACH_Q(tmp,&mng_use)
	{
		printf("%s\n",(TestData_T*)tmp->data);
	}
	printf("unused_que:%d\n",que_count(&mng_unuse));
	printf("used_que:%d\n",que_count(&mng_use));

	FOREACH_GET_Q(tmp,&mng_use)
	{
		printf("%s\n",(TestData_T*)tmp->data);
		que_add(&mng_unuse,tmp);
	}
	printf("unused_que:%d\n",que_count(&mng_unuse));
	printf("used_que:%d\n",que_count(&mng_use));


}
