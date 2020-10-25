/*
 * @Author: morningdrizzle
 * @Date: 2020-10-25 19:00:42
 * @LastEditors: morningdirzzle
 * @LastEditTime: 2020-10-29 21:14:11
 * @Description: file content
 */
#include <stdio.h>
#include <stdlib.h>
#define VERTEX_MAX_NUMBER 10

typedef struct edgenode{
    int index;   //这条边的另一个顶点的数组下标
    struct edgenode *next;
    int otherinfo;   //顶点包含的其他信息
}edgenode;

typedef struct vertexnode{
    struct edgenode *first;
    int vertexinfo;
}vertexnode;

typedef struct adjlistgraph{
    vertexnode adjlist[VERTEX_MAX_NUMBER];
    int  vertexnumber, edgenumber;
}adjlistgraph;

int locatevex(adjlistgraph  adj, int m){
    for (int i=0;i<adj.edgenumber;i++){
        if(adj.adjlist[i].vertexinfo==m+1)
            return i;
    }
    return -1;
}

void CreateGraph(adjlistgraph * alg){   //有向图
    printf("请输入顶点数和边数,以逗号隔开\n");
    scanf("%d,%d", &alg->vertexnumber, &alg->edgenumber);
    printf("请输入顶点信息\n");
    for(int i=0; i<alg->vertexnumber; i++){
        scanf("%d", &alg->adjlist[i].vertexinfo);
        alg->adjlist[i].first = NULL;
    }
    for (int i = 0; i < alg->edgenumber; i++){
        edgenode * mid = malloc(sizeof(edgenode));
        mid->next = NULL;
        edgenode * temp = NULL;
        
        int v1,v2,weight;
        printf("请输入顶点及其边对应的另一个点和权重，按空格分开\n");
        scanf("%d%d%d", &v1, &v2, &weight);
        int m = locatevex(*alg, v1);
        int n = locatevex(*alg, v2);
        
        if(-1==m || -1==n){
            printf("no this vertex%d,%d\n",m,n);
            exit(1);
        }
        mid->index = v2;
        mid->otherinfo = weight;
        
        temp = alg->adjlist[v1].first;
        
        alg->adjlist[v1].first =mid;
        mid->next = temp;
    }
    
    
}

void PrintGraph(adjlistgraph alg){
    edgenode * temp = NULL;
    for (int i = 0; i<alg.vertexnumber;i++){
        printf("%d\n", alg.adjlist[i].vertexinfo);
        temp = alg.adjlist[i].first;
        while(temp!=NULL){
            printf("%d,%d,%d;", alg.adjlist[i].vertexinfo, temp->next->index, temp->next->otherinfo);
            temp = temp->next;
        }
    }
}

int main(){
    adjlistgraph  alg;
    printf("aaaaaa\n");
    CreateGraph(&alg);
    PrintGraph(alg);
    return 0;
}
