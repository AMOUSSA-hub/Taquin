#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
int main(int argc, char * argv[]){
		int posx=150,posy=100,i,j=0;
		int l,h,choix;
		scanf("%d",&choix);
		if (choix == 1){
		l=300;
		h=169;//Jordan
		}else if(choix == 2){
		l=570;
		h=384;//kangoo
		}else if(choix == 3){
			l=480;
			h=270;//Vegeta
		}
		int taille,taille_lignes;
		scanf("%d %d",&taille,&taille_lignes);
	  InitialiserGraphique();
    CreerFenetre(600,600,700,700);
		for(i=0;i<h;i+=(h/taille)){
      for(j=0;j<l;j+=(l/taille_lignes)){
        ChargerImage("Vegeta.jpg",posx,posy,j,i,(l/taille_lignes),(h/taille));
				printf("posx=%d , posy=%d , j=%d , i=%d , l=%d , h=%d\n",posx,posy,j,i,(l/taille_lignes),(h/taille));
				posx+=((l/taille_lignes)+5);
      }
      posy+=((h/taille)+5);
      j=0;
			posx=150;
    }
		/*
		for(i=0;i<h;i+=(h/taille)){
      for(j=0;j<l;j+=(l/taille)){
        ChargerImage("Kangoo.jpg",posx,posy,j,i,(l/taille),(h/taille));
        printf("posx=%d , posy=%d , j=%d , i=%d\n",posx,posy,j,i);
        posx+=((l/taille)+5);
      }
      posy+=((h/taille)+5);
      j=0;
      posx=150;
    }*/
		/*
		ChargerImage("Vegeta.jpg",posx,posy,0,0,160,90);
		ChargerImage("Vegeta.jpg",posx+=165,posy,160,0,160,90);
		ChargerImage("Vegeta.jpg",posx+=165,posy,320,0,160,90);

		ChargerImage("Vegeta.jpg",posx=150,posy+=95 ,0,90 ,160,90);
		ChargerImage("Vegeta.jpg",posx+=165,posy ,160 ,90 ,160,90);
		ChargerImage("Vegeta.jpg",posx+=165,posy ,320 ,90 ,160,90);

		ChargerImage("Vegeta.jpg",posx=150,posy+=95 ,0,180 ,160,90);
    ChargerImage("Vegeta.jpg",posx+=165,posy ,160 ,180 ,160,90);
    ChargerImage("Vegeta.jpg",posx+=165,posy ,320 ,180 ,160,90);
		*/

    Touche();
    FermerGraphique();

return EXIT_SUCCESS;
}




