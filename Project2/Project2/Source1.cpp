#include <stdio.h>
#include "hashmap.h"

int main()
{

	hashmap_t* myhash = hash_map_create();
	hash_map_print(myhash);

	hash_map_put(myhash, 3, 55);
	hash_map_print(myhash);

	hash_map_put(myhash, 43, 91);
	hash_map_print(myhash);

	hash_map_put(myhash, 88, 91);
	hash_map_print(myhash);

	hash_map_put(myhash, 558, 91);
	hash_map_print(myhash);

	hash_map_put(myhash, 10008, 91);
	hash_map_print(myhash);

	int a = hash_map_get(myhash,559);
	printf("hash 558 val %d", a);



	return 0;
}