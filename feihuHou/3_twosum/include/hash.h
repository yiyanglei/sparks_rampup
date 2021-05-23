#ifndef HASH_H
#define HASH_H

typedef struct Pair_s {
	uint32_t key;
	uint32_t value;
}Pair_t;

typedef struct List_s {
	Pair_t pair;
	struct List_s* next;
}List_t;


typedef struct Hash_s {
	List_t* head;
	uint32_t size;
	uint32_t count;
}Hash_t;



uint32_t get_key_index (Hash_t* p_hash_s, uint32_t key);
List_t* get_key_plist (Hash_t* p_hash_s, uint32_t key);
Hash_t* hsah_new (uint32_t size);
uint32_t hsah_insert (Hash_t* p_hash_s, Pair_t* pair);
uint32_t hash_remove (Hash_t* p_hash_s, uint32_t  key);
void hash_delete (Hash_t* p_hash_s);
void hash_print (Hash_t* p_hash_s);



#endif
