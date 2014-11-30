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
  * @file libertes.c
  *
  * Fichier d'en-t�te du type abstrait Libert�s
  *
  * */

#ifndef LIBERTES_H_INCLUDED
#define LIBERTES_H_INCLUDED

#include "position.h"

/**
  * @typedef Libert�s
  *
  * Libert�s est un pointeur sur ensemble_positions
  *
  * */

typedef ensemble_positions* Libertes;

#include "chaines.h"
#include "plateau.h"

/**
  * Cr�ation et intialisation d'un ensemble de libert�s
  *
  * @return L'ensemble de libert�s correctement allou�
  *
  * */

Libertes libertes_creer();

 /**
  * Destruction d'un ensemble de libert�s
  *
  * @param L'ensemble de libert�s � d�truire
  *
  * */

void libertes_detruire(Libertes liste);

/**
  * Teste si un ensemble de libert�s est vide
  *
  * @param L'ensemble � tester
  * @return 1 si l'ensemble est vide, 0 si elle ne l'est pas
  *
  * */

int libertes_vide(Libertes liste);

/**
  * Ajoute une libert� � l'ensemble
  *
  * @param La position � ajouter
  * @param L'ensemble auquel on veut ajouter une position
  *
  * */

void libertes_ajouter(Position position, Libertes liste);

/**
  * Teste si une position appartient � l'ensemble de libert�s
  *
  * @param La position � tester
  * @param L'ensemble � tester
  * @return 1 si la position appartient � l'ensemble, 0 sinon
  *
  * */

int libertes_appartient(Position position, Libertes liste);

/**
  * Se placer en t�te d'un ensemble de libert�s
  *
  * @param L'ensemble � traiter
  *
  * */

void libertes_tete(Libertes liste);

/**
  * Passer � l'�l�ment suivant d'un ensemble de libert�s
  *
  * @param L'ensemble � traiter
  * @return 1 s'il y'a bien un suivant, 0 sinon
  *
  * */

int libertes_suivant(Libertes liste);

/**
  * L'�l�ment courant d'un ensemble de libert�s
  *
  * @param L'ensemble � traiter
  * @return Un pointeur sur l'�l�ment courant de l'ensemble
  *
  * */

element_position* libertes_courant(Libertes liste);

/**
  * D�termine les libert�s d'une chaine sur le plateau
  *
  * @param Le plateau courant
  * @param La chaine � traiter
  * @return L'ensemble des libert�s de la chaine
  *
  * */

Libertes determine_liberte(Plateau plateau, Chaine chaine);

#endif
