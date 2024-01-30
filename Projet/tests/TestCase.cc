// Let DocTest provide main():
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "utilisateur.hh"
#include "evenement.hh"
#include "utilisateurAdmin.hh"
#include "utilisateurVIP.hh"
#include "utilisateurPublic.hh"
#include <SFML/Graphics.hpp>
#include "applicationJO.hh"

TEST_CASE("Test de utilisateurPublic.hh")
{
    std::cout << "------------------------------\nTest de utilisateurPublic.hh" << std::endl;
    UtilisateurPublic test1("nom1", "prenom1", "mail1", "telephone1", "login1", "mdp1", "type1");
    UtilisateurPublic test1bis("nom1", "prenom1", "mail1", "telephone1", "login1", "mdp1", "type1");
    CHECK(test1.getNom() == "nom1");
    CHECK(test1.getPrenom() == "prenom1");
    CHECK(test1.getMail() == "mail1");
    CHECK(test1.getTelephone() == "telephone1");
    CHECK(test1.getLogin() == "login1");
    CHECK(test1.getMdp() == "mdp1");
    CHECK(test1.getType() == "type1");
    CHECK(test1 == test1bis);
    std::cout << test1 << std::endl;
    Evenement event1("Enom1", "Edate1", "Elieu1", "Edescription1", "Etype1");
    Evenement event2("Enom2", "Edate2", "Elieu2", "Edesciption2", "VIP");
    test1.acheterTicket(event1);
    test1.consulterTicket(event1);
    test1.acheterTicket(event2);
    test1.consulterListeTickets();
    test1.annulerTicket(event1);
    test1.consulterListeTickets();
}

TEST_CASE("Test de utilisateurVIP.hh")
{
    std::cout << "------------------------------\nTest de utilisateurVIP.hh" << std::endl;
    UtilisateurVIP test2("nom2", "prenom2", "mail2", "telephone2", "login2", "mdp2", "type2");
    UtilisateurVIP test2bis("nom2", "prenom2", "mail2", "telephone2", "login2", "mdp2", "type2");
    CHECK(test2.getNom() == "nom2");
    CHECK(test2.getPrenom() == "prenom2");
    CHECK(test2.getMail() == "mail2");
    CHECK(test2.getTelephone() == "telephone2");
    CHECK(test2.getLogin() == "login2");
    CHECK(test2.getMdp() == "mdp2");
    CHECK(test2.getType() == "type2");
    CHECK(test2 == test2bis);
    std::cout << test2 << std::endl;
    Evenement event1("Enom1", "Edate1", "Elieu1", "Edescription1", "Etype1");
    Evenement event2("Enom2", "Edate2", "Elieu2", "Edesciption2", "VIP");
    test2.acheterTicket(event1);
    test2.consulterTicket(event1);
    test2.acheterTicket(event2);
    test2.consulterListeTickets();
    test2.consulterListeTicketsVIP();
    test2.annulerTicket(event1);
    test2.consulterListeTickets();
}

TEST_CASE("Test de utilisateurAdmin.hh")
{
    std::cout << "------------------------------\nTest de utilisateurAdmin.hh" << std::endl;
    UtilisateurAdmin test3("nom3", "prenom3", "mail3", "telephone3", "login3", "mdp3", "type3");
    UtilisateurAdmin test3bis("nom3", "prenom3", "mail3", "telephone3", "login3", "mdp3", "type3");
    CHECK(test3.getNom() == "nom3");
    CHECK(test3.getPrenom() == "prenom3");
    CHECK(test3.getMail() == "mail3");
    CHECK(test3.getTelephone() == "telephone3");
    CHECK(test3.getLogin() == "login3");
    CHECK(test3.getMdp() == "mdp3");
    CHECK(test3.getType() == "type3");
    CHECK(test3 == test3bis);
    std::cout << test3 << std::endl;
    Evenement event1("Enom1", "Edate1", "Elieu1", "Edescription1", "Etype1");
    Evenement event2("Enom2", "Edate2", "Elieu2", "Edesciption2", "VIP");
    test3.acheterTicket(event1);
    test3.consulterTicket(event1);
    test3.acheterTicket(event2);
    test3.consulterListeTickets();
    test3.consulterListeTicketsVIP();
    test3.annulerTicket(event1);
    test3.modifierTicketType(event1, "VIP");
    test3.modifierTicketNom(event1, "nom1-2");
    test3.modifierTicketDate(event1, "date1-2");
    test3.modifierTicketLieu(event1, "lieu1-2");
    test3.modifierTicketDescription(event1, "description1-2");
    CHECK(event1.getNom() == "nom1-2");
    CHECK(event1.getDate() == "date1-2");
    CHECK(event1.getLieu() == "lieu1-2");
    CHECK(event1.getDescription() == "description1-2");
    CHECK(event1.getType() == "VIP");
    test3.acheterTicket(event1);
    test3.consulterListeTicketsVIP();
    test3.modifierNomAutre("nom3-2", test3);
    test3.modifierPrenomAutre("prenom3-2", test3);
    test3.modifierMailAutre("mail3-2", test3);
    test3.modifierTelephoneAutre("telephone3-2", test3);
    test3.modifierLoginAutre("login3-2", test3);
    test3.modifierMdpAutre("mdp3-2", test3);
    test3.modifierTypeAutre("type3-2", test3);
    CHECK(test3.getNom() == "nom3-2");
    CHECK(test3.getPrenom() == "prenom3-2");
    CHECK(test3.getMail() == "mail3-2");
    CHECK(test3.getTelephone() == "telephone3-2");
    CHECK(test3.getLogin() == "login3-2");
    CHECK(test3.getMdp() == "mdp3-2");
    CHECK(test3.getType() == "type3-2");
}