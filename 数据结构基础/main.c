//
//  main.c
//  数据结构基础
//
//  Created by vsKing on 2017/2/13.
//  Copyright © 2017年 vsKing. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DoubleList.h"


/*
 声明一个结构体 定义节点
 */
struct Node {
    char name[10];
    int score;
    struct Node *next;
};

typedef struct Node ListNode;


/*---------------------------函数实现部分-------------------------------*/
/*-----------------------------创建链表---------------------------------*/
/*在链表的末端插入新的节点，建立链表*/

ListNode * creatList(int n){
    
    ListNode * head;
    ListNode *p = NULL,*pre;
    int i;
    
    head = (ListNode *)malloc(sizeof(ListNode));
    head->next = NULL;
    pre = head;
    
    for (i = 1; i<= n; i++) {
        
        p = (ListNode *)malloc(sizeof(ListNode));
        
        printf("输入第%d个学生的名字:",i);
        scanf("%s",p->name);
        
        printf("输入第%d个学生的成绩:",i);
        scanf("%d",&p->score);
        
        pre->next = p;
        
        pre = p;
        
    }
    if (n > 0 ) {
        p->next = NULL;

    }
    
    //
    return head;
    
    

}


/*-------------------------输出链表-----------------------------------*/

void printList(ListNode * head){
    
    ListNode *p;
    p = head->next;
    
    while (p != NULL) {
        printf("name:%s,score:%d",p->name,p->score);
        p = p->next;
        printf("\n");
    }
    
    


}

/*----------------------插入链表结点--------------------------*/
/*--------------------------------------------------------------------
 函数名称:insertList(ListNode *head,int i,char name[],int score)
 函数功能:插入链表结点
 入口参数: head: 头结点地址 i:插入到第几个结点 name:插入
 结点的姓名 e:插入结点的分数
 
 出口参数:
 --------------------------------------------------------------------*/

void insertList(ListNode *head,int i,char name[],int score){

    ListNode *p1,*p2;
    
    int j;
    
    if (i<1) {
        printf("插入错误：不能小于1 \n");
    }else{
        
        j = 0;
        p1 = head;
        
        int isOut = 0;
        
        while (j < i-1) {
            p1 = p1->next;
            
            if (p1 == NULL) {
                printf("插入错误：插入点大于 总数+1\n");
                isOut = 1;
                break ;
            }
            
            j++;
        }
        
        
        if (isOut == 0) {
            p2 = (ListNode *)malloc(sizeof(ListNode));
            strcpy(p2->name, name);
            p2->score = score;
            
            p2->next = p1->next;
            p1->next = p2;
        }
        
    }
    
    
}

/*--------------------------------------------------------------------
 函数名称:deleteList(ListNode *head,int i)
 函数功能:删除链表结点
 入口参数: head: 头结点地址 i:要删除的结点所在位置

 
 出口参数:
 --------------------------------------------------------------------*/


void deleteList(ListNode *head,int i){

    ListNode *p1,*p2;
    int j = 0;
    int isOut = 0;
    if (i < 1) {
        printf("删除错误：不能小于1\n");
    }else{
        
        p1 = head;
        
        while (j < i - 1) {
            p1 = p1->next;
            
            if (p1 == NULL) {
                printf("删除错误：不能大于总数\n");
                isOut = 1;
                break;
            }
            
            j++;
            
        }
        
        if (isOut == 0 && p1->next != NULL) {
            
            
            
            p2 = p1->next;
            
            p1->next = p2->next;
            
            free(p2);
          
        }else{
            printf("删除错误：不能大于总数\n");
        }
    }
    
}



/* 
 移除全部元素 
 */

void removeAll(ListNode *head){
    
    ListNode *p1,*p2;
    
    if (head->next == NULL) {
        
        printf("链表是空的 删除完毕");
        
        return ;
    }else{
        
        p1 = head ->next;
        
        if (p1->next == NULL) {
            
            head ->next = NULL;
            
            free(p1);
            
            return ;
            
        }else{
            
            p2 = p1 ->next;
            free(p1);
            head->next = p2;
            
        }
        
    }
    
    
    removeAll(head);
    
    
}


/*
 获取链表的长度
 */



int lenght(ListNode *head){
    
    static int len = 0;
    
    static ListNode *p1;
    
    if (head ->next == NULL) {
        return 0;
    }
    
    p1 = head ->next;
    
    len++;
    
    if (p1->next == NULL) {
        return len;
    }
    
    lenght(p1);
    
    
    return len;
}

