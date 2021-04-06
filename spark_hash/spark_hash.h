/**
 * @file spark_hash.h
 * @author your name (you@domain.com)
 * @brief export interfaces of Hash Module
 * @version 0.1
 * @date 2021-04-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#define SPARK_MAX_HASH_SIZE     16U
#define SPARK_MAX_ENTRY_NUM     16U

#define SPARK_INVALID_COMPONENT_ID      0xffffU

typedef unsigned short spark_component_id_t;

/* message level type */
typedef enum
{
    SPARK_LOG_OFF,
    SPARK_LOG_FATAL,
    SPARK_LOG_ERROR,
    SPARK_LOG_WARN,
    SPARK_LOG_INFO,
    SPARK_LOG_DEBUG,
    SPARK_LOG_VERBOSE,
    SPARK_LOG_INVALID
} spark_message_level_t;

/* filter type */
typedef struct spark_filter_type
{
    spark_component_id_t      component_id;
    spark_message_level_t     message_level;
    struct spark_filter_type  * p_next;
} spark_filter_t;

