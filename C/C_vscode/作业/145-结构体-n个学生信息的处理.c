#include <stdio.h>
#include <string.h>


struct Student {
    char id[20];
    char name[20];
    int score1;
    int score2;
    int score3;
};

void input(struct Student s[], int n) {

    int i;

    for (i = 0; i < n; i++) {
        scanf("%s %s %d %d %d", s[i].id, s[i].name, &s[i].score1, &s[i].score2, &s[i].score3);
    }
}

void output(struct Student s[], int n) {

    int i;

    printf("       No.      name score[1] score[2] score[3]  average\n");
    for (i = 0; i < n; i++) {
        printf("%10s%10s%9.2f%9.2f%9.2f%8.2f\n", s[i].id, s[i].name, s[i].score1 * 1.0, s[i].score2 * 1.0, s[i].score3 * 1.0, (s[i].score1 + s[i].score2 + s[i].score3) / 3.0);
    }
}

void max_aver(struct Student s[], int n) {

    int i;
    double average = 0;

    for (i = 0; i < n; i++) {
        average += ((s[i].score1 + s[i].score2 + s[i].score3) / 3.0);
    }

    printf("average=%6.2f\n", average * (1.0 / n));

    float highest_score = s[0].score1 + s[0].score2 + s[0].score3;
    char highest_id[20], highest_name[20];
    int highest_score1 = 0, highest_score2 = 0, highest_score3 = 0;

    for (i = 0; i < n; i++) {
        if (s[i].score1 + s[i].score2 + s[i].score3 > highest_score) {
            highest_score = s[i].score1 + s[i].score2 + s[i].score3;
            strcpy(highest_name,s[i].name);
            strcpy(highest_id, s[i].id);
            highest_score1 = s[i].score1;
            highest_score2 = s[i].score2;
            highest_score3 = s[i].score3;
        }
    }

    printf("The highest score is:%10s%10s\n", highest_id, highest_name);

    printf("His scores are:%6.2f%6.2f%6.2f,average:%6.2f\n", highest_score1 * 1.0, highest_score2 * 1.0, highest_score3 * 1.0, (highest_score1 + highest_score2 + highest_score3) / 3.0);

}

int main(int argc, char *argv[]) {

    int n;

    scanf("%d", &n);

    struct Student Students[n], *s = Students;

    input(s, n);

    output(s, n);

    max_aver(s, n);

    return 0;
}