//
//  DoubleList.c
//  数据结构基础
//
//  Created by vsKing on 2017/2/16.
//  Copyright © 2017年 vsKing. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DoubleNode {
    char name[10];
    int score;
    struct DoubleNode *next;
    struct DoubleNode *pre;
};

typedef struct DoubleNode DoubleList;


DoubleList *creatDoubleList(int count){
    
    DoubleList *head;
    DoubleList *p = NULL, *pre;
    
    head = (DoubleList *)malloc(sizeof(DoubleList));
    head->next = NULL;
    head->pre = NULL;
    
    pre = head;
    
    
    for (int i = 1; i<=count; i++) {
        
        p = (DoubleList*)malloc(sizeof(DoubleList));
        
        printf("请输入第%d个学生的名字:",i);
        scanf("%s",p->name);
        printf("请输入第%d个学生的成绩:",i);
        scanf("%d",&p->score);
        
        pre->next = p;
        p->pre = pre;
        
        
        pre = p;
        
    }
    
    
    if (count > 0) {
        p->next = NULL;
    }
    
    
    return head;
    
}


void printDoubleList(DoubleList *head){
    
    DoubleList *p;
    p = head->next;
    
    while (p != NULL) {
        printf("name:%s,score:%d",p->name,p->score);
        p = p->next;
        printf("\n");
    }
    
}


void insertDoubleList(DoubleList *head,int position,DoubleList * object){
    
    if (position < 1) {
        printf("插入错误: position 不能小于1");
        return ;
    }
    
    
    
    DoubleList *p1,*p2;
    
    
    p1 = head;
    
    int isout = 0;
    
    
    for (int i = 1; i < position; i++) {
        
        p1 = p1->next;
        
        if (p1 == NULL) {
            printf("插入错误：越界\n");
            isout = 1;
            break ;
        }
        
    }
    
    if (isout == 0) {
        
        p2 = p1->next;
        
        p1->next = object;
        object->pre = p1;
        
        object->next = p2;
        if (p2) {
            p2->pre = object;
        }
        
        
        
    }
    

}



