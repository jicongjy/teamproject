#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct {
    char day[100];//������ ��¥
    int point;//����Ʈ
    int num;//����
    char trans[100];//�������
    char place[100];//���� ���
    char diary[100];//����� ����
}data;

int SelectMenu(); //�޴��� �����ϴ� �Լ�
int GetPoint(data *d, int po); //�� �Ѱ� �ۼ� �� ����Ʈ�� ����
int ManagePoint(); //����Ʈ�� �����ϴ� �Լ�
int DeletePost(data *d); //���� �����ϴ� �Լ�
int CreatPost(data *d); //���� �߰��ϴ� �Լ�
void listPost(data* d[],int count); //��ϵ� �� ��� ���
void listDetail(data d[]); //���λ��� ���
int readPost(data d[]); //�ϳ��� �� ��� �Լ�
int UpdatePost(data* d); //���� �����ϴ� �Լ�
void Viewpoint(data *d);//����Ʈ�� Ȯ���ϴ� �Լ�
void saveData(data *d[], int count);//���������Լ�
int loadData(data* p[]);//���Ϸε��Լ�
void searchName(data* p[], int count);//�˻��ϴ� �Լ�
