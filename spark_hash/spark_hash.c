/**
 * @file spark_hash.c
 * @author your name (you@domain.com)
 * @brief Hash implement for NIO sparks training
 * @version 0.1
 * @date 2021-04-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "spark_hash.h"

/* HASH buckets */
static spark_filter_t * gp_spark_buckts[SPARK_MAX_HASH_SIZE];

/* filter entry memorys */
static spark_filter_t g_spark_entrys[SPARK_MAX_ENTRY_NUM];

/**
 * @brief hash function 
 * 
 * @param component_id 
 * @return unsigned short 
 */
static unsigned short spark_hash_func(spark_component_id_t component_id)
{
    return component_id % SPARK_MAX_HASH_SIZE;
}

/**
 * @brief 
 * 
 * @return spark_filter_t* 
 */
static spark_filter_t * spark_entry_new(void)
{
    spark_filter_t * p_new_entry = NULL;

    for (unsigned short index  = 0U; index < SPARK_MAX_ENTRY_NUM; ++index)
    {
        if (SPARK_INVALID_COMPONENT_ID == g_spark_entrys[index].component_id)
        {
            p_new_entry = &g_spark_entrys[index];
            break ;
        }
    } 

    return p_new_entry;   
}

/**
 * @brief 
 * 
 * @param p_entry 
 */
static void spark_entry_free(spark_filter_t * p_entry)
{
    if (NULL != p_entry)
    {
        p_entry->component_id   = SPARK_INVALID_COMPONENT_ID;
        p_entry->p_next         = NULL;
    }

    return ;
}

/**
 * @brief 
 * 
 * @param component_id 
 * @param message_level 
 * @return unsigned int zero success, non zero failed
 */
unsigned int spark_insert(spark_component_id_t component_id,  
                  spark_message_level_t message_level)
{
    unsigned int   ret_val  = 0U;
    unsigned short index    = SPARK_MAX_HASH_SIZE;

    /* 1: find hash index */  
    index = spark_hash_func(component_id);

    /* 2: find existed entry */ 
    spark_filter_t * p_previous = NULL;
    spark_filter_t * p_current  = gp_spark_buckts[index];
    
    while ((NULL != p_current) && (component_id != p_current->component_id))
    {
        p_previous  = p_current;
        p_current   = p_current->p_next;
    }

    /* try allocate new one */
    if (NULL == p_current)
    {
        /* 3： alloc entry */ 
        p_current = spark_entry_new();
        if (NULL == p_current)
        {
            /* error */
            ret_val = 1U;
        }

        /* 4. insert */
        if (NULL != p_previous)
        {
            p_previous->p_next = p_current;
        }
        else
        {
            gp_spark_buckts[index] = p_current;
            p_current->p_next = NULL;
        }
    }
    
    /* save message level */
    if (NULL != p_current)
    {
        p_current->message_level = message_level;
    }
    
    return ret_val;
}

/**
 * @brief 
 * 
 * @param component_id 
 */
void spark_delete(spark_component_id_t component_id)
{
    unsigned short index    = SPARK_MAX_HASH_SIZE;

    /* 1: find hash index */  
    index = spark_hash_func(component_id);

    /* 2: find existed entry */ 
    spark_filter_t * p_previous = NULL;
    spark_filter_t * p_current  = gp_spark_buckts[index];
    
    while ((NULL != p_current) && (component_id != p_current->component_id))
    {
        p_previous  = p_current;
        p_current   = p_current->p_next;
    }

    /* delete it */
    if (NULL != p_current)
    {
        /* delete from hash buckets*/
        if (NULL != p_previous)
        {
            p_previous->p_next = NULL;
        }
        else
        {
            gp_spark_buckts[index] = NULL;
        }

        spark_entry_free(p_current);
    }
}

/**
 * @brief 
 * 
 */
void spark_init(void)
{
    return ;
}

