#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
char name[20];
int level; //BFSƮ���� ���� �� �ʿ��� ������, ��������κ����� �Ÿ��� ��Ÿ����.
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

for(j=0;j<m_len;j++){//name, visited�� level������ ���� element x�� �̷���� �迭 m (���� m_len)�� �����.
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

else //name1(level 0)�������� �����ؼ� name2���� ����vertex���������� �Ÿ��� level�� �����Ͽ� Breadth First Search tree�� ���� ��, �� tree���� name2���� �����ؼ� name1�� ������ ������ level�� 1�� ���ҵǴ� ������ ���󰡸� vertex�� stack�� �����ߴٰ� pop�ϸ鼭 print�Ѵ�.
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

if(m[l].visited==0) { //�� ��° vertex�� �湮���� �ʾ����� �� vertex�� ������� ���� ����̹Ƿ� ����� ����.
return 0;}

for(j=0;j<m_len;j++){//��� vertex�� visited ���� 0���� �ʱ�ȭ
m[j].visited=0;
}

push(m[l]);  //�ι�° vertex�� stack�� push�ϰ� BFSƮ���� ���� level�� 1�� �����ϴ� ������ vertex���� push�ߴٰ� ù��° vertex�� �����ϸ� pop�ϸ鼭 ����Ѵ�.
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
for(i=0;i<20;i++) //matrix �ʱ�ȭ
{
for(j=0;j<20;j++)
{
mat[i][j]=0;
}
}

for(i=0;i<20;i++) //BFS tree matrix �ʱ�ȭ
{
for(j=0;j<20;j++)
{
span_mat[i][j]=0;
}
}

i=0;j=0;m_len=0;
fscanf(r,"%s",temp);
while((strcmp("$",temp)!=0)){ //��� �̸��� name �迭�� �����Ѵ�.  
strcpy(name[m_len++],temp); 
fscanf(r,"%s",temp);
}

while(EOF!=fscanf(r,"%s %s",name1,name2)){//���Ͽ��� �о���� ���� ���� adjacency matrix�� �����.
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