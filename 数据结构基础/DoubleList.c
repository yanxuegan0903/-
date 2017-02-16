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
    DoubleList *p = NULL, *precede;
    
    head = (DoubleList *)malloc(sizeof(DoubleList));
    head->next = NULL;
    head->pre = NULL;
    
    precede = head;
    
    
    for (int i = 1; i<=count; i++) {
        
        p = (DoubleList*)malloc(sizeof(DoubleList));
        
        printf("请输入第%d个学生的名字:",i);
        scanf("%s",p->name);
        printf("请输入第%d个学生的成绩:",i);
        scanf("%d",&p->score);
        
        precede->next = p;
        p->pre = precede;
        
        
        precede = p;
        
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



