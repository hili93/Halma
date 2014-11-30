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
  * @file territoires.c
  *
  * Fichier d'en-t�te du type abstrait Territoires
  *
  * */

#ifndef TERRITOIRES_H_INCLUDED
#define TERRITOIRES_H_INCLUDED

#include "territoire.h"

/**
  * @struct element_territoire
  *
  * L'�l�ment d'une liste simplement chain�e de territoires
  *
  * @var Un territoire
  * @var Un pointeur sur l'�l�ment suivant
  *
  * */

typedef struct element_territoire
{
    Territoire territoire;
    struct element_territoire* suivant;
} element_territoire;

/**
  * @struct ensemble_territoires
  *
  * La structure permettant de g�rer une liste simplement chain�e de territoires
  *
  * @var La taille de la liste
  * @var Un pointeur sur la t�te de la liste
  * @var Un pointeur sur l'�l�ment courant de la liste
  *
  * */

typedef struct ensemble_territoires
{
    int taille;
    element_territoire* tete;
    element_territoire* courant;
} ensemble_territoires;

/**
  * @typedef Territoires
  *
  * Territoires est un pointeur sur ensemble_territoires
  *
  * */

typedef ensemble_territoires* Territoires;

/**
  * Cr�ation et intialisation d'une liste simplement chain�e de territoires
  *
  * @return La liste correctement allou�e
  *
  * */

Territoires territoires_creer();

/**
  * Destruction d'une liste de territoires
  *
  * @param La liste � d�truire
  *
  * */

void territoires_detruire(Territoires liste);

/**
  * Teste si une liste de territoires est vide
  *
  * @param La liste � tester
  * @return 1 si la liste est vide, 0 si elle ne l'est pas
  *
  * */

int territoires_vide(Territoires liste);

/**
  * Ajoute un territoire � une liste de territoires
  *
  * @param Le territoires � ajouter
  * @param La liste � laquelle on veut ajouter un territoire
  *
  * */

void territoires_ajouter(Territoire territoire, Territoires liste);

/**
  * Teste si un territoire appartient � une liste de territoires
  *
  * @param Le territoire � tester
  * @param La liste � tester
  * @return 1 si le territoire appartient � la liste, 0 sinon
  *
  * */

int territoires_appartient(Territoire territoire, Territoires liste);

/**
  * Se placer en t�te d'une liste de territoires
  *
  * @param La liste � traiter
  *
  * */

void territoires_tete(Territoires liste);

/**
  * Passer � l'�l�ment suivant d'une liste de territoires
  *
  * @param La liste � traiter
  * @return 1 s'il y'a bien un suivant, 0 sinon
  *
  * */

int territoires_suivant(Territoires liste);

/**
  * L'�l�ment courant d'une liste de territoires
  *
  * @param La liste � traiter
  * @return Un pointeur sur l'�l�ment courant de la liste
  *
  * */

element_territoire* territoires_courant(Territoires liste);

#endif