/*
 检查链表是否为空
 */

int isNull(ListNode * head){
    
    if (head->next == NULL) {
        printf("链表为空\n");
        
        return 1;
    }
    printf("链表不为空\n");
    
    return 0;
}


/*
 返回单链表中第pos个结点中的元素，若pos超出范围，则停止程序运行
 */

ListNode *getObjectWithIndex(ListNode *head,int position){
    
    ListNode *p1;
    
    if (head->next == NULL || position <= 0) {
        printf("链表为空 或者position 为0");
        return NULL;
    }
    
    
    p1 = head->next;
    
    for (int i = 1; i <= position; i++) {
        
        if (i == position) {
            return p1;
        }
        
        
        if (p1->next == NULL) {
            printf("position 超出范围 跳出\n");
            free(p1);
            return NULL;
        }
        
        
        p1 = p1->next;
        
    }
    
    return p1;
    
    
}


/*
 从单链表中查找具有给定值x的第一个元素，若查找成功则返回该结点，否则返回NULL
 */
ListNode * getAddressWithName(ListNode * head,int score){
    

    
    if (head->next == NULL) {
        return NULL;
    }else{
        
        if (head->next->score == score) {
            
            printf("找到 name:%s,score:%d\n",head->next->name,head->next->score);
            
            return head->next;
        }else{
            getAddressWithName(head->next, score);
        }
        
        
    }
    
    
    return NULL;
    
    
    
}


/*
    在链表的表头插入一个元素
 */

void insertAtFirst(ListNode *head,ListNode *object){
    
    if (head->next ==NULL) {
    
        head->next = object;
        object->next = NULL;
        
    }else{
        
        ListNode * p1;
        
        p1 = head->next;
        
        head->next = object;
        object->next = p1;
        
        
    }
    
    
    
    
}

/*
 在链表的末尾插入一个元素
 */

void insertAtLast(ListNode *head,ListNode *object){
    
    
    if (head->next == NULL) {
        head->next = object;
        object ->next = NULL;
        return ;
    }else{
    
        insertAtLast(head->next, object);
    
    
    }
    
    
    
    
    
}



/*
 获取某一个位置的元素并返回
 */
ListNode * getPreListNode(ListNode *head, int i){
    
    ListNode *p1,*p2;
    int j = 0;
    int isOut = 0;
    
    if (i == 0) {
        
        if (head->next == NULL) {
            return NULL;
        }
        
        return head;
        
    }else if (i > 0){
        
        p1 = head;
        
        while (j < i - 1) {
            p1 = p1->next;
            
            if (p1 == NULL) {
                printf("删除错误：不能大于总数\n");
                isOut = 1;
                break;
            }
            
            j++;
            
        }
        
        if (isOut == 0 && p1->next != NULL) {
            
            p2 = p1->next;
            
            if (p2->next == NULL) {
                
                return NULL ;
            }
            
            return p2;
            
        }else{
            printf("错误：不能大于总数\n");
            
            return NULL ;
        }
        
    }else{
        printf("错误：不能小于0\n");
    }
    
    return NULL;
    
}



/*
 交换两个元素的位置
 */

