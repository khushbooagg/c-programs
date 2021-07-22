#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct guest{
    char name[100],sex[10];
    int age,id_num,room_num;
} guest;

int main(){
    printf("--- HOTEL MANAGEMENT SYSTEM ---\n\n");
    char filename[20] = {"guest.txt"};
    FILE* fp = fopen(filename, "a+");
    if(fp == NULL){
        printf("ERROR\n");
        return -1;
    }
    int x;
    while(1){
        printf("(1) - for adding/checkin guest details\n");
        printf("(2) - for listing guests\n");
        printf("(3) - for checkout guests\n");
        printf("(4) - to exit\n");
        scanf("%d", &x);
        fp = fopen(filename, "a+");
        if(x == 4) break;
        if(x == 1){
            guest i;
            printf("Enter the details of the guest\n ");
            printf("Enter name ");
            getchar();
            gets(i.name);
            printf("Enter the sex ");
            gets(i.sex);
            printf("Enter the age ");
            scanf("%d", &i.age);
            printf("Enter the id number ");
            scanf("%d", &i.id_num);
            printf("Enter the room number ");
            scanf("%d", &i.room_num);
            fprintf(fp,"%s\n%s\n%d\n%d\n%d\n\n",i.name,i.sex,i.age,i.id_num,i.room_num);
        } else if(x == 2) {
            printf("\n");
            guest i;
            char agg[50];
            int a = 0;
            while(fgets(agg, 100, fp)){
                if(agg[0] == '\n'){
                    printf("Name : %s\nsex : %s\n  age : %d\nid number : %d\nroom number : %d\n", i.name, i.sex, i.age, i.id_num, i.room_num);
                    a = 0;
                    continue;
                }
                if(a == 0) strcpy(i.name, agg); 
                else if(a == 1) strcpy(i.sex, agg);
                else if(a == 2)i.age = atoi(agg);
                else if(a == 3)i.id_num = atoi(agg);
                else i.room_num = atoi(agg);
                a++;//copies the values and helps in displaying
            }
            printf("\n");
        } else {
            char name[100], agg[100], s[100];
            printf("Enter the name of guest to check out: ");
            getchar();
            gets(name);
            FILE* rec = fopen("rec.txt", "w");
            int a = 0;
            while(fgets(agg, 100, fp)){
                strcpy(s, agg);
                if(strcmp(name, s) == 0 || (sscanf(s, "%s\n", s) && strcmp(name, s) == 0)){
                    printf("guest checked out\n");
                    a = 1;
                    continue;
                }
                if(a == 1 || a == 2 || a == 3 || a == 4){
                    a++;
                    continue;
                }
                fprintf(rec, "%s", agg);
            }
            fclose(fp);
            fclose(rec);
            rec= fopen("rec.txt", "r");
            fp = fopen("guest.txt", "w");
            while(fgets(agg, 100, rec)){
                fprintf(fp, "%s", agg);
            }
            fclose(rec);
      
      
             remove("guest.txt");
        rename("rec.txt","guest.txt");
      
      
        }
        fclose(fp);
    }
    printf("\n- thankyou for your stay -\n");
    return 0;
}
