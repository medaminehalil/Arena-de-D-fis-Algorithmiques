#include<stdio.h>
#include<string.h>
int defi_mastermind(){
    char sec[7] = "1234567";
    printf("\n=== Defi mastermind ===\n");
    printf("Deviner la sequence secrete (7 chiffres). 10 essais maximum.\n");
    int k=0;
    int fini =1;
    while(k<10&&fini==1){
        char esai[7];
        printf("\ndonner le esai : ");
       
            scanf("%s",esai);
            if(strlen(esai) != 7) {
            printf(" Vous devez entrer exactement 8 caracteres.\n");}
        else{
        int mal=0;
        int bon=0;
        for(int i=0;i<7;i++){
            for(int j=0;j<7;j++){
                if(esai[i]==sec[j]&&i==j){bon++;}
                else if(esai[i]==sec[j]&&i!=j){mal++;}
            }
        }
        printf("\n nombre de chiffres bien places = %i et nombre de chiffres mal place = %i \n",bon,mal);
        k++;
        if(bon==6){
            printf("good job");
            return k;}
        else if(k==10&&bon<6){return -1;}
    }
        
        
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    }

}