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
  * @file chaines.c
  *
  * Fichier d'en-t�te du type abstrait Chaines
  *
  * */

#ifndef CHAINES_H_INCLUDED
#define CHAINES_H_INCLUDED

#include "chaine.h"

/**
  * @struct element_chaine
  *
  * L'�l�ment d'une liste simplement chain�e de chaines
  *
  * @var Une chaine
  * @var Un pointeur sur l'�l�ment suivant
  *
  * */

typedef struct element_chaine
{
    Chaine chaine;
    struct element_chaine* suivant;
} element_chaine;

/**
  * @struct ensemble_chaines
  *
  * La structure permettant de g�rer une liste simplement chain�e de chaines
  *
  * @var La taille de la liste
  * @var Un pointeur sur la t�te de la liste
  * @var Un pointeur sur l'�l�ment courant de la liste
  *
  * */

typedef struct ensemble_chaines
{
    int taille;
    element_chaine* tete;
    element_chaine* courant;
} ensemble_chaines;

/**
  * @typedef Chaines
  *
  * Chaines est un pointeur sur ensemble_chaines
  *
  * */

typedef ensemble_chaines* Chaines;

/**
  * Cr�ation et intialisation d'une liste simplement chain�e de chaines
  *
  * @return La liste correctement allou�e
  *
  * */

Chaines chaines_creer();

/**
  * Destruction d'une liste de chaines
  *
  * @param La liste � d�truire
  *
  * */

void chaines_detruire(Chaines liste);

/**
  * Teste si une liste de chaines est vide
  *
  * @param La liste � tester
  * @return 1 si la liste est vide, 0 si elle ne l'est pas
  *
  * */

int chaines_vide(Chaines liste);

/**
  * Ajoute une chaine � une liste de chaines
  *
  * @param La chaine � ajouter
  * @param La liste � laquelle on veut ajouter une chaine
  *
  * */

void chaines_ajouter(Chaine chaine, Chaines liste);

/**
  * Teste si une chaine appartient � une liste de chaines
  *
  * @param La chaine � tester
  * @param La liste � tester
  * @return 1 si la chaine appartient � la liste, 0 sinon
  *
  * */

int chaines_appartient(Chaine chaine, Chaines liste);

/**
  * Se placer en t�te d'une liste de chaines
  *
  * @param La liste � traiter
  *
  * */

void chaines_tete(Chaines liste);

/**
  * Passer � l'�l�ment suivant d'une liste de chaines
  *
  * @param La liste � traiter
  * @return 1 s'il y'a bien un suivant, 0 sinon
  *
  * */

int chaines_suivant(Chaines liste);

/**
  * L'�l�ment courant d'une liste de chaines
  *
  * @param La liste � traiter
  * @return Un pointeur sur l'�l�ment courant de la liste
  *
  * */

element_chaine* chaines_courant(Chaines liste);

#endif
