/**
  * ENSICAEN
  * 6, boulevard du Mar�chal Juin
  * 14050 Caen Cedex
  *
  * This file is owned by ENSICAEN students
  * No portion of this document may be reproduced, copied or revised without written permission of the authors
  *
  * */

  /**
  * @file chaine.c
  *
  * Fichier d'en-t�te du type abstrait Chaine
  *
  * */

#ifndef CHAINE_H_INCLUDED
#define CHAINE_H_INCLUDED

#include "couleur.h"

/**
  * @typedef Chaine
  *
  * Chaine est un pointeur sur ensemble_colore
  *
  * */

typedef ensemble_colore* Chaine;

/**
  * Cr�ation et intialisation d'une chaine
  *
  * @param La couleur de la chaine
  * @return La chaine correctement allou�e
  *
  * */

Chaine chaine_creer(Couleur couleur);

/**
  * Destruction d'une chaine
  *
  * @param La chaine � d�truire
  *
  * */

void chaine_detruire(Chaine liste);

/**
  * Teste si une chaine est vide
  *
  * @param La chaine � tester
  * @return 1 si la chaine est vide, 0 si elle ne l'est pas
  *
  * */

int chaine_vide(Chaine liste);

/**
  * Ajoute une position � une chaine
  *
  * @param La position � ajouter
  * @param La chaine � laquelle on veut ajouter une position
  *
  * */

void chaine_ajouter(Position position, Chaine liste);

/**
  * Teste si une position appartient � une chaine
  *
  * @param La position � tester
  * @param La chaine � tester
  * @return 1 si la position appartient � la chaine, 0 sinon
  *
  * */

int chaine_appartient(Position position, Chaine liste);

/**
  * Teste si deux chaines sont identiques
  *
  * @param La premi�re chaine � tester
  * @param La seconde chaine � tester
  * @return 1 si les chaines sont identiques, 0 sinon
  *
  * */

int chaine_est_identique(Chaine chaine1, Chaine chaine2);

/**
  * Se placer en t�te d'une chaine
  *
  * @param La chaine � traiter
  *
  * */

void chaine_tete(Chaine liste);

/**
  * Passer � l'�l�ment suivant d'une chaine
  *
  * @param La chaine � traiter
  * @return 1 s'il y'a bien un suivant, 0 sinon
  *
  * */

int chaine_suivant(Chaine liste);

/**
  * L'�l�ment courant d'une chaine
  *
  * @param La chaine � traiter
  * @return Un pointeur sur l'�l�ment courant de la chaine
  *
  * */

element_position* chaine_courant(Chaine liste);

#endif
