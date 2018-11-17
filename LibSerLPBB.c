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
