#include <stdio.h>
#include <stdlib.h>

typedef struct User{
    int  id ;
    char  Username[10];
    char  Pin[4] ;
    }User;

int main(){
    FILE *fp ;
    User s ;
    fp=fopen("/home/amine/Desktop/trial/lol.txt","ab");
        
        printf("Saisir Id de User"); 
        scanf("%d",&s.id);
        fprintf(fp,"%d\n",s.id);
        printf("Saisir Prenom de s");
        scanf("%s",s.Username);
        fprintf(fp,"%s\n",s.Username);
        printf("Saisir Prenom de s");
        scanf("%s",s.Pin);
        fprintf(fp,"%s\n",s.Pin);
        system("./Crypt.sh");
    
    fclose(fp);
}