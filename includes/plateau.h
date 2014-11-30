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
  * @file plateau.c
  *
  * Fichier d'en-t�te du type abstrait Plateau
  *
  * */

#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED

#include "couleur.h"

/**
  * @struct structure_plateau
  *
  * La structure impl�mentant un plateau de jeu
  *
  * @var La taille du plateau
  * @var Un tableau d'une dimension stockant la couleur de chaque case du plateau
  *
  * */

typedef struct structure_plateau
{
    int taille;
    Couleur* couleur;
} structure_plateau;

/**
  * @typedef Plateau
  *
  * Plateau est un pointeur sur structure_plateau
  *
  * */

typedef structure_plateau* Plateau;

#include "pion.h"
#include "libertes.h"
#include "chaines.h"
#include "territoires.h"

/**
  * Cr�ation et intialisation d'un plateau de jeu
  *
  * @param La taille du plateau
  * @return Le plateau correctement initialis�
  *
  * */

Plateau plateau_creer(int taille);

/**
  * Destruction d'un plateau de jeu
  *
  * @param Le plateau � d�truire
  *
  * */

void plateau_detruire(Plateau plateau);

/**
  * R�cup�re la couleur d'une case sur le plateau
  *
  * @param Le plateau
  * @param L'abscisse de la position
  * @param L'ordonn�e de la position
  * @return La couleur � la position voulue
  *
  * */

Couleur plateau_get(Plateau plateau, int i, int j);

/**
  * Modifier la couleur d'une case sur le plateau
  *
  * @param Le plateau
  * @param L'abscisse de la position
  * @param L'ordonn�e de la position
  * @param La couleur � mettre sur la case
  *
  * */

void plateau_set(Plateau plateau, int i, int j, Couleur couleur);

/**
  * D�terminer la chaine � laquelle appartient un pion
  *
  * @param Le plateau courant
  * @param La position du pion
  * @return La chaine compl�te
  *
  * */

Chaine plateau_determiner_chaine(Plateau plateau, Position pos);

/**
  * R�aliser la capture d'une chaine sur le plateau
  *
  * @param Le plateau � modifier
  * @param La chaine � capturer
  *
  * */

void plateau_realiser_capture(Plateau plateau, Chaine chaine);

/**
  * Teste si deux plateaux sont indentiques
  *
  * @param Le premier plateau � tester
  * @param Le second plateau � tester
  * @return 1 si les plateaux sont identiques, 0 sinon
  *
  * */

int plateau_est_identique(Plateau plateau1, Plateau plateau2);

/**
  * Copier un plateau vers un autres, les deux �tant correctement allou�s
  *
  * @param Le plateau source
  * @param Le plateau destination
  * @return 1 si la copie est r�ussie, 0 sinon
  *
  * */

int plateau_copie(Plateau from, Plateau to);

/**
  * D�terminer les chaines qui entourent un territoire sur le plateau
  *
  * @param Le territoire
  * @param Le plateau courant
  * @return La liste des chaines entourant le territoire
  *
  * */

Chaines plateau_entoure_un_territoire(Territoire territoire, Plateau plateau);

/**
  * Sauvegarder un pleteau
  *
  * @param Le plateau � sauvegarder
  * @param Le fichier o� sauvegarder
  * @return 1 si la sauvegarde est r�ussie, 0 sinon
  *
  * */

int plateau_sauvegarde(Plateau plateau, FILE* fichier);

/**
  * Charger un pleteau
  *
  * @param Le fichier � partir duquel charger
  * @return Le plateau charg�
  *
  * */

Plateau plateau_chargement(FILE* fichier);

/**
  * D�termine les chaines captur�es par la pose d'un pion, et si le coup est valide ou non
  *
  * @param Le plateau courant
  * @param Le pion � poser
  * @param Un pointeur sur le bool�en � mettre � 1 si le coup est valide, 0 sinon
  * @return La liste des chaines captur�es
  *
  * */

Chaines capture_chaines(Plateau plateau, Pion pion, int* valide);

#endif
