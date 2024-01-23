#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "utilisateurAdmin.hh"

void UtilisateurAdmin::vendreTicket(Evenement evenement){
    
}

void UtilisateurAdmin::modifierTicketNom(Evenement evenement, std::string nom){
    evenement.modifierNom(nom);
}

void UtilisateurAdmin::modifierTicketDate(Evenement evenement, std::string date){
    evenement.modifierDate(date);
}

void UtilisateurAdmin::modifierTicketLieu(Evenement evenement, std::string lieu){
    evenement.modifierLieu(lieu);
}

void UtilisateurAdmin::modifierTicketDescription(Evenement evenement, std::string description){
    evenement.modifierDescription(description);
}

void UtilisateurAdmin::modifierTicketType(Evenement evenement, std::string type){
    evenement.modifierType(type);
}

void UtilisateurAdmin::modifierNomAutre(std::string nom, Utilisateur &user){
    user.modifierNom(nom);
}

void UtilisateurAdmin::modifierPrenomAutre(std::string prenom, Utilisateur &user){
    user.modifierPrenom(prenom);
}

void UtilisateurAdmin::modifierMailAutre(std::string mail, Utilisateur &user){
    user.modifierMail(mail);
}

void UtilisateurAdmin::modifierTelephoneAutre(std::string telephone, Utilisateur &user){
    user.modifierTelephone(telephone);
}

void UtilisateurAdmin::modifierLoginAutre(std::string login, Utilisateur &user){
    user.modifierLogin(login);
}

void UtilisateurAdmin::modifierMdpAutre(std::string mdp, Utilisateur &user){
    user.modifierMdp(mdp);
}

void UtilisateurAdmin::modifierTypeAutre(std::string type, Utilisateur &user){
    user.modifierType(type);
}