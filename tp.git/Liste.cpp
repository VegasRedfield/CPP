#include <iostream>
using namespace std;
#include <cstring>

#include "Liste.h"

       Liste::Liste(void)
       {
              debut = nullptr;
              fin = nullptr;
              nb_maillons = 0;
       }

     int Liste::ajouter_fin(Trajet *traj)
     {
         Maillon * nouveau = new Maillon(traj);

         if (nouveau == NULL)
               return 0;

         if(nb_maillons==0)
         {
               debut = nouveau;
               fin = debut;
               debut -> suivant = fin;
               fin -> suivant = debut;
         }else
         {
               fin->suivant = nouveau;
               fin = nouveau;
               fin -> suivant = debut;
          }
          ++nb_maillons;
          return 1;
     }

       void Liste::afficheCata(void)
       {
        Maillon * curr = debut;

          for(int i = 0; i<nb_maillons ; i++)
          {
            cout << "- ";
            curr->T->Afficher();
            cout << endl;
            curr = curr->suivant;
          }
       }

       void Liste::afficheComp(void)
       {
        Maillon * curr = debut;

          for(int i = 0; i<nb_maillons ; i++)
          {
               curr->T->Afficher();
               if(curr != fin && curr->suivant != fin)
                    cout << ", d'un ";
               else if(curr -> suivant == fin)
                    cout << " et d'un ";

            curr = curr->suivant;
          }
       }

       Liste* Liste::search(const char *Vd, const char *Va)
       {
          Liste *liste = new Liste();
          Maillon * curr = debut;

          for(int i = 0; i<nb_maillons ; i++)
          {
            if(curr->T->getVd() == Vd && curr->T->getVa() == Va)
               liste->ajouter_fin(curr->T);

            curr = curr->suivant; 
          }
          return liste;
       }

       Liste*  Liste::searchComp(const char *Vd, const char *Va)
       {
         Liste* liste = new Liste();
         //char * * anciennesVilles = new char * [1000]; 
         //char * pointeur = anciennesVilles[0]; 
          
        /*  Maillon * curr = debut;
          char * villeDep = Vd; 
          bool arrive = false; 
          bool boucle = false; 

          while(!arrive && !boucle)
          {
            if(curr->T->getVd() == villeDep)
            {
               liste->ajouter_fin(curr->T);
               villeDep = curr->T->getVd(); 
                if(curr->T->getVa() == Va)
                arrive = true; 
                if(curr->T->getVa() == Vd)
                boucle = true; 
                
            }

            curr = curr->suivant; 
            }  */          
         return liste;  
         }

       bool Liste::searchVille(const char *Va)
        { 
          Maillon * curr = debut;

          for(int i = 0; i<nb_maillons ; i++)
          {
            if(curr->T->getVd() == Va || curr->T->getVa() == Va)
               return true;

            curr = curr->suivant; 
          }
          return false;
       }

       bool Liste::methodeRecursive(Liste * listeTrajet, const char * villeCurr, const char * Dest)
    {
        Maillon * curr = debut;

          for(int i = 0; i<nb_maillons ; i++)
          {
            if(curr->T->getVd() == villeCurr &&  !listeTrajet->searchVille(curr->T->getVa()))
            {
                        
            listeTrajet->ajouter_fin(curr->T); 
            
               if(curr->T->getVa() == Dest)
               {
                return true; 
               }
            methodeRecursive(listeTrajet, curr->T->getVa(), Dest); 
             
            }
            curr = curr->suivant; 
         }
    return false; 
    }