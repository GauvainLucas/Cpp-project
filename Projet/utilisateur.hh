#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "evenement.hh"


class Utilisateur{
    public:
        Utilisateur();
        Utilisateur(std::string nom, std::string prenom, std::string mail,
                    std::string telephone, std::string login, std::string mdp, std::string type);

        // getters
        std::string getNom(){return nom;};
        std::string getPrenom(){return prenom;};
        std::string getMail(){return mail;};
        std::string getTelephone(){return telephone;};
        std::string getLogin(){return login;};
        std::string getMdp(){return mdp;};
        std::string getType(){return type;};

        virtual void acheterTicket(Evenement evenement) = 0;
        virtual void annulerTicket(Evenement evenement) = 0;
        virtual void consulterTicket(Evenement evenement) = 0;
        virtual void consulterListeTickets() = 0;
        virtual void consulterListeTicketsEvenement(std::string nomEvenement) = 0;
        virtual void consulterListeTicketsDate(std::string dateEvenement) = 0;
        virtual void consulterListeTicketsLieu(std::string lieuEvenement) = 0;
        virtual void consulterListeTicketsType(std::string typeEvenement) = 0;
        
        void modifierNom(std::string nom);
        void modifierPrenom(std::string prenom);
        void modifierMail(std::string mail);
        void modifierTelephone(std::string telephone);
        void modifierLogin(std::string login);
        void modifierMdp(std::string mdp);
        void modifierType(std::string type);
        /*
        virtual void acheterTicket(Evenement event) = 0;
        void annulerTicket(std::string nomEvenement);
        void consulterTicket(std::string nomEvenement);
        void consulterListeTickets();
        void consulterListeTicketsEvenement(std::string nomEvenement);
        void consulterListeTicketsDate(std::string dateEvenement);
        void consulterListeTicketsLieu(std::string lieuEvenement);
        void consulterListeTicketsType(std::string typeEvenement);

        void modifierNom(std::string nom){this->nom = nom;};
        void modifierPrenom(std::string prenom){this->prenom = prenom;};
        void modifierMail(std::string mail){this->mail = mail;};
        void modifierTelephone(std::string telephone){this->telephone = telephone;};
        void modifierLogin(std::string login){this->login = login;};
        void modifierMdp(std::string mdp){this->mdp = mdp;};
         */

    protected:
        std::string nom;
        std::string prenom;
        std::string mail;
        std::string telephone;
        std::string login;
        std::string mdp;
        std::string type;
        std::vector<Evenement> listeTickets;
};