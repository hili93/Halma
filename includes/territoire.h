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
  * @file territoire.c
  *
  * Fichier d'en-t�te du type abstrait Territoire
  *
  * */

#ifndef TERRITOIRE_H_INCLUDED
#define TERRITOIRE_H_INCLUDED

#include "couleur.h"

/**
  * @typedef Territoire
  *
  * Territoire est un pointeur sur ensemble_colore
  *
  * */

typedef ensemble_colore* Territoire;

#include "plateau.h"

/**
  * Cr�ation et intialisation d'un territoire
  *
  * @param La couleur du territoire
  * @return Le territoire correctement allou�
  *
  * */

Territoire territoire_creer(Couleur couleur);

/**
  * Destruction d'un territoire
  *
  * @param Le territoire � d�truire
  *
  * */

void territoire_detruire(Territoire liste);

/**
  * Teste si un territoire est vide
  *
  * @param Le territoire � tester
  * @return 1 si le territoire est vide, 0 s'il ne l'est pas
  *
  * */

int territoire_vide(Territoire liste);

/**
  * Ajoute une position � un territoire
  *
  * @param La position � ajouter
  * @param Le territoire auquel on veut ajouter une position
  *
  * */

void territoire_ajouter(Position position, Territoire liste);

/**
  * Teste si une position appartient � un territoire
  *
  * @param La position � tester
  * @param Le territoire � tester
  * @return 1 si la position appartient au territoire, 0 sinon
  *
  * */

int territoire_appartient(Position position, Territoire liste);

/**
  * Teste si deux territoires sont identiques
  *
  * @param Le premier territoire � tester
  * @param Le second territoire � tester
  * @return 1 si les territoires sont identiques, 0 sinon
  *
  * */

int territoire_est_identique(Territoire territoire1, Territoire territoire2);

/**
  * Se placer en t�te d'un territoire
  *
  * @param Le territoire � traiter
  *
  * */

void territoire_tete(Territoire liste);

/**
  * Passer � l'�l�ment suivant d'un territoire
  *
  * @param Le territoire � traiter
  * @return 1 s'il y'a bien un suivant, 0 sinon
  *
  * */

int territoire_suivant(Territoire liste);

/**
  * L'�l�ment courant d'un territoire
  *
  * @param Le territoire � traiter
  * @return Un pointeur sur l'�l�ment courant du territoire
  *
  * */

element_position* territoire_courant(Territoire liste);

/**
  * D�termine le territoire auquel appartient une case vide du plateau
  *
  * @param Le plateau courant
  * @param La position de la case
  * @return Le territoire auquel appartient la position
  *
  * */

Territoire determine_territoire(Plateau plateau, Position pos);

#endif
