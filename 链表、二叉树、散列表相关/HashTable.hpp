// 这段代码实现了散列表（用拉链法解决冲突）

#ifndef CODE_HASHTABLE_H
#define CODE_HASHTABLE_H

#include "stdlib.h"
#include "stdio.h"

//用于存储关键字的结点
typedef struct HaNode
{
    int key;
    struct HaNode *next;
} HaNode;

#define N 7 //散列表的长度
typedef struct
{
    HaNode *h; //链头指针
} HashTable[N];

/**
 * 初始化散列表
 * @param hashTable
 */
void InitHashTable(HashTable t)
{
    for (int i = 0; i < N; i++)
        t[i].h = NULL;
}

/**
 * 在散列表 t 中插入元素 key
 * @param t
 * @param key
 * @return
 */
int InsertElem(HashTable t, int key)
{
    //申请新结点
    HaNode *p = (HaNode *)malloc(sizeof(HaNode));
    p->key = key;

    //头插法插入关键字key对应的拉链
    int index = key % N;
    p->next = t[index].h;
    t[index].h = p;
    return 1; //插入成功
}

/**
 * 在散列表 t 中删除值为 key 的元素
 * @param t
 * @param key
 * @return
 */
int DeleteElem(HashTable t, int key)
{
    int index = key % N;
    int flag = 0;           // flag=0表示删除失败，flag=1表示删除成功
    HaNode *pPre = NULL;    // pPre在遍历过程中指向p的前驱结点
    HaNode *p = t[index].h; // p指针从第一个结点开始遍历
    while (p != NULL)
    {
        //找到链表中值为key的结点并删除
        if (p->key == key)
        {
            if (pPre == NULL)
            {                         // pPre==NULL说明p结点是当前这个链表的第一个元素
                t[index].h = p->next; //头指针指向p的下一个结点
                HaNode *s = p;
                p = p->next;
                free(s);
            }
            else
            {
                pPre->next = p->next;
                HaNode *s = p;
                p = p->next;
                free(s);
            }
            flag = 1;
        }
        else
        {
            //当前结点 p 的值不等于 key，继续检查下一个结点
            pPre = p;
            p = p->next;
        }
    }
    return flag; //遍历整个链表，没找到关键字为key的结点，返回0表示删除失败
}

/**
 * 在散列表 t 中查找值为 key 的元素
 * @param t
 * @param key
 * @return
 */
HaNode *GetElem(HashTable t, int key)
{
    int index = key % N;
    HaNode *p = t[index].h; // p指针从第一个结点开始遍历
    while (p != NULL)
    {
        //找到链表中值为key的结点并删除
        if (p->key == key)
        {
            return p; //返回第一个关键字为key的结点
        }
        p = p->next;
    }
    return NULL; //遍历整个链表，没找到关键字为key的结点，返回NULL表示查找失败
}

//打印出散列表的样子
void PrintHashTable(HashTable t)
{
    printf("你的散列表长酱紫：\n");
    for (int i = 0; i < N; i++)
    {
        printf("HashTable[%d]——>", i);
        HaNode *p = t[i].h;
        while (p != NULL)
        {
            printf("%d——>", p->key);
            p = p->next;
        }
        printf("NULL\n");
    }
}

/**
 * 测试函数，初始化散列表 h，并插入、查找、删除一些元素
 */
void test_HashTable()
{
    HashTable t;       //定义一个散列表
    InitHashTable(t);  //初始化
    PrintHashTable(t); //打印出来看一眼

    //测试插入操作，生成50个随机数，并插入散列表
    for (int i = 0; i < 50; i++)
    {
        int key = rand() % 20; //随机数范围限制在20以内好了，不然看着有点累
        InsertElem(t, key);
    }
    PrintHashTable(t);  //打印出来看一眼
    InsertElem(t, 985); //手动插入一个关键字
    PrintHashTable(t);  //打印出来看一眼
    InsertElem(t, 211); //手动插入一个关键字
    PrintHashTable(t);  //打印出来看一眼

    //测试删除操作
    DeleteElem(t, 9);  //删除9
    PrintHashTable(t); //打印出来看一眼
    DeleteElem(t, 5);  //删除5
    PrintHashTable(t); //打印出来看一眼

    //测试查找操作
    HaNode *result;
    int key = 9; //查找关键字9
    result = GetElem(t, key);
    if (result == NULL)
    {
        printf("哎呀，没找到你的结点：%d\n", key);
    }
    else
    {
        printf("成功找到你的结点：%d\n", key);
    }

    key = 985; //查找关键字985
    result = GetElem(t, key);
    if (result == NULL)
    {
        printf("哎呀，没找到你的结点：%d\n", key);
    }
    else
    {
        printf("成功找到你的结点：%d\n", key);
    }
}

#endif // CODE_HASHTABLE_H