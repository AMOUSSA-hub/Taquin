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

		int taille,taille_lignes,num_case=0,testposx,testposy;
		scanf("%d %d",&taille,&taille_lignes);
		int tab[taille*taille_lignes-1][4]; 
	  InitialiserGraphique();
		CreerFenetre(600,600,1000,1000);
		for(i=0;(i+(h%taille))<h;i+=(h/taille)){
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


if(Touche() == 0XFF51 ){
	posx=150;
	CopierZone(0,1,0,0,1000,1000,0,0);
	CopierZone(0,0,tab[0][1],tab[0][2],l/taille_lignes,h/taille,tab[1][1],tab[1][2]);
	CopierZone(1,0,tab[1][1],tab[1][2],l/taille_lignes,h/taille,tab[0][1],tab[0][2]);


}

int x ;
	for(x=0; x <=num_case;x++){
			printf("case numéro: %d  posx=%d posy=%d i=%d l= %d\n",tab[x][0],tab[x][1],tab[x][2],tab[x][3],tab[x][4]);
				
    
		
		}
		
		
		Touche();
FermerGraphique();
return EXIT_SUCCESS;

				/*		
up=0XFF52
down=0XFF54
right=0XFF53
left=0XFF51
*/
}



