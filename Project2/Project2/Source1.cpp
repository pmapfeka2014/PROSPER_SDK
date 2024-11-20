#include <stdio.h>
#include "hashmap.h"

int main()
{
	hashmap_t* myhash = hash_map_create();
	hash_map_print(myhash);

	hash_map_put(myhash, 3, 55);
	hash_map_print(myhash);

	hash_map_put(myhash, 8, 91);
	hash_map_print(myhash);




	return 0;
}