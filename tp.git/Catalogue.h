
#if ! defined ( Catalogue_H )
#define Catalogue_H

#include "Trajet.h"
#include "Liste.h"

class Catalogue
{

public:
    void Ajouter (Trajet *Traj);

    void affiche(void);

    void recherche(const char *Vd, const char *Va);

    Liste* search(const char* vD, const char* vA);

    Catalogue ();

    virtual ~Catalogue ();

protected:

    Liste *l;

};


#endif