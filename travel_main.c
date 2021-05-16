#include "travel.h"

int main(){
    int menu;
    int count=0;
    int choose;
    data *d[100];
    count=loadData(d);
    //포인터에 공간 배정
    for(int i=0;i<100;i++){
        d[i]=malloc(sizeof(data));
    }
    
    while(menu!=0){
        menu=SelectMenu();

        if(menu==1){
            //새글 등록
            count+=CreatPost(d[count]);
        }
        else if(menu==2){
            //글 조회
            listPost(d,count);
        }
        else if(menu==3){
            printf("삭제할 번호를 고르시오:\n");
            scanf("%d",&choose);
		DeletePost(d[choose-1]);
            //글 삭제
        }
        else if(menu==4){
            printf("수정할 번호를 고르시오:\n");
            scanf("%d",&choose);
		UpdatePost(d[choose-1]);
            //글 수정
        }
        else if(menu==5){
            saveData(d, count);
            //파일 저장
        }
        else if(menu==6){
            searchName(d, count);
            // 검색
        }
        else if(menu==7){
            printf("조회할 번호를 고르시오:\n");
            scanf("%d",&choose);
		Viewpoint(d[choose-1]);
            //포인트 조회
        }
	else if(menu==8){
            printf("조회할 번호를 고르시오:\n");
            scanf("%d",&choose);
            listDetail(d[choose-1]);
		//세부 정보 
	}
    }
    //포인터에 배정된 공간 삭제
    for(int i=0;i<100;i++){
        free(d[i]);
    }
    return 0; 
}