void exchangePosition(ListNode *head, int firstPosition,int secondPosition){
    
    if (head->next == NULL) {
        printf("链表为空 直接返回\n");
        return ;
    }
    
    if (firstPosition == secondPosition) {
        printf("两个位置相同 无需交换 返回\n");
        return ;
    }
    
    if (firstPosition <= 0 || secondPosition <= 0) {
        printf("位置点小于等于0 无法交换 直接返回\n");
        return ;
    }
    
    ListNode *firstPre;
    ListNode *secondPre;
    
    firstPre = getPreListNode(head, firstPosition-1);         //  寻找 firstPosition 的前一个节点
    
    if (firstPre == NULL) {
        printf("没有找到firstPosition 的前一个节点 ，越界了  直接返回\n");
        return ;
    }else{
        printf("firstPosition 的前一个节点找到了  \n");
        
        
        secondPre = getPreListNode(head, secondPosition-1);     //  寻找 secondPosition 的前一个节点
        
        if (secondPre == NULL) {
            printf("没有找到secondPosition 的前一个节点 ，越界了  直接返回\n");
            return ;
        }
        
        printf("secondPosition 的前一个节点找到了 \n ");
        
    }
    
    
    ListNode *p1,*p2;
    p1 = firstPre->next;
    p2 = secondPre->next;
    
    if (p1->next == p2) {
        printf("firstPosition 是 secondPosition 的前节点\n");
        
        if (p2->next == NULL) {
            printf("secondPosition 是最后一个节点\n");
            
            firstPre->next = p2;
            p2->next = p1;
            p1->next = NULL;
            
            return ;
            
        }else{
            
            ListNode *secondNext;
            secondNext = p2->next;
            
            firstPre->next = p2;
            p2->next = p1;
            p1->next = secondNext;
            
            return ;
            
        }
        
        
    }else if (p2->next == p1){
        printf("secondPosition 是 firstPosition 的前节点\n");
        
        if (p1->next == NULL) {
            printf("firstPosition 是最后一个节点\n");
            
            secondPre->next = p1;
            p1->next = p2;
            p2->next = NULL;
            
            return ;
            
        }else{
            
            ListNode * firstNext;
            firstNext = p1->next;
            
            secondPre->next = p1;
            p1->next = p2;
            p2->next = firstNext;
            
            
        }
        
        
        
        
        
    }else{
        printf("两个交换的节点不相邻 \n");
        
        ListNode *firstNext,*secondNext;
        
        firstNext = p1->next;
        secondNext = p2->next;
        
        if (firstNext && secondNext) {
            printf("前后都存在 两个节点都不在末尾\n");
            
            firstPre->next = p2;
            p2->next = firstNext;
            
            secondPre->next = p1;
            p1->next = secondNext;
            
            
        }else if (firstNext == NULL){
            printf("firstPosition 在末尾\n");
            secondPre->next = p1;
            p1->next = secondNext;
            
            firstPre->next = p2;
            p2->next = NULL;
            
        }else if (secondNext == NULL){
            printf("secondPosition 在末尾\n");
            
            firstPre->next = p2;
            p2->next = firstNext;
            
            secondPre->next = p1;
            p1->next = NULL;
            
        }
    }
}


/*
 对单链表进行排序
 */

ListNode * sort(ListNode *pHead){
    
    ListNode* pCurr = (ListNode *)NULL;
    ListNode* pPost = (ListNode *)NULL;
    ListNode* pFirst = (ListNode *)NULL;
    ListNode* pPrev = (ListNode *)NULL;
    unsigned int uwLinkListLength = 0;
    unsigned int uwInnerLoopIndex = 0;
    unsigned int uwOuterLoopIndex = 0;
    
    if (NULL == pHead)
    {
        printf("链表是空的,直接返回\n");
        return (ListNode *)NULL;
    }
    
    pFirst = (ListNode *)malloc(sizeof(ListNode));
    if (NULL == pFirst)
    {
        return (ListNode *)NULL;
    }
    
    uwLinkListLength = lenght(pHead);
    uwOuterLoopIndex = uwLinkListLength;
    pFirst->next = pHead;
    
    while (uwOuterLoopIndex > 0)
    {
        pFirst->next = pHead;
        pCurr = pFirst->next;
        pPost = pCurr->next;
        
        uwInnerLoopIndex = uwOuterLoopIndex;
        while ((NULL != pPost) && (uwInnerLoopIndex > 0))
        {
            if (pCurr->score > pPost->score)
            {
                pFirst->next->next = pPost->next;
                pPost->next = pFirst->next;
                
                if (pHead == pFirst->next)
                {
                    pHead = pPost;
                    pPrev = pPost;
                }
                else
                {
                    pPrev->next = pPost;
                    pPrev = pPrev->next;
                }
                
                pPost = pCurr->next;
                pFirst->next = pCurr;
                
                
                
            }
            else
            {
                pPrev = pCurr;
                pCurr = pCurr->next;
                pPost = pCurr->next;
                pFirst->next = pCurr;
            }
            uwInnerLoopIndex--;
        }
        uwOuterLoopIndex--;
    }
    
    pFirst->next = NULL;
    free(pFirst);
    pFirst = NULL;
    return pHead;
}






int main(int argc, const char * argv[]) {
    
    
    DoubleList * head;
    head = creatDoubleList(3);
    
    printDoubleList(head);
    printf("\n");
        
    
    printf("\n\n");
    printDoubleList(head);
    printf("\n");
    
    
    
    return 0;
}

