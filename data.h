#ifdef DATAH

#else


#define DATAH

struct SeanceLPBB { 
         int  Reference ;
	 char Film[40] ;
	 int  Places ;
         char Date[12] ;
		 char LieuTournage[20];
	} ;

struct FactureLPBB
       {
         int NumeroFacturation ;
         char NomClient[40] ;
	 int DateFacturation ;
         int Places ;
	 int Reference ;
	} ;  	
#endif
