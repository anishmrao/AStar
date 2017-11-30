#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    int id;
    char name[10];
    int *connects;
    int *dists;
    int num;
    int cameFrom;
    int gscore;
    int fscore;
}node;



void init(node *nodes)
{
    int i=0;
    for(i=0; i<10; ++i)
    {
        nodes[i].cameFrom = i;
        nodes[i].gscore = 0;
        nodes[i].fscore = 0;
    }
    nodes[0].id = 0;
    strcpy(nodes[0].name, "A");
    nodes[0].connects = (int*)calloc(4, sizeof(int));
    nodes[0].connects[0] = 1;
    nodes[0].connects[1] = 4;
    nodes[0].connects[2] = 6;
    nodes[0].connects[3] = 9;
    nodes[0].dists = (int*)calloc(4, sizeof(int));
    nodes[0].dists[0] = 20;
    nodes[0].dists[1] = 65;
    nodes[0].dists[2] = 30;
    nodes[0].dists[3] = 110;
    nodes[0].num = 4;

    nodes[1].id = 1;
    strcpy(nodes[1].name, "B");
    nodes[1].connects = (int*)calloc(4, sizeof(int));
    nodes[1].connects[0] = 0;
    nodes[1].connects[1] = 2;
    nodes[1].connects[2] = 6;
    nodes[1].connects[3] = 7;
    nodes[1].dists = (int*)calloc(4, sizeof(int));
    nodes[1].dists[0] = 20;
    nodes[1].dists[1] = 40;
    nodes[1].dists[2] = 30;
    nodes[1].dists[3] = 84;
    nodes[1].num = 4;

    nodes[2].id = 2;
    strcpy(nodes[2].name, "C");
    nodes[2].connects = (int*)calloc(5, sizeof(int));
    nodes[2].connects[0] = 1;
    nodes[2].connects[1] = 3;
    nodes[2].connects[2] = 5;
    nodes[2].connects[3] = 6;
    nodes[2].connects[4] = 7;
    nodes[2].dists = (int*)calloc(5, sizeof(int));
    nodes[2].dists[0] = 40;
    nodes[2].dists[1] = 45;
    nodes[2].dists[2] = 85;
    nodes[2].dists[3] = 60;
    nodes[2].dists[4] = 100;
    nodes[2].num = 5;

    nodes[3].id = 3;
    strcpy(nodes[3].name, "D");
    nodes[3].connects = (int*)calloc(4, sizeof(int));
    nodes[3].connects[0] = 2;
    nodes[3].connects[1] = 5;
    nodes[3].connects[2] = 7;
    nodes[3].connects[3] = 8;
    nodes[3].dists = (int*)calloc(4, sizeof(int));
    nodes[3].dists[0] = 45;
    nodes[3].dists[1] = 50;
    nodes[3].dists[2] = 80;
    nodes[3].dists[3] = 46;
    nodes[3].num = 4;

    nodes[4].id = 4;
    strcpy(nodes[4].name, "E");
    nodes[4].connects = (int*)calloc(2, sizeof(int));
    nodes[4].connects[0] = 0;
    nodes[4].connects[1] = 7;
    nodes[4].dists = (int*)calloc(2, sizeof(int));
    nodes[4].dists[0] = 65;
    nodes[4].dists[1] = 85;
    nodes[4].num = 2;

    nodes[5].id = 5;
    strcpy(nodes[5].name, "F");
    nodes[5].connects = (int*)calloc(3, sizeof(int));
    nodes[5].connects[0] = 2;
    nodes[5].connects[1] = 3;
    nodes[5].connects[2] = 8;
    nodes[5].dists = (int*)calloc(3, sizeof(int));
    nodes[5].dists[0] = 85;
    nodes[5].dists[1] = 50;
    nodes[5].dists[2] = 30;
    nodes[5].num = 3;

    nodes[6].id = 6;
    strcpy(nodes[6].name, "G");
    nodes[6].connects = (int*)calloc(5, sizeof(int));
    nodes[6].connects[0] = 0;
    nodes[6].connects[1] = 1;
    nodes[6].connects[2] = 2;
    nodes[6].connects[3] = 8;
    nodes[6].connects[4] = 9;
    nodes[6].dists = (int*)calloc(5, sizeof(int));
    nodes[6].dists[0] = 30;
    nodes[6].dists[1] = 30;
    nodes[6].dists[2] = 60;
    nodes[6].dists[3] = 110;
    nodes[6].dists[4] = 90;
    nodes[6].num = 5;

    nodes[7].id = 7;
    strcpy(nodes[7].name, "H");
    nodes[7].connects = (int*)calloc(6, sizeof(int));
    nodes[7].connects[0] = 1;
    nodes[7].connects[1] = 2;
    nodes[7].connects[2] = 3;
    nodes[7].connects[3] = 4;
    nodes[7].connects[4] = 8;
    nodes[7].connects[5] = 9;
    nodes[7].dists = (int*)calloc(6, sizeof(int));
    nodes[7].dists[0] = 84;
    nodes[7].dists[1] = 100;
    nodes[7].dists[2] = 80;
    nodes[7].dists[3] = 85;
    nodes[7].dists[4] = 90;
    nodes[7].dists[5] = 60;
    nodes[7].num = 6;

    nodes[8].id = 8;
    strcpy(nodes[8].name, "I");
    nodes[8].connects = (int*)calloc(4, sizeof(int));
    nodes[8].connects[0] = 3;
    nodes[8].connects[1] = 5;
    nodes[8].connects[2] = 6;
    nodes[8].connects[3] = 7;
    nodes[8].dists = (int*)calloc(4, sizeof(int));
    nodes[8].dists[0] = 46;
    nodes[8].dists[1] = 30;
    nodes[8].dists[2] = 110;
    nodes[8].dists[3] = 90;
    nodes[8].num = 4;

    nodes[9].id = 9;
    strcpy(nodes[9].name, "J");
    nodes[9].connects = (int*)calloc(3, sizeof(int));
    nodes[9].connects[0] = 0;
    nodes[9].connects[1] = 6;
    nodes[9].connects[2] = 7;
    nodes[9].dists = (int*)calloc(3, sizeof(int));
    nodes[9].dists[0] = 110;
    nodes[9].dists[1] = 90;
    nodes[9].dists[2] = 60;
    nodes[9].num = 3;
}

