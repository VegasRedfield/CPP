#if ! defined ( Liste_H )
#define Liste_H

#include "Trajet.h"
#include "maillon.h"


class Liste
{
    
public :

      Liste(void);

      inline ~Liste(void) {delete[] debut; delete[] fin;}

      int ajouter_fin(Trajet *traj);

      inline int taille(void) const { return nb_maillons;}

      void afficheCata(void);

      void afficheComp(void);

      Liste* search(const char *Vd, const char *Va);

      Liste* searchComp(const char *Vd, const char *Va);

      bool searchVille(const char* Va);

      bool methodeRecursive(Liste* listeTrajet, const char* villeCurr, const char* Dest);



  protected :

      Maillon * debut;

      Maillon * fin;

      int nb_maillons;
};
#endif