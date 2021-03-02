#include <stdio.h>

struct info {
    char name[20];
    double score;
    int credit;
};

int input_data(struct info st[5], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d번 째 학생의 이름, 평점 평균, 취득 학점을 입력하세요.", i+1);
        scanf("%s", st[i].name);
        scanf("%lf", &st[i].score);
        scanf("%d", &st[i].credit);
    }

    for(int i = 0; i < n; i++) {
        printf("이름 \t 취득 학점 \t 평점 평균\n");
        printf("%-10s\t%1f\t%2d\n", st[i].name, st[i].score, st[i].credit);
    }

    return 0;
}

int scholarship(struct info st[5], int n) {
    printf("장학생\n");

    for(int i = 0; i < n; i++) {
        if(st[i].score >= 4.3 && st[i].credit >=20) {
             printf("%-10s %1f %2d\n", st[i].name, st[i].score, st[i].credit);
        }
    }
    return 0;
}

int main(void) {
    struct info students[5];
    input_data(students, 5);
    scholarship(students, 5);
    return 0;
}