void print_connects(node n)
{
    int i;
    for(i=0; i<n.num; ++i)
        printf("%d ", n.connects[i]);
    printf("\n");
}

void print_dists(node n)
{
    int i;
    for(i=0; i<n.num; ++i)
        printf("%d ", n.dists[i]);
    printf("\n");
}

void print_names_dists(node *nodes)
{
    int i =0, j=0;
    for(i=0; i<10; ++i)
    {
        for(j=0; j<nodes[i].num;++j)
            printf("  %s - %s : %d", nodes[i].name, nodes[nodes[i].connects[j]].name, nodes[i].dists[j]);
        printf("\n");
    }
}

void print_names(node *nodes, node n)
{
    int i;
    for(i=0; i<n.num; ++i)
        printf("%s ", nodes[n.connects[i]].name);
    printf("\n");
}





int get_dist(int index1, int index2)
{
    int adist[10][10];
    adist[0][0] = 0;
    adist[0][1] = 24;
    adist[0][2] = 64;
    adist[0][3] = 96;
    adist[0][4] = 65;
    adist[0][5] = 146;
    adist[0][6] = 30;
    adist[0][7] = 96;
    adist[0][8] = 140;
    adist[0][9] = 110;
    adist[1][0] = 20;
    adist[1][1] = 0;
    adist[1][2] = 40;
    adist[1][3] = 74;
    adist[1][4] = 86;
    adist[1][5] = 122;
    adist[1][6] = 30;
    adist[1][7] = 84;
    adist[1][8] = 117;
    adist[1][9] = 120;
    adist[2][0] = 64;
    adist[2][1] = 40;
    adist[2][2] = 0;
    adist[2][3] = 45;
    adist[2][4] = 128;
    adist[2][5] = 85;
    adist[2][6] = 60;
    adist[2][7] = 100;
    adist[2][8] = 96;
    adist[2][9] = 145;
    adist[3][0] = 96;
    adist[3][1] = 74;
    adist[3][2] = 45;
    adist[3][3] = 0;
    adist[3][4] = 140;
    adist[3][5] = 50;
    adist[3][6] = 70;
    adist[3][7] = 77;
    adist[3][8] = 46;
    adist[3][9] = 138;
    adist[4][0] = 65;
    adist[4][1] = adist[1][4];
    adist[4][2] = adist[2][4];
    adist[4][3] = adist[3][4];
    adist[4][4] = 0;
    adist[4][5] = 190;
    adist[4][6] = 71;
    adist[4][7] = 85;
    adist[4][8] = 173;
    adist[4][9] = 74;
    adist[5][0] = adist[0][5];
    adist[5][1] = adist[1][5];
    adist[5][2] = adist[2][5];
    adist[5][3] = adist[3][5];
    adist[5][4] = adist[4][5];
    adist[5][5] = 0;
    adist[5][6] = 120;
    adist[5][7] = 117;
    adist[5][8] = 30;
    adist[5][9] = 182;
    adist[6][0] = adist[0][6];
    adist[6][1] = adist[1][6];
    adist[6][2] = adist[2][6];
    adist[6][3] = adist[3][6];
    adist[6][4] = adist[4][6];
    adist[6][5] = adist[5][6];
    adist[6][6] = 0;
    adist[6][7] = 60;
    adist[6][8] = 110;
    adist[6][9] = 90;
    adist[7][0] = adist[0][7];
    adist[7][1] = adist[1][7];
    adist[7][2] = adist[2][7];
    adist[7][3] = adist[3][7];
    adist[7][4] = adist[4][7];
    adist[7][5] = adist[5][7];
    adist[7][6] = adist[6][7];
    adist[7][7] = 0;
    adist[7][8] = 90;
    adist[7][9] = 60;
    adist[8][0] = adist[0][8];
    adist[8][1] = adist[1][8];
    adist[8][2] = adist[2][8];
    adist[8][3] = adist[3][8];
    adist[8][4] = adist[4][8];
    adist[8][5] = adist[5][8];
    adist[8][6] = adist[6][8];
    adist[8][7] = adist[7][8];
    adist[8][8] = 0;
    adist[8][9] = 145;
    adist[9][0] = adist[0][9];
    adist[9][1] = adist[1][9];
    adist[9][2] = adist[2][9];
    adist[9][3] = adist[3][9];
    adist[9][4] = adist[4][9];
    adist[9][5] = adist[5][9];
    adist[9][6] = adist[6][9];
    adist[9][7] = adist[7][9];
    adist[9][8] = adist[8][9];
    adist[9][9] = 0;
    return adist[index1][index2];

}






