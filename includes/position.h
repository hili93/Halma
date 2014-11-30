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
  * @file position.c
  *
  * Fichier d'en-t�te du type abstrait Positions
  *
  * */

#ifndef POSITION_H_INCLUDED
#define POSITION_H_INCLUDED

/**
  * @struct position
  *
  * La structure impl�mentant une position
  *
  * @var L'abscisse
  * @var L'ordonn�e
  *
  * */

typedef struct position
{
    int x;
    int y;
} Position;

/**
  * @struct element_position
  *
  * L'�l�ment d'une liste simplement chain�e de positions
  *
  * @var La position
  * @var Un pointeur sur l'�lement suivant
  *
  * */

typedef struct element_position
{
    Position position;
    struct element_position* suivant;
} element_position;

/**
  * @struct ensemble_position
  *
  * Une structure permettant de g�rer une liste simplement chain�e de positions
  *
  * @var La taille de la liste
  * @var Un pointeur sur la t�te de la liste
  * @var Un pointeur sur l'�l�ment courant de la liste
  *
  * */

typedef struct ensemble_positions
{
    int taille;
    element_position* tete;
    element_position* courant;
} ensemble_positions;

#endif
