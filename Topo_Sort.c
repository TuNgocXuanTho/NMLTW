#include <stdio.h>
#define MAX_N 100
//Danh sach 
typedef struct {
	int elements[100];
	int size;
}List;
void makenullList (List *L){
	L->size=0;
}
void push_back (List *L, int x){
	L->elements[L->size]=x;
	L->size++;
}
int element_at (List L, int i){
	return L.elements[i];
}
//Hang doi
typedef struct{
	int Element[100];
	int front,rear;
}Queue;
void makenullQueue (Queue *Q){
	Q->front = 0;
	Q->rear = -1;
}
int emptyQueue(Queue Q){
	if(Q.front==0 && Q.rear==-1) return 1;
	return 0;
}
void enQueue(Queue *Q, int x){
	Q->rear++;
	Q->Element[Q->rear]=x;
}
void dequeue(Queue *Q){
	Q->front++;
}
int front(Queue Q){
	return Q.Element[Q.front];
}
typedef struct{
	int n,m;
	int A[MAX_N][MAX_N];
}Graph;
void init_graph(Graph *G, int n){
	G->n=n;
	G->m=0;
	int i,j;
	for (i=1;i<=n;i++){
		for (j=1; j<=n; j++)
			G->A[i][j]=0;
	}
}
void add_edge(Graph *G,int u, int v){
    G->A[u][v]++;//do thi co huong
    //G->A[v][u]++;//them vao neu la do thi vo huong
    G->m++;
}
int degree(Graph G,int u){
	int deg_u=0, v;
	for (v=1; v<=G.n; v++)
		deg_u +=G.A[u][v];//vo huong
		//deg_u +=G.A[u][v]+G.A[v][u];//co huong
	return deg_u +=G.A[u][u];
}
int adjacent (Graph G, int u, int v){
	return G.A[u][v];
}
void topo_sort(Graph *G, List *L){
	//tinh d[u]
	int d[100];
	int u,x;
	for (u =1; u<=G->n; u++){
		d[u]=0;
		for (x=1; x<=G->n; x++)
			if(G->A[x][u]!=0)
				d[u]++;
	}
	Queue Q;
	makenullQueue(&Q);
	//dua d[u]=0 vao Q
	for (u=1; u<=G->n; u++)
		if (d[u]==0)
			enQueue (&Q,u);
	makenullList(L);
	while (!emptyQueue(Q)){
		u = front (Q);
		int v;
		dequeue(&Q);
		push_back(L,u);
		for (v=1; v<= G->n; v++)
			if (adjacent(*G,u,v)!=0){
				d[v]--;
				if (d[v]==0)
					enQueue (&Q,v);
			}
	}
}
int main(){
	Graph G;
	List L;
	int n,u,v,i,m;
	freopen ("DATA.txt","r",(stdin));
	scanf ("%d%d",&n,&m);
	init_graph(&G,n);
	for (i=1; i<=m; i++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	makenullList(&L);
	topo_sort(&G,&L);
	for (i=1;i<=n;i++)
		printf("%d ",element_at (L,i));
	return 0;
}