int in_list(node *q, int connects, int fscore,int  num_in_open)
{
    int i;
    int flag=0;
    for(i=0;i<num_in_open;i++)
    {
        if(q[i].id==connects && q[i].fscore<fscore)
        {
            flag=1;
            printf("%s is in list with fscore less than %d\n", q[i].name, fscore);
            break;
        }


    }
    if(flag)
        return 1;
    else
    {
        printf("%c not in the list or has higher fscore in the list\n", 'A'+connects);
         return 0;
    }


}


int ret_smallest(node *open,int num_in_open)
{
   int min=open[0].fscore;
   int i=0;
   int index=0;
   for(i=1;i<num_in_open;i++)
   {
       if(min>open[i].fscore)
       {
           min=open[i].fscore;
           index=i;
       }
   }
   printf("Smallest in open : %s\n", open[index].name);
   return index;
}

node pop(int index,int *num_in_open,node *open)
{
    node ret;
    ret.id=open[index].id;
    ret.fscore=open[index].fscore;
    ret.gscore=open[index].gscore;
    ret.connects=open[index].connects;
    ret.cameFrom=open[index].cameFrom;
    ret.dists=open[index].dists;
    strcpy(ret.name,open[index].name);
    ret.num=open[index].num;


    int i=0;
    if(*num_in_open!=1)
    {


        for(i=index;i<((*num_in_open)-1);++i)
        {
        open[i]=open[i+1];
        }
    }
    *num_in_open-=1;
    printf("Returned node element: %s\n", ret.name);
    return ret;

}

void push(node *q, int *num_in_q,node *nodes ,int gscore ,int fscore,int connect,int top, int change)
{
    /*int i, flag=0, pos=0;
    for(i=0; i<*num_in_q; ++i)
        if(q[i].id == connect)
        {
            flag=1;
            pos=i;
            break;
        }
    if(flag)
    {
        q[pos].fscore = fscore;
        q[pos].gscore = gscore;
        q[pos].cameFrom = top;
    }
    else
    {*/
    node new_node=nodes[connect];
    new_node.fscore=fscore;
    new_node.gscore=gscore;
    new_node.cameFrom=top;
    q[*num_in_q]=new_node;
    //}
    *num_in_q+=1;
    if(change)
    {
        nodes[connect].cameFrom = top;
        //nodes[connect].fscore = fscore;
        //nodes[connect].gscore = gscore;
    }

    printf("Pushed value :%c\n",'A'+connect);

}

