#include "travel.h"

int SelectMenu(){
    int menu;
    printf("\n*** 메뉴 ***\n");
    printf("1. 새 글 등록\n");
    printf("2. 내 글 조회\n");
    printf("3. 글 삭제\n");
    printf("4. 글 수정\n");
    printf("5. 파일저장\n");
    printf("6. 검색\n");
    printf("7. 포인트 조회\n");
    printf("8. 세부정보 조회\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
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
    printf("현재 %d포인트가 적립되어 있습니다." , d->point);
}

int DeletePost(data *d){
    int no;
    printf("정말로 삭제하시겠습니까?(삭제:1)");
    scanf("%d" , &no);
    if(no==1){
    d->day[0] = '\0';
    d->point = 0;
    d->num = 0;
    d->trans[0] = '\0';
    d->place[0] = '\0';
    d->diary[0] = '\0';
    printf("=> 삭제됨!\n");
    }
    Getpoint(d, -1);
    return 1;
}
int CreatPost(data *d){
    getchar();
    printf("여행지 명은? ");
    scanf(" %[^\n]s" , d->place);
    printf("여행한 날짜는? ");
    scanf(" %[^\n]s" , d->day);
    printf("이용한 교통수단은? ");
    scanf(" %[^\n]s" , d->trans);
    printf("별점개수는? (최고 별점은 5점입니다.)");
    scanf(" %d" , &d->num);
    printf("추가로 기록할 내용을 자유롭게 기록해주세요.(100자 이내로 작성해주세요!)");
    scanf(" %[^\n]s" , d->diary);
    printf("=>추가됨!");
    return 1;
}


int readPost(data d[]){
    printf("%s\n",d->diary);
}

void listPost(data* d[],int count){
    for(int i=0;i<count;i++){
        printf("%d) 여행날짜 %s \n기록내용: ",i+1,d[i]->day);
        readPost(d[i]);
    }
}

void listDetail(data d[]){
    printf("여행한 장소 %s\n",d->place);
    printf("여행한 날짜 %s\n",d->day);
    printf("현재 포인트 %d\n",d->point);
    printf("현재 별점\n");
    for(int i=0; i<d->num; i++)
        printf("★");
     for(int i=0; i<5-d->num; i++)
        printf("☆");
        printf("\n");
    printf("이용한 교통수단 %s",d->trans);
}
int UpdatePost(data* d){
    CreatPost(d);
}

void save(data *d[], int count)
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
 printf("=> 저장됨! ");
}