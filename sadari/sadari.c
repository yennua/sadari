//산업보안학과 20201171 공예나
//프로그래밍 과제1 사다리

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
    
int main() {
    int cnt[5][5] = { {0, }, };
    int a;
    int x, index, flag;
	int n, i, j, k;
	
    srand((unsigned int)time(NULL));

    for (n = 0; n < 100; n++) {
        int list[10][4] = { {0, }, };
        int line[6] = { -1, };
        int result[5] = { 0, };

        //랜덤작성
        for (i = 0; i < 4; i++) {
            index = rand() % 2 + 4;
            for (j = 0; j < index; j++) {
                while (1) {
                    flag = 0;
                    a = rand() % 10;
                    for (k = 0; k < j+1; k++) {
                        //printf("%d %d %d\n", i, j, k);
                        if (line[k] == a) flag = 1;
                        else if (i >= 1) {
                            if (list[a][i - 1] == 1) flag = 1;
                        }
                    }
                    if (flag == 0) {
                        list[a][i] = 1;
                        line[j] = a;
                        break;
                    }
                }
            }
        }
        /*
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 4; j++) {
                printf("%d ", list[i][j]);
            }
            printf("\n");
        }
        */

        //사다리 출력
        printf("1  2  3  4  5\n");
        for (i = 0; i < 21; i++) {
            if (i % 2 == 0) printf("I  I  I  I  I\n");
            else {
                for (j = 0; j < 9; j++) {
                    if (j % 2 == 0) printf("+");
                    else if(list[i/2][j/2]==1) printf("--");
                    else printf("  ");
                }
                printf("\n");
            }
        }
        printf("A  B  C  D  E\n\n");

        //결과 계산
        for (k = 0; k < 5; k++) {
            x = k;
            for (i = 0; i < 10; i++) {
                if (x < 4) {
                    if (list[i][x] == 1) {
                        x++;
                        //printf("증가 ");
                        continue;
                    }
                }
                if (x > 0) {
                    if (list[i][x - 1] == 1) {
                        x--;
                        //printf("감소 ");
                    }
                }
            }
            result[k] = x;
            //printf("result: %d\n", x);
            cnt[k][x]++;
        }
        for (k = 0; k < 5; k++) {
            printf("%d -> ", k + 1);
            switch (result[k])
            {
            case 0:
                printf("A");
                break;
            case 1:
                printf("B");
                break;
            case 2:
                printf("C");
                break;
            case 3:
                printf("D");
                break;
            case 4:
                printf("E");
                break;
            }
            printf(", ");
        }
        printf("\n\n");
    }
    
    for (i = 0; i < 5; i++) {
        printf("%d: A(%d) B(%d) C(%d) D(%d) E(%d) :%d  \n", 
            i+1, cnt[i][0], cnt[i][1], cnt[i][2], cnt[i][3], cnt[i][4], 
            cnt[i][0]+cnt[i][1]+cnt[i][2]+cnt[i][3]+cnt[i][4]);
    }
}
