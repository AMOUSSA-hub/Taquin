#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
int main(int argc, char * argv[]){
		int posx=150,posy=100,i,j=0;
		int l,h,choix;
		char *image_selectionnee[16]={("aj1_grande.png"),("Kangoo.jpg"),("Vegeta.jpg")};
		scanf("%d",&choix);
		if (choix == 1){ 
		l=650;
		h=366;//Jordan
		}else if(choix == 2){
		l=570;
		h=384;//kangoo
		}else if(choix == 3){
			l=480;
			h=270;//Vegeta
		}

		int taille,taille_lignes,num_case=0;
		scanf("%d %d",&taille,&taille_lignes);
		int tab[taille*taille_lignes-1][4]; 
	  InitialiserGraphique();
		CreerFenetre(100,100,1000,1000);
		for(i=0;(i+(h%taille))<h;i+=(h/taille) ){
      for(j=0;(j+(l%taille_lignes))<l;j+=(l/taille_lignes)){
        ChargerImage(image_selectionnee[choix-1],posx,posy,j,i,(l/taille_lignes),(h/taille));
				printf("posx=%d , posy=%d , j=%d , i=%d , l=%d , h=%d\n",posx,posy,j,i,(l/taille_lignes),(h/taille));
				tab[num_case][0]=num_case;
				tab[num_case][1]=posx;
				tab[num_case][2]=posy;
				tab[num_case][3]=l/taille_lignes;
				tab[num_case][4]=h/taille;
				
				posx+=((l/taille_lignes)+5);
				num_case++;
    
			} 
      posy+=((h/taille)+5);
      j=0;
			posx=150;
    }

		ChoisirEcran(10);
    EffacerEcran(CouleurParNom("white"));
		CopierZone(10,0,0,0,l/taille_lignes,h/taille,150,100);
		ChoisirEcran(0);

		
		
int recherche,case_cliquee=0,keep_x,keep_y,;
int case_inconnu[1];
 keep_x,keep_y;
do{
while(!SourisCliquee());
	{
		if(_X>=150 && _X<= 150+l && _Y>= 100 && _Y <= 100+h){
			/*haut[0]=tab[0][1];
			haut[1]=tab[0][2]-(h/taille);
			bas[0]=tab[0][1];
			bas[1]=tab[0][2]+(h/taille);
			gauche[0]=tab[0][1]-(l/taille_lignes);
			gauche[1]=tab[0][2];
			droite[0]=tab[0][1]+(l/taille_lignes);
			droite[1]=tab[0][2];*/
			
			/*case du haut*/
			if(_X>=tab[0][1] && _X<=tab[0][1]+(l/taille_lignes) && _Y>=tab[0][2]-(h/taille)-5 && _Y <=tab[0][2]-5){
		case_inconnu[0]=tab[0][1];
		case_inconnu[1]=tab[0][2]-(h/taille)-5;
printf("%d  %d \n",case_inconnu[0],case_inconnu[1]);
}

			/*case de droite*/
			if(_X>=tab[0][1]+(l/taille_lignes)+5 && _X<=tab[0][1]+(2*(l/taille_lignes))+5 && _Y>=tab[0][2] && _Y <=tab[0][2]+(h/taille)){
		case_inconnu[0]=tab[0][1]+(l/taille_lignes)+5;
		case_inconnu[1]=tab[0][2];
printf("%d  %d \n",case_inconnu[0],case_inconnu[1]);
}

			/*case du bas*/
			if(_X>=tab[0][1] && _X<=tab[0][1]+(l/taille_lignes) && _Y >=tab[0][2]+(h/taille)+5  && _Y<= tab[0][2]+(2*(h/taille))+5){
		case_inconnu[0]=tab[0][1];
		case_inconnu[1]=tab[0][2]+(h/taille)+5;
printf("%d  %d \n",case_inconnu[0],case_inconnu[1]);
}
			/*case du gauche*/
			if(_X >=tab[0][1]-(l/taille_lignes)-5 && _X<=tab[0][1]-5 && _Y>=tab[0][2] && _Y <=tab[0][2]+(h/taille)){
		case_inconnu[0]=tab[0][1]-(l/taille_lignes)-5;
		case_inconnu[1]=tab[0][2];
printf("%d  %d \n",case_inconnu[0],case_inconnu[1]);
}
					for(recherche=0;recherche <= num_case;recherche++){
						
						if(tab[recherche][1] == case_inconnu[0] && tab[recherche][2] == case_inconnu[1]){
						case_cliquee = recherche;
printf("%d\n",tab[case_cliquee][0]);
}
																																		  
																																			}
printf("%d   %d\n",tab[0][1],tab[0][2]);



	CopierZone(0,1,0,0,1000,1000,0,0);
	CopierZone(0,0,tab[0][1],tab[0][2],l/taille_lignes,h/taille,tab[case_cliquee][1],tab[case_cliquee][2]);
	CopierZone(1,0,tab[case_cliquee][1],tab[case_cliquee][2],l/taille_lignes,h/taille,tab[0][1],tab[0][2]);

keep_x= tab[0][1];
keep_y= tab[0][2];
tab[0][1]=tab[case_cliquee][1];
tab[0][2]=tab[case_cliquee][2];
tab[case_cliquee][1]=keep_x;
tab[case_cliquee][2]=keep_y;


printf("%d   %d\n",tab[case_cliquee][1],tab[case_cliquee][2]);
printf("%d   %d\n",tab[0][1],tab[0][2]);

			}
}
}while(1);
/*		
if(Touche() == 0XFF51 ){
	int keep_x,keep_y;
	posx=150;
	CopierZone(0,1,0,0,1000,1000,0,0);
	CopierZone(0,0,tab[0][1],tab[0][2],l/taille_lignes,h/taille,tab[1][1],tab[1][2]);
	CopierZone(1,0,tab[1][1],tab[1][2],l/taille_lignes,h/taille,tab[0][1],tab[0][2]);
keep_x= tab[0][1];
keep_y= tab[0][2];
tab[0][1]=tab[1][1];
tab[0][2]=tab[1][2];
tab[1][1]=keep_x;
tab[1][2]=keep_y;

}
*/
/*
int x ;
	for(x=0; x <=num_case-1;x++){
			printf("case numéro: %d  posx=%d posy=%d i=%d l= %d\n",tab[x][0],tab[x][1],tab[x][2],tab[x][3],tab[x][4]);
				
    
		
		}*/
		
		
Touche();
FermerGraphique();
return EXIT_SUCCESS;

}
				/*		
up=0XFF52
down=0XFF54
right=0XFF53
left=0XFF51
*/



