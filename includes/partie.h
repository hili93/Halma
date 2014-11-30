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
  * @file partie.c
  *
  * Fichier d'en-t�te du type abstrait Partie
  *
  * */

#ifndef PARTIE_H_INCLUDED
#define PARTIE_H_INCLUDED

#include "plateau.h"

/**
  * @struct Joueur
  *
  * La structure impl�mentant un joueur
  *
  * @var Le nom du joueur
  * @var 1 s'il est humain, 0 si c'est une IA
  * @var Son score (conserv� au fil de la partie)
  *
  * */

typedef struct joueur
{
    char nom[8];
    int humain;
    float* score;
} Joueur;

/**
  * @struct Partie
  *
  * La structure permettant de g�rer tout le d�roulement d'une partie
  *
  * @var 1 si la partie est termin�e, 0 sinon
  * @var 1 si au tour pr�c�dent, le joueur a pass�
  * @var Le nombre de coups jou�s en tout
  * @var Le nombre de fois qu'un des joueurs a pass� son tour
  * @var Le dernier coup jou� (conserv� au fil de la partie)
  * @var Le plateau actuel et tous les pr�c�dents
  * @var Un tableau contenant les deux joueurs
  * @var Le komi d�fini pour la partie
  *
  * */

typedef struct partie
{
    int termine;
    int passe;
    int nbCoups;
    int nbPasse;
    char (*dernier)[4];
    Plateau* plateau;
    Joueur joueur[2];
    float komi;
} Partie;

/**
  * @typedef FonctionsQuestions
  *
  * Pointeur sur une fonction r�cup�rant le param�trage d'une partie par l'utilisateur
  *
  * */

typedef void (*FonctionQuestions)(int numeroQuestion, Partie* p);

/**
  * Cr�� et initialise une partie selon le param�trage de l'utilisateur
  *
  * @param Un pointeur sur la fonction communiquant avec l'utilisateur
  * @return La partie correctement intialis�e
  *
  * */

Partie partie_initialisation(FonctionQuestions fonctionQuestions);

/**
  * Pose les questions n�cessaires � la cr�ation d'une partie � l'utilisateur en mode console
  *
  * @param Le num�ro de la question
  * @param Un pointeur sur la partie � initialiser
  *
  * */

void fonctionQuestions(int numeroQuestion, Partie* p);

/**
  * Sauvegarde une partie
  *
  * @param La partie � sauvegarder
  * @param Le fichier o� sauvegarder
  * @return 1 si la sauvegarde a �t� r�ussie, 0 sinon
  *
  * */

int partie_sauvegarde(Partie partie, FILE* fichier);

/**
  * Charge une partie
  *
  * @param Le fichier � partir duquel charger
  * @return La partie charg�e
  *
  * */

Partie partie_chargement(FILE* fichier);

/**
  * Calcule le score de chaque joueur en fin de partie
  *
  * @param La partie � traiter
  *
  * */

void partie_score_joueurs(Partie* p);

#endif
