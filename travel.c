#include "travel.h"

int SelectMenu(){
    int menu;
    printf("\n*** �޴� ***\n");
    printf("1. �� �� ���\n");
    printf("2. �� �� ��ȸ\n");
    printf("3. �� ����\n");
    printf("4. �� ����\n");
    printf("5. ��������\n");
    printf("6. �˻�\n");
    printf("7. ����Ʈ ��ȸ\n");
    printf("8. �������� ��ȸ\n");
    printf("0. ����\n\n");
    printf("=> ���ϴ� �޴���? ");
    scanf("%d", &menu);
    return menu;
}

int Getpoint(data *d, int po){
    if(po==1)
    d->point++;
    else if(po==-1)
    d->point--;
    return 1;
}

void Viewpoint(data *d){
    printf("���� %d����Ʈ�� �����Ǿ� �ֽ��ϴ�." , d->point);
}

int DeletePost(data *d){
    int no;
    printf("������ �����Ͻðڽ��ϱ�?(����:1)");
    scanf("%d" , &no);
    if(no==1){
    d->day[0] = '\0';
    d->point = -1;
    d->num = -1;
    d->trans[0] = '\0';
    d->place[0] = '\0';
    d->diary[0] = '\0';
    printf("=> ������!\n");
    }
    Getpoint(d, -1);
    return 1;
}
int CreatPost(data *d){
    getchar();
    printf("������ ����? ");
    scanf(" %[^\n]s" , d->place);
    printf("������ ��¥��? ");
    scanf(" %[^\n]s" , d->day);
    printf("�̿��� ���������? ");
    scanf(" %[^\n]s" , d->trans);
    printf("����������? (�ְ� ������ 5���Դϴ�.)");
    scanf(" %d" , &d->num);
    printf("�߰��� ����� ������ �����Ӱ� ������ּ���.(100�� �̳��� �ۼ����ּ���!)");
    scanf(" %[^\n]s" , d->diary);
    printf("=>�߰���!");
    d->point=0;
    return 1;
}


int readPost(data d[]){
    printf("%s\n",d->diary);
}

void listPost(data* d[],int count){
    for(int i=0;i<count;i++){
        printf("%d) ���೯¥ %s \n��ϳ���: ",i+1,d[i]->day);
        readPost(d[i]);
    }
}

void listDetail(data d[]){
    printf("������ ��� %s\n",d->place);
    printf("������ ��¥ %s\n",d->day);
    printf("���� ����Ʈ %d\n",d->point);
    printf("���� ����\n");
    for(int i=0; i<d->num; i++)
        printf("��");
     for(int i=0; i<5-d->num; i++)
        printf("��");
        printf("\n");
    printf("�̿��� ������� %s",d->trans);
}
int UpdatePost(data* d){
    CreatPost(d);
}

void searchName(data* p[], int count){
    int scnt = 0;
    char search[20];
    int sea=0;
    printf("���� ��Ҹ� �Է��ϼ���");
    scanf("%s" , search);
    printf("================================\n");
        for(int i =0; i <count ; i++){ if(p[i]->point == -1) continue;
            if(strstr(p[i]->place, search)){
                 printf("%2d ", i+1);
                 printf("%d) ���೯¥ %s \n��ϳ���: ",i+1, p[i]->day);
                 readPost(p[i]);
                 listDetail(p[i]);
                 scnt++;
                 }
                }
    if(scnt == 0) printf("=> �˻��� ������ ����!");
        printf("\n");
    }


void saveData(data *d[], int count)
{
 FILE *fp;
 fp = fopen("diary.txt", "wt");

 for(int i = 0; i < count; i++){
 if(d[i]->day[0] == '\0') continue;

 fprintf(fp, "%s ", d[i]->day);
 fprintf(fp, "%d ",d[i]->point);
 fprintf(fp, "%d ",d[i]->num);
 fprintf(fp, "%s ",d[i]->trans);
 fprintf(fp, "%s ",d[i]->place);
 fprintf(fp, "%s \n",d[i]->diary);
 }
 fclose(fp);
 printf("=> �����! ");
}

int loadData(data* p[]){
    int i = 0;
    FILE *fp;
    fp = fopen("diary.txt", "rt");
    if(fp == NULL)
         printf("=>���� ����\n");
    else{
    for(; i < 100; i++){
         if(feof(fp)) break;
                 fscanf(fp, "%s", p[i]->day);
                 fscanf(fp, "%d", &p[i]->point);
                 fscanf(fp, "%d", &p[i]->num);
                 fscanf(fp, "%s", p[i]->trans);
                 fscanf(fp, "%s", p[i]->place);
                 fscanf(fp, "%s", p[i]->diary);
                }
    fclose(fp);
    printf("=> �ε� ����!\n");
    }
    return i;
}
