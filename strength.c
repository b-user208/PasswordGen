#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "strength.h"

int strength(char mdp[]) {
    unsigned taille = strlen(mdp);

    // Boolean
    _Bool lower = 0,
    upper = 0,
    digit = 0,
    special = 0;

    // Analyse
        for(unsigned i = 0; i < taille; ++i) {
            if(islower(mdp[i])) lower = 1;
            if(isupper(mdp[i])) upper = 1;
            if(isdigit(mdp[i])) digit = 1;
            if(ispunct(mdp[i])) special = 1;
        }

    unsigned
    // Différents score 
    repet = 0,
    score_categorie = 0,
    score_brut = 0,
    score_longueur = (taille - 8) * 4;
    if(score_longueur >= 40)
        score_longueur = 40;

        // Scoring
        score_categorie = (lower + upper + digit + special) * 15;
        score_brut = score_categorie + score_longueur;

        // Malus consecutif
        for(unsigned i = 0; i + 1 < taille; ++i)
            if(mdp[i] == mdp[i + 1]) 
                ++repet;

        // Malus de fréquence
        for(unsigned i = 0; i < taille; ++i) {
                unsigned count = 0;
            for(unsigned j = i + 1; j < taille; ++j) 
                if((mdp[i] != mdp[j]) && (mdp[i] == mdp[j + 1])) {
                    ++count;
                    if((count >= 2) && (count % 2 == 0))
                        ++repet;
                }
            }

        // Score final 
        int score_final = score_brut - repet;

        // Force
        return score_final;
}