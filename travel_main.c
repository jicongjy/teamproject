#include "travel.h"

int main(){
    int menu;
    int count=0;
    data *d[100];
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
            //글 삭제
        }
        else if(menu==4){
            //글 수정
        }
        else if(menu==5){
            //파일 저장
        }
        else if(menu==6){
            // 검색
        }
        else if(menu==7){
            //포인트 조회
        }
    }
    //포인터에 배정된 공간 삭제
    for(int i=0;i<100;i++){
        free(d[i]);
    }
    return 0;
}
