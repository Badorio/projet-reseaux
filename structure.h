
#include "data.h"

enum TypeRequete {
       Question = 1 ,
       Achat  = 2 ,
       Livraison = 3 ,
       OK = 4,
       Fail = 5
     } ;

struct Requete
{
  enum TypeRequete Type ;
  int Numero;
  int NumeroFacture;
  struct SeanceLPBB UnRecord;
  char Client[80]; 
} ; 
