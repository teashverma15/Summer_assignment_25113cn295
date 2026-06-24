//Ques 93:Write a program to Check string rotation. 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int rotation(const char *str1,const char *str2)
{
   int len1=strlen(str1);
   int len2=strlen(str2);

   if (len1!=len2){
    return 0;
   }

   char *temp=(char *)malloc(sizeof(char)*(len1*2 +1));
   if(temp==NULL){
    printf("Memory allocation failed");
    return 0;
   }

   strcpy(temp,str1);
   strcat(temp,str1);
    
   char *match=strstr(temp,str2);
   free(temp);
   return (match!=NULL);

}

int  main()
{
    char str1[]="ABCD";
    char str2[]="BCDA";
    if(rotation(str1,str2)){
        printf("%s is a rotation of %s \n",str2,str1);
    }
    else{
         printf("%s is not a rotation of %s \n",str2,str1);
    }
    return 0;
}