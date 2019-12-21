#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
       char message[10][150],buffer[80], messagepass[20][20];
        int i=0,j=0,p=0;
        FILE *file_in;
        file_in=fopen("Data.txt", "r");
          while(fgets(buffer,80,file_in)){
              if(i%2==0){
                strcpy(message[j],buffer);
                j++;
                i++;
                continue;
              }
              if(i%2!=0){
                strcpy(messagepass[p],buffer);
                p++;
                i++;
                continue;
              }
              //strcpy(message[j],buffer);
              //strcpy(messagepass[j],buffer);
              //j++;
          } 
    fclose(file_in);
    for(int k=0;k<3;k++)
    {
      printf("%s",message[k]);
    }
    for(int k=0;k<3;k++)
    {
      printf("%s",messagepass[k]);
    }
}

    /*
         while(fscanf(fp,"%s %*s",x))
             {
                printf("%s",x);
             }
    fclose(fp);*/