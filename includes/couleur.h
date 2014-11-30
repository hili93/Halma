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
  * @file couleur.c
  *
  * Fichier d'en-t�te du type abstrait Couleur
  *
  * */

#ifndef COULEUR_H_INCLUDED
#define COULEUR_H_INCLUDED

#include "position.h"

/**
  * @enum Couleur
  *
  * Une couleur peut �tre noire, blanche ou vide
  *
  * */

typedef enum couleur {VIDE, ROUGE, BLEU, JAUNE, VERT, MARQUEUR} Couleur;

/**
  * @struct ensemble_colore
  *
  * Une structure incluant une couleur permettant de g�rer une liste simplement chain�e de positions
  *
  * @var La taille de la liste
  * @var Un pointeur sur la t�te de la liste
  * @var Un pointeur sur l'�l�ment courant de la liste
  * @var La couleur de la liste
  *
  * */

typedef struct ensemble_colore
{
    int taille;
    element_position* tete;
    element_position* courant;
    Couleur couleur;
} ensemble_colore;

#endif
