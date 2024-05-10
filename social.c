//Author: Nilay Gupta 
#include <stdio.h>
#include <string.h>  
int d=0;  
int gn=0;
int check(char[] ,char[]);
struct User {
    char userID[50];
    char name[50];
    int age;
    struct User *friends[100];
    int friend_count; 
};
int check_friends(struct User *user1, struct User *user2);
void addFriend(struct User *user1, struct User *user2);
float calculatefriendshipStrength(struct User*user1);
int check_mutuals(struct User *user1, struct User *user2);
void generatefriendshipRecommendation(struct User*user1);
int check1(char a[],char b[]);
int main(){
    struct User all_user[100];
    char userID[50];
    int age;
    printf("To stop the prompt enter 0 when prompt asks user name\n");
    printf("Line 1: Enter the name of user\n"); 
    printf("Line 2: Enter the USER ID of user\n");
    printf("Line 3: Enter the age of user \n");
    char name[50];
    int i;
    for (i = 0; i < 100; i++) {
    gets(name);
    if ((int)name[0] == (int)'0') { 
        break;
    }
    for(int j=0;j<strlen(name);j++){
        all_user[i].name[j]=name[j];
    }
    scanf("%s", all_user[i].userID);
    scanf("%d", &all_user[i].age);
    printf("\n");
    getchar();
}
gn=i;
for(int j=0;j<i;j++){
    all_user[j].friend_count=0;
}
printf("Enter friends user ids to add as friends\nfor eg: rahul69 reema123\n Enter 0 to stop\n");
printf("To stop the prompt enter 0\n");
int d=0;
for(int j=0;j<50;j++){
    char f1[50];
    char f2[50];
    int index1=-1;
    int index2=-1;
    scanf("%s",f1);
    if(f1[0]=='0'){
        break;
    }
     for(int s=0;s<i;s++){
        if(check1(all_user[s].userID,f1)==0){
            index1=s;
            break;
        }
     }
    scanf("%s",f2);
    for(int s=0;s<i;s++){
        if(check1(all_user[s].userID,f2)==0){
            index2=s;
            break;
        } 
    
    }
    if(index2!=-1 && index1!=-1){
    addFriend(&all_user[index1],&all_user[index2]);
    }
    else{
        printf("friends not found\n");
    }
}
for(int n=0;n<i;n++){
    printf("friends of %s are %d\n",all_user[n].name,all_user[n].friend_count);
    printf("friends of %s:\n",all_user[n].name);
    for(int j=0;j<all_user[n].friend_count;j++){
        printf("%s\n",all_user[n].friends[j]->name);
    }
}
printf("\n");
float h_score=0;
float val=0;
int u=0;
for(int j=0;j<i;j++){
    val=calculatefriendshipStrength(&all_user[j]);
    printf("friendship strength of %s is %.3f\n",all_user[j].name,val);
    if(h_score<val){
        u=j;
        h_score=val;
    }
}
printf("The most social person is %s with score %.3f\n",all_user[u].name,h_score);
printf("\n");
for(int j=0;j<i;j++){
    generatefriendshipRecommendation(&all_user[j]);
}
    return 0; 
}
void addFriend(struct User *user1, struct User *user2) {
    if(check_friends(user1,user2)==-1){
    user1->friends[user1->friend_count] = user2;
    user2->friends[user2->friend_count] = user1;
    user1->friend_count++;
    user2->friend_count++;
    printf("%s and %s are now friends\n",user1->name,user2->name);
    return;
    }
    else if(check_friends(user1,user2)==0){
    printf("They are already friends\n");
    return;
    }
    else if(check_friends(user1,user2)==1){
    printf("No need to add, a human is always a friends of himself/herself\n");
    return ;
    } 
}
int check_friends(struct User *user1, struct User *user2) {
    if(user1->userID==user2->userID){ 
        return 1;
    }
    for(int i=0;i<user1->friend_count;i++){
        if(user1->friends[i]->userID==user2->userID){
            return 0;
        }
    }
    return -1;
}
float calculatefriendshipStrength(struct User*user1){
    float fc= 0.6;
    float aa=0.4;
    float age1=0;
    fc=fc*(float)(user1->friend_count);
    for(int j=0;j<(user1->friend_count);j++){
        age1=age1+(user1->friends[j]->age);
    }
    aa= aa*(age1/(float)(user1->friend_count));
    float total_weight= aa+fc;
    return total_weight;
}
void generatefriendshipRecommendation(struct User *user1){
    for(int i=0;i<user1->friend_count;i++){
        for(int j=0;j<user1->friends[i]->friend_count;j++){
           if(check_mutuals(user1,user1->friends[i]->friends[j])==-1){
             printf("Mutuals Recommendation for %s is %s\n",user1->name,user1->friends[i]->friends[j]->name);
           }
        }
    }
}
int check_mutuals(struct User *user1, struct User *user2){
    if(check(user1->userID,user2->userID)==0){
           return 0;
    }
    for(int i=0;i<user1->friend_count;i++){
        if(check(user1->friends[i]->userID,user2->userID)==0){
            return 0;
        }
    }
    return -1;
}
int check(char a[],char b[]){
  int count=1;
  for(int i=0;i<20;i++){
        if(a[i]!=b[i]){
            return -1;
        }
    }
    return 0;
}
int check1(char a[],char b[]){
  int count=1;
  for(int i=0;i<strlen(a);i++){
        if(a[i]!=b[i]){
            return -1;
        }
    }
    return 0;
}
