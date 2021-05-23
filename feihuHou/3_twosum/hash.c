#include "./include/typedef.h"
#include "./include/hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define PRINT_FORMAT  printf



uint32_t get_key_index(Hash_t* p_hash_s, uint32_t key) 
{
	return key % p_hash_s->size;
}


List_t* get_key_plist(Hash_t* p_hash_s, uint32_t key)
{
	int i;
	i = get_key_index(p_hash_s, key);
	List_t* p_list = p_hash_s->head[i].next;

	while ((p_list != NULL) && (p_list->pair.key != key)) 
	{
		p_list = p_list->next;
	}
	return p_list;
}




Hash_t* hsah_new(uint32_t size) 
{
	Hash_t* p_hash_s = (Hash_t*)malloc(sizeof(Hash_t));
	p_hash_s->size = size;
	p_hash_s->head = (List_t*)malloc((p_hash_s->size) * sizeof(List_t));
	memset(p_hash_s->head, 0, (p_hash_s->size) * sizeof(List_t));
	p_hash_s->count = 0;
	return p_hash_s;
}


uint32_t hsah_insert(Hash_t* p_hash_s, Pair_t* pair) 
{
	List_t* p_list = get_key_plist(p_hash_s, pair->key);

	if (NULL != p_list) 
	{
		return 0;
	}
	List_t* p_list_temp = (List_t*)malloc(sizeof(List_t));
	memcpy(&p_list_temp->pair, pair, sizeof(Pair_t));

	int index = get_key_index(p_hash_s, pair->key);
	p_list_temp->next = p_hash_s->head[index].next;
	p_hash_s->head[index].next = p_list_temp;
	p_hash_s->count++;
	return 1;
}


uint32_t hsah_remove(Hash_t* p_hash_s, uint32_t  key) 
{
	int index;
	index = get_key_index(p_hash_s, key);
	List_t* p_list = &p_hash_s->head[index];

	while ((p_list->next != NULL) && (p_list->next->pair.key != key)) 
	{
		p_list = p_list->next;
	}
	if (p_list->next == NULL) 
	{
		return 0;
	}
	List_t* p_list_temp = p_list->next;
	p_list->next = p_list->next->next;
	free(p_list_temp);
	p_list_temp = NULL;
	p_hash_s->count--;
	return 1;
}

void hash_delete(Hash_t* p_hash_s) 
{
	int index;
	List_t* p_list = NULL;
	List_t* p_list_temp = NULL;

	for (index = 0; index < p_hash_s->size; index++) 
	{
		p_list = p_hash_s->head[index].next;
		while (p_list) 
		{
			p_list_temp = p_list->next;
			free(p_list);
			p_list = p_list_temp;
		}
	}
	p_list = NULL;
	p_list_temp = NULL;
	free(p_hash_s->head);
	p_hash_s->head = NULL;
	free(p_hash_s);
	p_hash_s = NULL;
}


void hsah_print(Hash_t* p_hash_s) 
{
	int i;
	for (i = 0; i < p_hash_s->size; i++) 
	{
		List_t* p_list = p_hash_s->head[i].next;
		while (p_list) 
		{
			PRINT_FORMAT("[%d-%d] ", p_list->pair.key, p_list->pair.value);
			p_list = p_list->next;
		}
		PRINT_FORMAT("^\n");
	}
	PRINT_FORMAT("\n");
}


