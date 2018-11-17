/******************************************
  Loic Peters - Benjamin Belluz
  2017 Basé sur Fichiers
*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "data.h"
#include "LibSerLPBB.h"

int main()
{
 char Choix ;
 char Tampon[80] ;
 int res ;
 struct SeanceLPBB UnRecord ;
 int Numero ;
 while(1)
 {
  printf("----------------------\n") ;
  printf("1) Ajout              \n") ;
  printf("2) Seances            \n") ;  
  printf("3) Recherche          \n") ;   
  printf("4) Achat              \n") ;  
  printf("5) Factures           \n") ;
  printf("6) A propos           \n") ;
  printf("7) exit               \n") ; 
  printf("----------------------\n") ; 
  Choix=ReadChar() ;
  switch(Choix)
  {
   case '1': 
             {
              struct SeanceLPBB  UnRecord ;
 	     FILE *sortie ;
             char Redo ;
		
             Redo='y' ;
 	    while ( Redo=='Y' || Redo=='y')
 	    { 
             int Nombre ;
             Nombre= NombreSeancesLPBB("SeancesLPBB") ;
  	     SaiSieSeanceLPBB(Nombre+1, &UnRecord ) ;
  	     CreationAjoutSeanceLPBB("SeancesLPBB",&UnRecord) ; 
  	     printf("Encoder un autre (Y/N) ?)") ;
  	     Redo=ReadChar() ;
 	   }
 
	     break ;	
             }
   case '2': ListingSeancesLPBB("SeancesLPBB") ;
             break ;
   case '3':   
   			printf("Saisie Reference :") ;
			fgets(Tampon,sizeof Tampon,stdin ) ;
			Numero= atoi(Tampon) ;
			if(RechercheLPBB("SeancesLPBB",Numero,&UnRecord)==1)
			{
				AfficheEnteteSeanceLPBB();
				AfficheSeanceLPBB(&UnRecord);
			}
             break ;
   case '5': ListingFacturesLPBB("FactureLPBB") ;
	     break ;
   case '6': AProposLPBB("V 1","Peters Loïc","Belluz Benjamin") ;
             break ;
   
	
   case '7': exit(0) ; 
  }
 }
}
