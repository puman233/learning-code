//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main(int argc, char *argv[]) {
//
//    FILE *fp1, *fp2;
//    // char ch;
//    char word[10][100];
//    int i = 0;
//
//    fp1 = fopen("test1.txt", "r");
//
//    fp2 = fopen("reverse.txt", "w");
//
//    for (i = 0; i < 10; i++) {
//        // word[i] = (char*)malloc(sizeof(char) * 100);
//        if (fgets(word[i], 100, fp1) == NULL){
//            break;
//        }
//        // word[i][strlen(word[i]) - 1] = '\0';
//        word[i][strcspn(word[i], "\n")] = 0;
//    }
//    int count = i;
//
//    for (i = count - 1; i >= 0; i--) {
//        fprintf(fp2, "%s\n", word[i]);
//    }
//
//
//    // free(word);
//    fclose(fp1);
//    fclose(fp2);
//
//    return 0;
//}
