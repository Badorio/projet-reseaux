#ifdef DATAH

#else


#define DATAH

struct SeanceLPBB { 
         int  Reference ;
	 char Film[40] ;
	 int  Places ;
         char Date[10] ;
		 char LieuTournage[10];
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
