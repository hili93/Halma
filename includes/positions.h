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
  * @file positions.c
  *
  * Fichier d'en-t�te du type abstrait Positions
  *
  * */

#ifndef POSITIONS_H_INCLUDED
#define POSITIONS_H_INCLUDED

#include "position.h"

/**
  * @typedef Positions
  *
  * Positions est un pointeur sur ensemble_positions
  *
  * */

typedef ensemble_positions* Positions;

/**
  * Cr�ation et intialisation d'une liste de positions
  *
  * @return La liste correctement allou�e
  *
  * */

Positions positions_creer();

/**
  * Destruction d'une liste de positions
  *
  * @param La liste � d�truire
  *
  * */

void positions_detruire(Positions liste);

/**
  * Teste si une liste de positions est vide
  *
  * @param La liste � tester
  * @return 1 si la liste est vide, 0 si elle ne l'est pas
  *
  * */

int positions_vide(Positions liste);

/**
  * Ajoute une chaine � une liste de positions
  *
  * @param La position � ajouter
  * @param La liste � laquelle on veut ajouter une chaine
  *
  * */

void positions_ajouter(Position position, Positions liste);

/**
  * Teste si une position appartient � une liste de positions
  *
  * @param La position � tester
  * @param La liste � tester
  * @return 1 si la position appartient � la liste, 0 sinon
  *
  * */

int positions_appartient(Position position, Positions liste);

/**
  * Se placer en t�te d'une liste de positions
  *
  * @param La liste � traiter
  *
  * */

void positions_tete(Positions liste);

/**
  * Passer � l'�l�ment suivant d'une liste de positions
  *
  * @param La liste � traiter
  * @return 1 s'il y'a bien un suivant, 0 sinon
  *
  * */

int positions_suivant(Positions liste);

/**
  * L'�l�ment courant d'une liste de positions
  *
  * @param La liste � traiter
  * @return Un pointeur sur l'�l�ment courant de la liste
  *
  * */

element_position* positions_courant(Positions liste);

#endif