void print_open(node *open, int num_in_open)
{
    int i=0;
    printf("In open :");
    for(i=0; i<num_in_open; ++i)
        printf("%c -> %d ", 'A'+open[i].id, open[i].fscore);
    printf("\n");
}

node a_star(int node_start, int node_end, node *nodes)
{
    int fscore,gscore,hscore;
    node open[10], closed[10];
    open[0] = nodes[node_start];
    open[0].fscore = 0;
    open[0].gscore = 0;
    int num_in_open = 1, num_in_closed = 0;
    int flag = 0;
    node current;
    while(num_in_open!=0)
    {
        print_open(open, num_in_open);
        current = pop(ret_smallest(open,num_in_open), &num_in_open, open);//pop takes index and num and open. Returns node. ret_smallest returns an index of the smallest fscore.
        int top = current.id;
        printf("Current node: %c\n",'A'+top);
        int *connects = nodes[top].connects;
        int num_connects = nodes[current.id].num;
        int i;
        for(i=0; i<num_connects; ++i)
        {
            printf("Connecting node: %c\n", 'A'+connects[i]);

            if(connects[i] == node_end)
            {
                printf("Found\n");
                flag = 1;
                break;
            }
            gscore = get_dist(top, connects[i]) + current.gscore;
            hscore = get_dist(connects[i], node_end);
            fscore = gscore + hscore;
            printf("fscore of node %c :%d\n", 'A'+connects[i], fscore);
            if(in_list(open, connects[i],fscore, num_in_open))
                continue;
            if(in_list(closed, connects[i], fscore, num_in_closed))
                continue;
            else
                push(open, &num_in_open, nodes, gscore, fscore, connects[i], top, 1);
        }
        if(!flag)
        {
            push(closed, &num_in_closed, nodes, current.gscore, current.fscore, current.id , top, 0);
            //push(open, &num_in_open, nodes, current.gscore, current.fscore, current.id , top);
        }
        else
            break;

    }
    printf("Outside while loop.\nNo in open :%d\n", num_in_open);
    if(flag)
        return current;
    else
        return;

}

void print_full_path(node retval, node *nodes, int node_end, int node_start)
{
    char *path=(char*)calloc(10, sizeof(char));
    path[0] = 'A' + node_end;
    path[1] = retval.name[0];
    int i=2;
    if(retval.id == node_start)
        path[2] = '\0';
    else
    {
        //printf("%c -> %s ", 'A'+node_end, retval.name);
        while(retval.cameFrom!=node_start)
        {
            //printf("-> %c ", 'A'+retval.cameFrom);
            path[i++]='A'+retval.cameFrom;
            retval = nodes[retval.cameFrom];
        }
        path[i]='A'+retval.cameFrom;
        path[i+1]='\0';
    }

    path = strrev(path);
    for(i=0; path[i+1]!='\0'; ++i)
        printf("%c -> ", path[i]);
    printf("%c\n", path[i]);

}
int main()
{
    node nodes[10];
    init(nodes);
    int ext_list[10], num_in_ext_list=0, num_in_q=0;

    //print_connects(nodes[0]);
    print_names_dists(nodes);
    char start, end;
    printf("Enter the starting point :");
    scanf("%c", &start);
    fflush(stdin);
    printf("Enter destination :");
    scanf("%c", &end);
    int node_start = start - 'A';
    int node_end = end - 'A';
    //print_names(nodes, nodes[node_start]);
    //print_names(nodes, nodes[node_end]);
    node retval = a_star(node_start,node_end,nodes);
    print_full_path(retval, nodes, node_end, node_start);
    /*printf("Returned node :%s\n", retval.name);
    printf("Came from : %c\n", 'A'+retval.cameFrom);
    printf("Came from cameFrom: %s\n", nodes[retval.cameFrom].name);*/
    //printf("%d\n", ret_index_sdist(nodes, *q, node_end));
}
