#include<stdio.h>
#include<string.h>
int main(){
    char sec[7]="";
    printf("##deviner un sequence secrete de nombre en minimun 10 esais##");
    int i=0;
    int fini =1;
    while(i<10&&fini==1){
        char esai[7];
        printf("\ndonner le esai :");
        scanf("%s",esai);
        int mal=0;
        int bon=0;
        for(int i=0;i<7;i++){
            for(int j=0;j<7;j++){
                if(esai[i]==sec[j]&&i==j){bon++;}
                else if(esai[i]==sec[j]&&i!=j){mal++;}
            }
        }
        printf("\nnombre de chiffres bien places = %i et nombre de chiffres mal place = %i",bon,mal);
        if(bon==7){return i;}
        
        
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    }

}