
#include <iostream>
#include<string>
#include <fstream>
#include <cstdlib>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


using namespace std;


string entree_chaine() {
    string s;
    do {
        cin >> s;
        if (s.length() != 7) {
            cout << "ATTENTION !! " << endl;
            cout << "Donner une chaine de 7 characteres !" << endl;
        }
    }     while (s.length() != 7);
    return s;
}


bool verif_exist(char c, string s) {
    for (int i = 0; i < s.length(); i++) {
        if (toupper(s[i]) == toupper(c)) {
            return 1;
        }
    }
    return 0;
}

bool verif_pos(char c1, char c2) {
        if (toupper(c1) == toupper(c2)) {
            return 1;
        
    }
    return 0;
}

int verification(string c_donnee, string c_entree) {
    int m = 0;
    for (int i = 0; i < c_donnee.length(); i++) {
        if ((verif_pos(c_donnee[i], c_entree[i])) && (verif_exist(c_entree[i], c_donnee)) ){
            cout << "La lettre " << c_entree[i] << " existe et est dans la bonne position " << endl;
            m += 1;
        }
        else if ((verif_exist(c_entree[i], c_donnee)) && !(verif_pos(c_donnee[i], c_entree[i]))) {
            cout << "La lettre " << c_entree[i] << " existe mais dans la mauvaise position" << endl;
        }
        else {
            cout << "La lettre " << c_entree[i] << " n'existe pas !" << endl;
        }
    }  
    cout << "m = " << m << endl;
    return m;
}

void resultat_jeu(int m) {
    if (m == 7) {
        cout << endl;
        cout << "        FELICITATION VOUS AVEZ GAGNEE LE JEU ! " << endl;
        cout << endl;

    }
    else {
        cout << endl;
        cout << "        MALHEUREUSEMENT VOUS N'AVEZ PAS GAGNEE ! " << endl;
        cout << endl;

    }
}


void indice_deuxieme_lettre(string s) {
    cout << endl;
    cout << "************************ VOICI UN INDICE = ****************************" << endl;
    cout << "La deuxieme lettre est = " << s[1] << endl;
    cout << endl;
}



// -------------------------  Import string from the file ---------------------------//

string import_from_file(int number) {
    ifstream input("7 letter words.txt");
    int i = 0;
    if (input.is_open()) {
        string line;
        while (getline(input, line)) {
            if (number == i) {
                return line.c_str();
            }
            i++;
        }
        input.close();
    }
}


int main()
{



    // ------------------------- DECLARATION -------------------------------//
    int score;
    string c_entree;
    string s;
    int compteur = 0;

    // --------------------- READ FROM FILE  -----------------------------//

    /*ifstream input("7 letter words.txt");*/
    srand(time(NULL));
    int rand_compteur;

    rand_compteur = (rand() % 10);
    
    c_entree = import_from_file(rand_compteur);
    cout << c_entree << endl;
    
    // --------------------- DEBUT JEU -----------------------------//

    cout << "************       JEU MOTUS       **************" << endl;
    do {
        // ESSAI COUNT
        if (compteur >= 1) {
            cout << "************   ESSAYEZ DE NOUVEAU        **************" << endl;
        }
        cout << "ESSAI NUMERO "<< compteur +1 << endl;
        cout << "La premiere lettre est = " << c_entree[0] << endl;
        // INDICE PREMIERE LETTRE

        if (compteur >= 2) {
            indice_deuxieme_lettre(c_entree);
        }

        s = entree_chaine();
        cout << "Votre chaine est " << s << endl;
        score = verification(c_entree, s);
        
        cout << "************       RESULTAT JEU MOTUS       **************" << endl;

        resultat_jeu(score);
        
        

        compteur++;
        if (score == 7) {
            break;
        }
           
    }     while (compteur < 4);

    
    return 0;
}

