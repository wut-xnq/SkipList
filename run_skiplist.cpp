#define _CRT_SECURE_NO_WARNINGS
#include "skiplist.h"
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(NULL));  // 设置随机数种子

    skip_list* sl = create_sl();

    for (int i = 1; i < 11111; ++i)
    {
        int value = rand() % 100000; 
        insert(sl, i, value);
    }

    for (int i = 11; i < 11111; ++i)
    {
        if (!erase(sl, i))
            printf("No!\n");
    }
    print_sl(sl);
    keyType input_key;  // 定义用户输入的 key
    printf("Enter the key to search: ");
    scanf("%d", &input_key);  // 获取用户输入

    int query_count;  // 定义查询次数变量
    int* p = search(sl, input_key, &query_count);  // 传入用户输入的 key
    if (p)
    {
        printf("Value of key %d is %d\n", input_key, *p);
        printf("Number of queries made: %d\n", query_count);  // 输出查询次数
    }
    else
    {
        printf("Value of key %d is not found.\n", input_key);
    }
    sl_free(sl);
    return 0;
}
