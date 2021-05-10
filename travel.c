#include <stdio.h>

typedef struct {
    char day[100];//여행한 날짜
    int point;//포인트
    int num;//별점
    char trans[100];//교통수단
    char place[100];//여행 장소
    char diary[100];//기록할 내용
}data;

int selectMenu(){
    int menu;
    printf("\n*** 메뉴 ***\n");
    printf("1. 새 글 등록\n");
    printf("2. 내 글 조회\n");
    printf("3. 글 삭제\n");
    printf("4. 글 수정\n");
    printf("5. 파일저장\n");
    printf("6. 검색\n");
    printf("7. 포인트 조회\n");
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
    return 1;
}
int CreatPost(data *d){
    getchar();
    printf("여행지 명은? ");
    scanf("%s" , d->place);
    printf("여행한 날짜는? ");
    scanf("%s" , d->day);
    printf("이용한 교통수단은? ");
    scanf("%d" , d->trans);
    printf("별점개수는? ");
    scanf("%d" , &d->num);
    printf("추가로 기록할 내용을 자유롭게 기록해주세요.");
    scanf("%s" , d->diary);
    printf("=>추가됨!");
    return 1;
}
