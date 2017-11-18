#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include <windows.h>
#include<Math.h>
#include<String.h>
#define M 3
//n colonne m ligne 
void Automate (char  mot[],char finaux [2], char tr[][5] ,int n , int m ){
	char etat = tr[1][0];
	//printf("%c",etat);
    int i,j;
    int k=0;
    bool x ;    
    
while (k<sizeof(mot)) {
	for(j=1;j<m;j++){
	        i=1;
			    while(i<n && etat!=tr[j][i]){
			           	if(mot[k]==tr[0][i]){
						          if (etat==tr[j][0]){	      		
		                        		          if(tr[j][i] !='0'){	     etat = tr[j][i];  	 }
										}										
									}
									i++;
											}
											k++;
											x=false;
//non entiérement lue ou ... et on a pas trouvé de symétrie entre l'alphabet et le symbole lu 

	}
		}


               for(int p =0;p<sizeof(finaux);p++){
                     if(etat == finaux[p] ){	x=true;	}	
												 }	

                                    if(x==false ){    printf("Non reconnu ");}
                                         	else {	printf("Reconnu ");}
 }	

int main(){	
							char  transition [5][5];
							char mot[9];
							char finaux[2];
							FILE * fmot; //fichier pour les mot ;
							FILE * fp; // fichier pour la matrice de transition
							FILE * final; //fichier pour etats finaux 
							int choix ;  
							int c ,li;
							printf("j'ai prepare deux exemples d'automates ,le votre et le mien \n" );
							printf("si vous voulez changer d'exemples\n");
							printf("il suffit d'aller changer le contenue des fichier utilises\n");
							printf("press 1 to see first  example \n");
							printf("press 2 to see Teacher's example \n");
							printf("press 3 to see third example \n");
							scanf("%d",&choix);
							system("cls");
							switch (choix ){
								case 2 : {
									fp = fopen("data2.txt", "r");
									fmot =fopen("fmot2.txt","r");
									final = fopen("f2.txt","r");
									c=3;
									li=4;
									break;
								}
								case 1 : {
									fp = fopen("data.txt", "r");
									fmot = fopen("m.txt","r");
									final=fopen("f.txt","r");
									c=4;
									li=5;
									break;
								}
								case 3 : {
									fp = fopen("mat.txt","r");
									fmot = fopen("mott.txt","r");
									final=fopen("fino.txt","r");
									c=5;
									li=5;
									break;
								}
								default : printf("on a prevu juste 3 exemples exemples ");
								
							}
				
	if(fp!=NULL){
								
			for(int i=0;i<li;i++){
				for(int j=0;j<c;j++){
						fscanf(fp,"  %c    ",&transition[i][j]);
						
				}
			}
		}
		fclose(fp);
		if(final!=NULL){
			for(int u=0;u<sizeof(finaux);u++){
				fscanf(final," %c ",&finaux[u]);
			}
		}
		

		fclose(final);
		if(fmot!=NULL){
			int k;
			int y = sizeof(mot);
       //  printf("la taille entrante %d",y);
			for(k=0;k<y;k++){
				fscanf(fmot," %c ",&mot[k]);
			}
						}
						fclose(fmot);	
						printf("la matrice de transition : \n");			
		for(int i=0;i<li;i++){
				for(int j=0;j<c;j++){
						printf("%c ",transition[i][j]);		
			                    	}
				printf("\n");
			}
			

	printf("\n");
         printf("le mot :");
    for(int l=0;l<sizeof(mot);l++){
				printf(" %c",mot[l]);				
			}
			printf(" est ");
			Automate(mot,finaux,transition,c,li);
			printf("par  l'automate  ");
	return 0;

}
