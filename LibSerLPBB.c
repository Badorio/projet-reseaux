#include "LibSerLPBB.h"

void AProposServeurLPBB(char *Version,char *Nom1,char* Nom2)
{
 printf("Version : %s \n",Version ) ;
 printf("Nom1 : %s \n",Nom1 ) ;
 printf("Nom2 : %s \n",Nom2 ) ;
}

int RechercheLPBB(char * NomFichier, int Reference, struct SeanceLPBB *UnRecord)
{

	FILE * fp;
	struct SeanceLPBB tmp;

	fp = fopen(NomFichier, "rb");

	if (!fp)
	{
		printf("Aucune séance encodée");
		return 0;
	}
	else //fichier ouvert
	{
		fprintf(stderr,"Ouverture reussie \n") ;
		fread(&tmp,sizeof(struct SeanceLPBB) ,1 , fp);
		while(tmp.Reference!=Reference && !feof(fp))
		{
			fread(&tmp,sizeof(struct SeanceLPBB) ,1 , fp);
		}
		if(feof(fp))
		{
			printf("Cette reference n'existe pas");
			return 0;
		}		
		UnRecord->Reference=Reference;
		strcpy(UnRecord->Film,tmp.Film);
		UnRecord->Places=tmp.Places;
		strcpy(UnRecord->Date,tmp.Date);
		strcpy(UnRecord->LieuTournage,tmp.LieuTournage);
		fclose(fp);
		return 1;
	}
}

void AProposLPBB(char *Version,char *Nom1,char* Nom2)
{
 printf("Version : %s \n",Version ) ;
 printf("Nom1 : %s \n",Nom1 ) ;
 printf("Nom2 : %s \n",Nom2 ) ;
 
}

void DelNewLine(char *Chaine)
{
 Chaine[strlen(Chaine)-1] = 0 ;
}

char ReadChar()
{
 char Tampon[80] ;
 fgets(Tampon,sizeof Tampon,stdin ) ;
 return Tampon[0] ;
} 

void MonPrintf(char* tempo, int espace,int taille )
{
 int Count ;
 printf("%s",tempo) ; 
 Count = espace-taille ;
 while ( Count>0 )
 {
       printf(" ");
       Count-- ;
 }
}

void AfficheEnteteSeanceLPBB()
{
 char Tampon[80] ;
 sprintf(Tampon,"%s","Ref" ) ;MonPrintf(Tampon,4,strlen(Tampon)) ;
 sprintf(Tampon,"%s","Film") ;    MonPrintf(Tampon,50,strlen(Tampon)) ;
 sprintf(Tampon,"%s","Places") ; MonPrintf(Tampon,10,strlen(Tampon)) ;
 sprintf(Tampon,"%s","Date") ; MonPrintf(Tampon,20,strlen(Tampon)) ;
 sprintf(Tampon,"%s","Lieu de tournage") ; MonPrintf(Tampon,30,strlen(Tampon)) ;
 
 printf("\n") ;
}

void AfficheSeanceLPBB(struct SeanceLPBB   *UnRecord)
{
 char Tampon[80] ;
 sprintf(Tampon,"%d",UnRecord->Reference ) ;  MonPrintf(Tampon,4,strlen(Tampon)) ;
 sprintf(Tampon,"%s",UnRecord->Film) ;    MonPrintf(Tampon,50,strlen(Tampon)) ;
 sprintf(Tampon,"%d",UnRecord->Places) ; MonPrintf(Tampon,10,strlen(Tampon)) ; 
 sprintf(Tampon,"%s",UnRecord->Date) ; MonPrintf(Tampon,20,strlen(Tampon)) ; 
 sprintf(Tampon,"%s",UnRecord->LieuTournage) ; MonPrintf(Tampon,30,strlen(Tampon)) ;
 printf("\n") ;
}

void SaiSieSeanceLPBB(int Reference, struct SeanceLPBB *UnRecord )
{
 char Tampon[80] ;

 printf("Reference :%d \n",Reference) ;
 UnRecord->Reference = Reference ; 
 printf("Saisie Film :") ;
 fgets(UnRecord->Film,sizeof UnRecord->Film,stdin ) ;
 printf("Saisie Places :") ;
 fgets(Tampon,sizeof Tampon,stdin ) ;
 UnRecord -> Places = atoi(Tampon) ;
 printf("Saisie Date :") ;
 fgets(UnRecord->Date,sizeof UnRecord->Date,stdin ) ;
 printf("Saisie LieuTournage :") ;
 fgets(UnRecord->LieuTournage,sizeof UnRecord->LieuTournage,stdin ) ;
 
 DelNewLine(UnRecord->Film);
 DelNewLine(UnRecord->LieuTournage) ;
 DelNewLine(UnRecord->Date);
 AfficheEnteteSeanceLPBB() ;
 AfficheSeanceLPBB(UnRecord) ;
 printf("-----------------------\n") ;
 return ;
}

