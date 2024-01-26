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


/*  TEST_CASE("Construct rabbit"){
    Rabbit leon, sophia(0,0),paul(22,-5);
    CHECK(sophia.getX() == 0);
    CHECK(sophia.getY() == 0);
    CHECK(leon.getX() >= 0);
    CHECK(leon.getY() >= 0);
    CHECK(leon.getX() < E_WIDTH);
    CHECK(leon.getY() < E_HEIGHT);
    CHECK(paul.getX() >= 0);
    CHECK(paul.getY() >= 0);
    CHECK(paul.getX() < E_WIDTH);
    CHECK(paul.getY() < E_HEIGHT);
  }

TEST_SUITE("Rabbit eats"){
  TEST_CASE("Rabbit can eat"){
    Rabbit sophia(0,0);
    Food salad(1,1);
    Food carrot(12,8);
    CHECK(sophia.Animal::eat(salad));
    CHECK_FALSE(sophia.Animal::eat(carrot));
  }
  TEST_CASE("Rabbit can eat"){
    Rabbit sophia(0,0);
    Food salad(0,0);
    sophia.move();
    unsigned int hp = sophia.getHP();
    sophia.Animal::eat(salad);
    CHECK(hp <= sophia.getHP());
  }

}

TEST_CASE("Count Rabbit's population")
    {
      {
        Rabbit leon;
        CHECK(Rabbit::popRabbit == 1);
      }
      CHECK(Rabbit::popRabbit == 0);
    }


TEST_SUITE("Fox Move"){
  TEST_CASE("keep going")
    {
      Fox felix(1,1);
      felix.move();
      CHECK(felix.getX() == 1 + ANIMAL_MAX_MOVE);
      CHECK(felix.getY() == 1);
    }
  TEST_CASE("Change direction")
    {
      Fox felicia(E_WIDTH-1,1);
      felicia.move();
      CHECK(felicia.getX() == E_WIDTH -1);
      CHECK(felicia.getY() == ANIMAL_MAX_MOVE); //+1(départ) -1 step (change dir)
    }
  TEST_CASE("Eat and change")
    {
      Fox kim(3,3);
      std::list<Rabbit> l_rabbit;
      l_rabbit.push_back(Rabbit(1,1));
      l_rabbit.push_back(Rabbit(2,2));
      kim.eat(l_rabbit);
      kim.move();
      CHECK(kim.getX() == 3);
      CHECK(kim.getY() == 13);
      CHECK(l_rabbit.size() == 1);
    }
}
TEST_CASE("Animal can reproduce"){
  // reproduce with a probability if distance is OK
  Rabbit joel(1,1);
  Rabbit gael(2,1);
  CHECK(joel.reproduce(gael) <=1);
}

TEST_CASE("Count Fox's population")
{
  {
    Fox pascal;
    CHECK(Fox::popFox == 1);
  }
  CHECK(Fox::popFox == 0);
}*/

/*************************************/
/*        New Groups template        */
/*************************************/

/*TEST_CASE("Construct new groups"){
  Group<Fox> meute;
  Group<Rabbit> rabbits(5);
  CHECK(meute.empty());
  CHECK_FALSE(rabbits.empty());
  CHECK(rabbits.getNb() == 5);
  CHECK(meute.getNbBirths() == 0);
  CHECK(meute.getNbEaten() == 0);
  std::list<Fox> foxes;
  foxes.push_back(Fox(0,0));
  foxes.push_back(Fox(8,8));
  foxes.push_back(Fox(1,0));
  Group<Fox> une_autre_meute(foxes);
  CHECK_FALSE(une_autre_meute.empty());
  CHECK(une_autre_meute.getNb() == 3);
  CHECK(une_autre_meute.getNbBirths() == 0);
  CHECK(une_autre_meute.getNbEaten() == 0);
}

TEST_CASE("Animal access"){
  // reproduce with a probability if distance is OK
  Group<Rabbit> rabbits(10);
  std::cout << rabbits << std::endl;
  rabbits[0] = Rabbit(1,1);
  CHECK(rabbits[0].getX() == 1);
  CHECK(rabbits[0].getY() == 1);
}

TEST_CASE("Eat"){
  Group<Fox> meute(1);
  Group<Rabbit> rabbits(10);
  // Put one rabbit near by the fox
  rabbits[0] = Rabbit(meute[0].getX(), meute[0].getY());
  u_int nbeaten = meute.eat(rabbits.getList());
  CHECK(nbeaten ==1);

  std::cout << nbeaten << std::endl;
  std::list<Vegetal> f;
  //create 10 food
  for(u_int i = 0 ; i<10 ; i++)
    f.emplace_back();
  u_int saladEaten = 0;

  saladEaten = rabbits.eat(f);
  CHECK(saladEaten<=10);

  std::cerr << f.size() << "Test Eat :  salad eaten : " << saladEaten <<  std::endl;

  //salad removes from the list
  CHECK(f.size() == 10 - saladEaten);
}

TEST_CASE("Reproduce"){
  //3 rabbits placed
  std::list<Rabbit> rabbits;
  rabbits.push_back(Rabbit(0,0));
  rabbits.push_back(Rabbit(8,8));
  rabbits.push_back(Rabbit(1,0));
  Group<Rabbit> meute(rabbits);
  u_int nbBirth = meute.reproduce();
  CHECK(nbBirth <= 1);
  CHECK(meute.getNb() <=4);
  nbBirth = meute.reproduce();
  CHECK(meute.getNbBirths() >= 0);
  // Au plus 3 naissances
  CHECK(meute.getNbBirths() <= 3);
  std::cerr << "Test Reproduce : Nombre de Naissances " << meute.getNbBirths() << std::endl;
}

TEST_CASE("Update"){
  //3 rabbits placed
  std::list<Rabbit> rabbits;
  rabbits.push_back(Rabbit(0,0));
  rabbits.push_back(Rabbit(18,7));
  rabbits.push_back(Rabbit(1,0));
  Group<Rabbit> pop_rabbit(rabbits);
  std::list<Fox> foxes;
  foxes.push_back(Fox(7,0));
  foxes.push_back(Fox(7,1));
  foxes.push_back(Fox(8,9));
  Group<Fox> pop_fox(foxes);

  std::cerr << "Test Update: Before " << std::endl;
  std::cerr << "Fox : " <<  pop_fox << std::endl;
  std::cerr << "Rabbit : "<< pop_rabbit << std::endl;

  pop_fox.update(pop_rabbit.getList());
  std::cerr << "Test Update: After " << std::endl;
  std::cerr << "Fox : " <<  pop_fox << std::endl;
  std::cerr << "Rabbit : "<< pop_rabbit << std::endl;

  CHECK(pop_fox.getNb() > 0);


}*/
