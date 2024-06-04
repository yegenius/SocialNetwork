#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
char name[20];
int level; //BFS트리를 만들 때 필요한 변수로, 출발점으로부터의 거리를 나타낸다.
int visited; 
}element;

typedef struct queue* queuePointer;
struct queue{
element x;
queuePointer link;
};

typedef struct stack* stackPointer;
struct stack{
element x;
stackPointer link;
};

queuePointer front,rear;
stackPointer top;

char name[20][20];
int mat[20][20];
int span_mat[20][20];

void push(element x_in){
stackPointer temp;
temp=malloc(sizeof(*temp));
temp->x=x_in;
temp->link=top;
top=temp;
}

element pop(){
element item;
stackPointer temp;
temp=top;
if(temp==NULL) {exit(0);}
item=temp->x;
top=temp->link;
free(temp);
return item;
}


void add(element x_in){
queuePointer temp;
temp=malloc(sizeof(*temp));
temp->x=x_in;
temp->link=NULL;
if(front==NULL){
front=temp;
}
else rear->link=temp;
rear=temp;
}


element delete(){
element item;
if(front==NULL){
exit(0);
}
else {item=front->x;
front=front->link;
return item;
}
}

void make_matrix(char *name1,char *name2){
int j,k,l;
for(j=0;j<20;j++)
{

if(strcmp(name[j],name1)==0) k=j;
if(strcmp(name[j],name2)==0) l=j;

}
mat[k][l]=1;
mat[l][k]=1;
}
void hascycle(int m_len)
{
add(mat
while(front){

}
}
int mutual(int m_len,char* name1,char* name2)
{
char name_mat[m_len][20];
int i,j,k,l;

char *e1="first name not found";
char *e2="second name not found";
char *e3="first and second name not found";

k=-1; l=-1;
for(j=0;j<20;j++)
{
if(strcmp(name[j],name1)==0) k=j;
if(strcmp(name[j],name2)==0) l=j;
}

if(k==-1&&l==-1) {printf("%s", e3); return 1;}
else if(k==-1){ printf("%s",e1); return 1;}
else if(l==-1) {printf("%s",e2); return 1;}

else{
j=0;
for(i=0;i<m_len;i++){
if(mat[k][i]==1&&mat[l][i]==1) strcpy(name_mat[j++],name[i]);
}
for(i=0;i<j;i++){
printf("%s\n",name_mat[i]);
}
return 0;
}
}

int isfriend(char* name1,char* name2)
{
char *s="yes";
char *n="no";
char *e1="first name not found";
char *e2="second name not found";
char *e3="first and second name not found";

int j,k,l;
k=-1; l=-1;
for(j=0;j<20;j++)
{
if(strcmp(name[j],name1)==0) k=j;
if(strcmp(name[j],name2)==0) l=j;
}
if(k==-1&&l==-1) {printf("%s",e3);return 1;}
else if(k==-1) {printf("%s",e1);return 1;}
else if(l==-1) {printf("%s",e2);return 1;}

else if(mat[k][l]==1) {printf("%s",s); return 0;}
else{ printf("%s", n); return 0;}
}

int relation(int m_len,char* name1,char* name2){
element x;
int j;
int k; 
int l;
int i;
int lev; 
element m[m_len];
int o;
char *e1="first name not found";
char *e2="second name not found";
char *e3="first and second name not found";

rear=front=NULL; top=NULL;
k=-1; l=-1;lev=0;

for(j=0;j<m_len;j++){//name, visited와 level변수를 가진 element x로 이루어진 배열 m (길이 m_len)을 만든다.
strcpy(x.name,name[j]);
x.visited=0;x.level=0;
m[j]=x;
}

for(j=0;j<m_len;j++)
{
if(strcmp(name[j],name1)==0) k=j;
if(strcmp(name[j],name2)==0) l=j;
}
if(k==-1&&l==-1) {printf("%s",e3);return 1;}
else if(k==-1) {printf("%s",e1);return 1;}
else if(l==-1) {printf("%s",e2);return 1;}

else //name1(level 0)에서부터 시작해서 name2까지 시작vertex에서부터의 거리인 level을 저장하여 Breadth First Search tree를 만든 후, 이 tree에서 name2부터 시작해서 name1에 도달할 때까지 level이 1씩 감소되는 방향을 따라가며 vertex를 stack에 저장했다가 pop하면서 print한다.
{
m[k].visited=1;  m[k].level=0;
add(m[k]);
while(front){
x=delete();
for(j=0;j<m_len;j++)
{
if(strcmp(name[j],x.name)==0) k=j;
}
lev=m[k].level+1;
for(i=0;i<m_len;i++){
if(mat[k][i]==1&&m[i].visited==0) 
{
m[i].visited=1;
m[i].level=lev;
add(m[i]); 
span_mat[k][i]=1; 
span_mat[i][k]=1;
}
}
}

if(m[l].visited==0) { //두 번째 vertex가 방문되지 않았으면 두 vertex가 연결되지 않은 경우이므로 출력이 없다.
return 0;}

for(j=0;j<m_len;j++){//모든 vertex의 visited 변수 0으로 초기화
m[j].visited=0;
}

push(m[l]);  //두번째 vertex를 stack에 push하고 BFS트리를 따라 level이 1씩 감소하는 순서로 vertex들을 push했다가 첫번째 vertex에 도달하면 pop하면서 출력한다.
for(i=0;i<m_len;i++)
{
for(o=0;o<m_len;o++){
if(span_mat[o][l]==1){
if(m[o].level==(m[l].level-1))
{
push(m[o]);
if(strcmp(m[o].name,name1)==0)
{
while(top){
x=pop();
printf("%s\n",x.name);
}
return 0; 
}
l=o; break;
}
}
}
}

return 0;
}
}

int main(int argc, char *argv[])
{
char name3[40];
char temp[20];char command[20];FILE *r;FILE *w;int i;int j;char name1[20]; char name2[20];
int m_len;
element x;
if(argc!=2){printf("please write input file name\n");
}
r=fopen(argv[1],"r");
for(i=0;i<20;i++) //matrix 초기화
{
for(j=0;j<20;j++)
{
mat[i][j]=0;
}
}

for(i=0;i<20;i++) //BFS tree matrix 초기화
{
for(j=0;j<20;j++)
{
span_mat[i][j]=0;
}
}

i=0;j=0;m_len=0;
fscanf(r,"%s",temp);
while((strcmp("$",temp)!=0)){ //모든 이름을 name 배열에 저장한다.  
strcpy(name[m_len++],temp); 
fscanf(r,"%s",temp);
}

while(EOF!=fscanf(r,"%s %s",name1,name2)){//파일에서 읽어들인 것을 토대로 adjacency matrix를 만든다.
make_matrix(name1,name2);
}
fclose(r);

while(1){
    scanf("%s",command);
	  if(!strcmp(command,"isfriend"))
	  {
      scanf("%s %s",name1,name2);
      if(isfriend(name1,name2)==0) printf("\n$\n");
	  else printf("\n"); 
	  }
	  else if(!strcmp(command,"mutual"))
	  {
	  scanf("%s %s",name1,name2);
	  if(mutual(m_len,name1,name2)==0) printf("$\n");
	  else printf("\n");
	  }
	  else if(!strcmp(command,"relation"))
	  {
	  scanf("%s %s",name1,name2);
	  if(relation(m_len,name1,name2)==0) printf("$\n");
	  else printf("\n");
	  }
	  else if(!strcmp(command,"quit")){
	  return 0;
	  }
	  }
	  }