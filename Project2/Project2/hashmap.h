#ifndef PS_HASHMAP_H
#define PS_HASHMAP_H

typedef struct hashmap hashmap_t;

struct hashmap
{
	int key;
	int value;
	hashmap* next;
};


//=================================================================
hashmap* hash_map_create();

void hash_map_put(hashmap_t * obj, int key, int value);

int hash_map_get(hashmap_t* obj, int key);

void hash_map_remove(hashmap_t* obj, int key);

void hash_map_free(hashmap_t* obj);

void hash_map_print(hashmap_t* obj);

//==================================================================


#endif 



