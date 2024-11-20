#include "hashmap.h"
#include <stdbool.h>
#include <limits.h>
#include <stdio.h>



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
 hashmap_t entry=array[0];\
 for(int index=0;index<ARRAY_SIZE(mymap);index++,entry=array[index])\


hashmap_t* hash_map_create()
{
	return mymap;
}

void hash_map_put(hashmap_t* map, int pkey, int pvalue)
{
	mymap[pkey].key = pkey;
	mymap[pkey].value = pvalue;
}

int hash_map_get(hashmap_t* map, int key)
{
	return map[key].value;
}

void hash_map_remove(hashmap_t* map, int key)
{

	map[key].key = 0;
	map[key].value = 0;

}

void hash_map_print(hashmap_t* map)
{
	FOR_EACH(pair, map)
	{
		printf("KEY %d, VALUE %d \r\n", pair.key, pair.value);
	}

	printf("\r\n");
	printf("\r\n");
	printf("=======================================================================================\r\n");

}



