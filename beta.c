#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
int main(int argc, char * argv[]){
		int posx=150,posy=100,i,j=0;
		int l,h,choix;
		char *image_selectionnee[16]={("aj1.png"),("Kangoo.jpg"),("Vegeta.jpg")};
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
    CreerFenetre(600,600,1000,1000);
		for(i=0;i<h;i+=(h/taille)){
      for(j=0;j<l;j+=(l/taille_lignes)){
        ChargerImage(image_selectionnee[choix-1],posx,posy,j,i,(l/taille_lignes),(h/taille));
				printf("posx=%d , posy=%d , j=%d , i=%d , l=%d , h=%d\n",posx,posy,j,i,(l/taille_lignes),(h/taille));
				posx+=((l/taille_lignes)+5);
      }
      posy+=((h/taille)+5);
      j=0;
			posx=150;
    }
    Touche();
    FermerGraphique();

return EXIT_SUCCESS;
}




