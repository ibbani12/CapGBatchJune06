#include <stdio.h>
#include <stdlib.h>
#include<string.h> 

typedef struct
{
   char name[14];
   char age;
   char gender;
} normal_member;

typedef struct
{
   char age;
   char gender;
   char name[];
} FAM_member;

int main()
{
    normal_member normal_member;
    FAM_member *member = (FAM_member *) malloc( sizeof(*member) + (sizeof(char) * strlen("David")) );
    
    member->age    = 28;
    member->gender = 'M';
    strcpy( member->name, "David" );
    
    normal_member.age    = 28;
    normal_member.gender = 'M';
    strcpy( normal_member.name, "David" );
    
    printf( "Normal Member's Age    : %d\n"
            "Normal Member's Gender : %c\n"
            "Normal Member's Name   : %s\n\n", 
            normal_member.age,
            normal_member.gender,
            normal_member.name
          ); 
    
    printf( "FAM Member's Age    : %d\n"
            "FAM Member's Gender : %c\n"
            "FAM Member's Name   : %s\n\n", 
            member->age,
            member->gender,
            member->name
          );
          
    printf("Size of normal_member struct = %ld\n", sizeof(normal_member));
    printf("Size of FAM_member struct = %ld\n", sizeof(( sizeof(*member) + (sizeof(char) * strlen("David")) )));
    
    free(member);
    return 0;
}