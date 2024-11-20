#include "hashmap.h"
#include <stdbool.h>
#include <limits.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>


//TRIVIAL HASHING HASH=KEY, WITH OVERWRITING
//


//statically allocated hashmap 10keys possible
//key is an int
//value is an int
//overwrite in case of collision

//hash algorithm uses the key as the stirage index

#define HASH_NUM_KEYS 10
hashmap_t mymap[HASH_NUM_KEYS];

#define ARRAY_SIZE(array) \
        sizeof(array)/sizeof(array[0])

#define FOR_EACH(entry,array)\
 hashmap_t* entry=&array[0];\
 for(int index=0;index<ARRAY_SIZE(mymap);index++,entry=&array[index])\


static int collision_count = 0;

hashmap_t* hash_map_create()
{
	FOR_EACH(pair, mymap)
	{
		pair->key = -1;
		pair->value = -1;
		pair->next = NULL;
	}
	return mymap;
}

void hash_map_put(hashmap_t* map, int pkey, int pvalue)
{
	int hash = pkey % 10;

	//check for collission
	if (map[hash].key != -1)
	{
		//collision
		//add as first node, avoid iterating
		collision_count++;
		hashmap_t* iterator =&map[hash] ;
		hashmap_t* next = iterator->next;

		iterator->next = (hashmap_t*)malloc(sizeof(hashmap_t));
		iterator = iterator->next;
		iterator->key = pkey;
		iterator->value = pvalue;
		iterator->next = next;


	}
	else
	{
		//no coliision
		map[hash].key = pkey;
		map[hash].value = pvalue;

	}


}

int hash_map_get(hashmap_t* map, int key)
{
	int hash = key%10;

	//first check in array
	if (map[hash].key == key)
	{
		//found in array O(1) time
		return map[hash].value;
	}

	//didnt find it as first in linked list check other nodes

	hashmap_t* iterator = &map[hash];
	while (iterator != NULL)
	{
		if (iterator->key == key)
		{

			return iterator->value;
			
		}
		iterator = iterator->next;
	}

	//rached the end , nothing found
	return -1;
}

void hash_map_remove(hashmap_t* map, int key)
{
	int hash = key%10;

	//first check in array
	if (map[hash].key == key)
	{
		//found in array O(1) time
		map[hash].key = 0;
		map[hash].value = 0;
	}

	//didnt find it as first in linked list check other nodes
	hashmap_t dummy;
	dummy.key = -1;
	dummy.next = &map[hash];

	hashmap_t* iterator = &dummy;

	while (iterator->next != NULL)
	{
		if (iterator->next->key == key)
		{
			int ret= iterator->value;
			
			//delete node next to you
			hashmap_t* nextiterator = iterator->next->next;
			iterator->next = nextiterator;
			free(iterator->next);
		

		}
		iterator = iterator->next;
	}

	//rached the end , nothing found, nothinig to delete


	

}

void hash_map_print(hashmap_t* map)
{
	FOR_EACH(pair, map)
	{
		//check if there is linked list
		if (pair->next == NULL)
		{
			printf("[%d,%d] \r\n", pair->key, pair->value);
		}
		else
		{
			hashmap_t* iterator = pair;
			while (iterator!= NULL)
			{
				printf("[%d,%d]---> ", iterator->key, iterator->value);
				iterator = iterator->next;
			}
			printf("\r\n");
		}
	
	}

	printf("\r\n");
	printf("\r\n");
	printf("=======================================================================================\r\n");

}



