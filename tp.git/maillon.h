#if ! defined ( Maillon_H )
#define Maillon_H

#include "Trajet.h"


class Maillon
{
    friend class Liste;

private:

    void Ajouter(Trajet *Traj);

    Maillon (Trajet *Traj) {T = Traj, suivant = NULL ;}

    Trajet *T;
    Maillon * suivant;
};

#endif

