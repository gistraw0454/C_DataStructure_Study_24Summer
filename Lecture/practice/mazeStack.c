#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define NONBLOCKED 0	// 뚫린 길
#define BLOCKED 1		// 벽
#define PATH 2			// 맞는 길
#define VISITED 3		// 방문함

#define WIDTH 8			// 미로의 너비
#define HEIGHT 8		// 미로의 높이


int maze[WIDTH][HEIGHT] = {
	0, 0, 0, 1, 1, 0, 1, 0,
	1, 1, 0, 0, 0, 0, 1, 0,
	0, 1, 0, 1, 1, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 1, 1,
	1, 1, 0, 1, 0, 1, 0, 0,
	0, 0, 0, 1, 1, 1, 1, 0,
	0, 1, 0, 0, 0, 0, 0, 0,
	0, 1, 1, 1, 0, 1, 1, 0
};

int visited[WIDTH][HEIGHT] = { 0, };

const int ENTRY_ROW = 0;
const int ENTRY_COL = 0;

const int GOAL_ROW = 7;
const int GOAL_COL = 7;

void trace() {
	int i, j;
	int tmp_map[WIDTH][HEIGHT] = { 0 };

	for (i = 0; i < HEIGHT; ++i) {
		for (j = 0; j < WIDTH; ++j) {
			if (maze[i][j] == BLOCKED) {
				printf("■");
			}
			else if (maze[i][j] == PATH) {
				printf("☆");
			}
			else {
				printf("□");
			}
		}
		printf("\n");
	}
}

// 도착지에 제대로 도착하면 TRUE
// 아직 도착지가 아닌 칸이면 FALSE
int push(int r, int c){

    //이미 방문했던 칸이니?
    if (visited[r][c]==VISITED)
        return FALSE;
    //else 방문 안했으면 방문했음을표시
    visited[r][c]=VISITED;

    //벽이니?
    if (maze[r][c]==BLOCKED){
        return FALSE;
    }

    //벽도 아니고 길이긴 길이니까 PATH로 표시
    int tmp = maze[r][c];    //현재 칸의 원래 데이터 보관(덮어쓰기위해서)
    maze[r][c] = PATH;

    //도착했나?
    if (r==GOAL_ROW && c==GOAL_COL)
        return TRUE;

    //왼쪽칸으로 push() 재실행
    if(c>0 && push(r,c-1)){ //c가 첫번째 열이 아니고,왼쪽으로 한칸간게 도착지면?
        return TRUE;
    }

    //윗쪽 칸으로 push() 재실행
    if(r>0 && push(r-1,c)){ 
        return TRUE;
    }

    //오른쪽 칸으로 push() 재실행
    if(c<WIDTH-1 && push(r,c+1)){ 
        return TRUE;
    }

    //오른쪽 칸으로 push() 재실행
    if(r<HEIGHT-1 && push(r+1,c)){ 
        return TRUE;
    }

    //다쳐다봤는데 길이없다면 길이 잘못됐다.
    maze[r][c]=tmp; // PATH가 아니니까 PATH로 표시한거 취소 !
    return FALSE;
}
int main(){
    push(ENTRY_ROW,ENTRY_COL);
    trace();
}