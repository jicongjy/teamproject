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

int SelectMenu(); //메뉴를 선택하는 함수
int GetPoint(data *d, int po); //글 한개 작성 시 포인트를 지급
int ManagePoint(); //포인트를 관리하는 함수
int DeletePost(data *d); //글을 삭제하는 함수
int CreatPost(data *d); //글을 추가하는 함수
void listPost(data* d[],int count); //등록된 글 목록 출력
void listDetail(data d[]); //세부사항 출력
int readPost(data d[]); //하나의 글 출력 함수
int UpdatePost(data* d); //정보 수정하는 함수
void Viewpoint(data *d);//포인트를 확인하는 함수
void saveData(data *d[], int count);//파일저장함수
int loadData(data* p[]);//파일로드함수
void searchName(data* p[], int count);//검색하는 함수
