#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "utilisateurVIP.hh"

class UtilisateurAdmin : public UtilisateurVIP{
    public:
        UtilisateurAdmin();
        UtilisateurAdmin(std::string nom, std::string prenom, std::string mail, std::string telephone, std::string login, std::string mdp, std::string type):UtilisateurVIP(nom, prenom, mail, telephone, login, mdp, type){};

        void vendreTicket(std::string nomEvenement);
        void modifierTicket(std::string nomEvenement);

        void modifierNomAutre(std::string nom, std::string loginUser);
        void modifierPrenomAutre(std::string prenom, std::string loginUser);
        void modifierMailAutre(std::string mail, std::string loginUser);
        void modifierTelephoneAutre(std::string telephone, std::string loginUser);
        void modifierLoginAutre(std::string login, std::string loginUser);
        void modifierMdpAutre(std::string mdp, std::string loginUser);
        void modifierTypeAutre(std::string type, std::string loginUser);

};