int NombreSeancesLPBB(char *NomFichier)
{
 FILE *sortie ;
 sortie = fopen(NomFichier,"r") ; /* Si le fichier existe, on le cree sinon on ajoute */
 if ( sortie == NULL )
    {
     fprintf(stderr,"Pas de fichier\n") ;
     return 0 ;
    }
 else
    fprintf(stderr,"Ouverture reussie \n") ;
 fseek(sortie, 0, SEEK_END ) ;
 return (ftell(sortie)/ sizeof(struct SeanceLPBB )) ;
}

void CreationAjoutSeanceLPBB(char *NomFichier,struct SeanceLPBB *UnRecord )
{
 FILE *sortie ;
 char Redo ;
 int nbr ;

 sortie = fopen(NomFichier,"a") ; /* Si le fichier existe, on le cree sinon on ajoute */
 if ( sortie == NULL )
    {
     fprintf(stderr,"Echec Ouverture\n") ;
     exit(0) ;
    }
 else
    fprintf(stderr,"Ouverture reussie \n") ;

 
  printf("Position actuelle dans le fichier %ld\n",ftell(sortie)) ;
  nbr = fwrite(UnRecord,sizeof(struct SeanceLPBB ),1,sortie) ;
  fflush(sortie) ;
 fclose(sortie) ;
}



void AfficheFacture(struct FactureLPBB *UneFacture)
{
 char Tampon[80] ;
 sprintf(Tampon,"%d",UneFacture->NumeroFacturation ) ; MonPrintf(Tampon,4,strlen(Tampon)) ;
 sprintf(Tampon,"%s",UneFacture->NomClient) ; MonPrintf(Tampon,60,strlen(Tampon)) ;
 sprintf(Tampon,"%d",UneFacture->Places ) ; MonPrintf(Tampon,4,strlen(Tampon)) ;
 sprintf(Tampon,"%d",UneFacture->Reference) ; MonPrintf(Tampon,4,strlen(Tampon)) ;
 sprintf(Tampon,"%d",UneFacture->DateFacturation ) ; MonPrintf(Tampon,8,strlen(Tampon)) ;
 
 printf("\n") ;
}

void ListingSeancesLPBB(char *NomFichier)
{
 struct SeanceLPBB  UnRecord ;
 FILE *sortie ;
 char Tampon[80] ;
 int  Numero ;
 int  nbr ;

 sortie = fopen(NomFichier,"r") ; /* Si le fichier existe, on le cree sinon on ajoute */
 if ( sortie == NULL )
    {
     fprintf(stderr,"Echec Ouverture\n") ;
     exit(0) ;
    }
 else
    fprintf(stderr,"Ouverture reussie \n") ;

 AfficheEnteteSeanceLPBB() ;
 nbr = fread(&UnRecord,sizeof(UnRecord),1,sortie) ;
 
 while ( !feof(sortie) )
 {
  fprintf(stderr,"Record lu %d et Position actuelle dans le fichier %ld\n",nbr,ftell(sortie)) ;
  AfficheSeanceLPBB( &UnRecord) ;
  nbr = fread(&UnRecord,sizeof(UnRecord),1,sortie) ;
 }
 fclose(sortie) ;
}

void ListingFacturesLPBB(char *NomFichier)
{
 struct FactureLPBB UneFacture ;
 FILE *sortie ;
 char Tampon[80] ;
 int  Numero ;
 int  nbr ;

 sortie = fopen(NomFichier,"r") ; /* Si le fichier existe, on le cree sinon on ajoute */
 if ( sortie == NULL )
    {
     fprintf(stderr,"Echec Ouverture\n") ;
     exit(0) ;
    }
 else
    fprintf(stderr,"Ouverture reussie \n") ;

 
 nbr = fread(&UneFacture,sizeof(struct FactureLPBB),1,sortie) ;
 
 while ( !feof(sortie) )
 {
  fprintf(stderr,"Record lu %d et Position actuelle dans le fichier %ld\n",nbr,ftell(sortie)) ;
  AfficheFacture( &UneFacture) ;
  nbr = fread(&UneFacture,sizeof(struct FactureLPBB ),1,sortie) ;
 }
 fclose(sortie) ;
}
