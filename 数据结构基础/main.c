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
    
    ListNode *p1;
    
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


int main(int argc, const char * argv[]) {
    
    
    ListNode * head;
    head = creatList(0);
    
    printList(head);
    printf("\n");
    
    
    printf("链表长度为：%d \n",lenght(head));
    
    
    
    printf("移除后的链表为：\n");
    printList(head);
    printf("\n");
    
    
    isNull(head);
    
    
    return 0;
}

