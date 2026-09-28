#include<stdio.h>
#include<string.h>

int main(void)
{
    char str1[20], str2[20], str3[20], strmax[20];
    /*
        dev c++ 
    scanf("%s", str1);
    scanf("%s", str2);
    scanf("%s", str3);
    
    strcpy(strmax, str1);

    if (strcmp(str1, str2) < 0) {
        strcpy(strmax, str2);
        if (strcmp(str2, str3) < 0)
        {
            strcpy(strmax, str3);
        }
    }
    else if (strcmp(str1, str3) < 0)
    {
        strcpy(strmax, str3);
        if (strcmp(str2, str3)< 0)
        {
            strcpy(strmax, str3);
        }
    }*/
    scanf_s("%19s", str1, 20);
    scanf_s("%19s", str2, 20);
    scanf_s("%19s", str3, 20);

    char* strcpy(strmax, str1);

    if (strcmp(str1, str2) < 0) {
        strcpy(strmax, str2);
        if (strcmp(str2, str3) < 0)
        {
            strcpy(strmax, str3);
        }
    }
    else if (strcmp(str1, str3) < 0)
    {
        strcpy(strmax, str3);
        if (strcmp(str2, str3) < 0)
        {
            strcpy(strmax, str3);
        }
    }
    


    printf("The maximum string is: %s\n", strmax);
    
    return 0;
}

