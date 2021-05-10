#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct {
    char day[100];//여행한 날짜
    int point;//포인트
    int num;//별점
    char trans[100];//교통수단
    char place[100];//여행 장소
    char diary[100];//기록할 내용
}data;
void SelectMenu(); //메뉴를 선택하는 함수
int GetPoint(); //글 한개 작성 시 포인트를 지급
int ManagePoint(); //포인트를 관라히는 함수
int DeletePost(); //글을 삭제하는 함수
int CreatPost(); //글을 추가하는 함수
void listPost(); //등록된 글 목록 출력
void listDetail(); //세부사항 출력
int readPost(); //하나의 글 출력 함수
int UpdatePost(); //정보 수정하는 함수
