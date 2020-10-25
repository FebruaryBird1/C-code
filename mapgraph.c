/*
 * @Author: morningdrizzle
 * @Date: 2020-10-21 16:26:09
 * @LastEditors: morningdirzzle
 * @LastEditTime: 2020-10-25 18:50:46
 * @Description: file content
 */
#include <stdio.h>


#define MAX_V_NUM 20  //最大的顶点个数，即二维矩阵的长宽
#define V_TYPE int    //定义顶点
#define EXTRAINFO_TYPE  char  //顶点包含的其他额外信息的指针变量类型
#define V_DATA_TYPE int   // 顶点的数据类型
typedef enum{
    DG, DN, UDG, UDN
} G_Kind;     //枚举图的四种类型


typedef struct{
    V_DATA_TYPE adj;    //二维数组中的元素值，1表示对应行列坐标的顶点有边，0表示没有边，其他值表示权值
    EXTRAINFO_TYPE * info;    //弧或边额外含有的信息
}Cell, Matrix[MAX_V_NUM][MAX_V_NUM];

typedef struct {
    V_DATA_TYPE vexs[MAX_V_NUM];   //顶点数据
    Matrix arcs;      //用二维数组表示图的顶点和边及其关系
    G_Kind  kind;    //图的种类
    int vexnum, arcnum;   //顶点数和边数
}MGraph;

int LocateVex(MGraph * g, V_DATA_TYPE v){
    int i = 0;
    for(; i<g->vexnum; i++){
        if(g->vexs[i] == v)
            break;
        else{
            printf("没有这个顶点");
            return -1;
        }
    }
    return i;
}


void CreateUDG(MGraph * g){
    printf("请输入定点数和边数，中间以逗号隔开\n");
    scanf("%d,%d", &(g->vexnum), &(g->arcnum));    //输入图的顶点数和边数
    for(int i=0; i<g->vexnum; i++){
        scanf("%d", &(g->vexs[i]));                 //输入对应顶点的下标
    }
    for(int i=0; i<g->vexnum; i++){
        for(int j=0; j<g->vexnum; j++){          //初始化二维数组
            g->arcs[i][j].adj = 0;
            g->arcs[i][j].info = NULL;
        }
    }
    //遍历每条边，然后输入顶点信息，修改矩阵的值为全职
    for(int i=0; i<g->arcnum; i++){
        int v1, v2, w;//申明边的顶点和权值
        scanf("%d%d%d",&v1, &v2, &w);
        int m=LocateVex(g, v1);
        int n=LocateVex(g, v2);
        if(-1==m || -1==n){
            printf("no this vertex\n");
            return;
        } 
        g->arcs[n][m].adj=w; 
        //将v1,v2对应矩阵的点赋值，如果是无向图，还要在对称点同样操作，因为v2到v1也是有联系的
        //g->arcs[m][n]=w;
    }
}

void PrintGrapth(MGraph G)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        for (int j = 0; j < G.vexnum; j++)
        {
            printf("%d ", G.arcs[i][j].adj);
        }
        printf("\n");
    }
}

int main(int argc, char **argv){
    MGraph g;
    CreateUDG(&g);
    PrintGrapth(g);
    printf("\naaaaaa你是傻叉么");
    return 0;
}