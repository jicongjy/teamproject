#include "travel.h"

int main(){
    int menu;
    int count=0;
    int choose;
    data *d[100];
    //�����Ϳ� ���� ����
    for(int i=0;i<100;i++){
        d[i]=malloc(sizeof(data));
    }
    count=loadData(d);
    
    while(menu!=0){
        menu=SelectMenu();

        if(menu==1){
            //���� ���
            count+=CreatPost(d[count]);
        }
        else if(menu==2){
            //�� ��ȸ
            listPost(d,count);
        }
        else if(menu==3){
            printf("������ ��ȣ�� ���ÿ�:\n");
            scanf("%d",&choose);
		DeletePost(d[choose-1]);
            //�� ����
        }
        else if(menu==4){
            printf("������ ��ȣ�� ���ÿ�:\n");
            scanf("%d",&choose);
		UpdatePost(d[choose-1]);
            //�� ����
        }
        else if(menu==5){
            saveData(d, count);
            //���� ����
        }
        else if(menu==6){
            searchName(d, count);
            // �˻�
        }
        else if(menu==7){
            printf("��ȸ�� ��ȣ�� ���ÿ�:\n");
            scanf("%d",&choose);
		Viewpoint(d[choose-1]);
            //����Ʈ ��ȸ
        }
	else if(menu==8){
            printf("��ȸ�� ��ȣ�� ���ÿ�:\n");
            scanf("%d",&choose);
            listDetail(d[choose-1]);
		//���� ���� 
	}
    }
    //�����Ϳ� ������ ���� ����
    for(int i=0;i<100;i++){
        free(d[i]);
    }
    return 0; 
}

