# Billetterie des Jeux Olympiques

## Présentation

Cette application a été réalisée par [Jacky CHUI](https://github.com/Chui-Jacky) et [Lucas GAUVAIN](https://github.com/GauvainLucas), étudiants ingénieurs en 4ème année d'Electronique et Informatique - Systèmes Embarqués (EI-SE) à Polytech Sorbonne. 

Notre application est une plateforme de billetterie dédiée aux Jeux Olympiques, dans laquelle se trouvent différentes fonctionnalités. Les utilisateurs peuvent facilement consulter les événements actuels et à venir, acheter des billets, et annuler leurs achats si nécessaire. Les événements disponibles à la réservation sont des compétitions sportives ainsi que des cérémonies.

Certains utilisateurs bénéficient de privilèges VIP, qui leur donnent accès à des événements exclusifs. De plus, des administrateurs sont disponibles pour assister les clients, que ce soit pour la modification de leur compte ou pour ajuster certains évènements.

L'application offre également une fonctionnalité de suivi des actualités, permettant aux utilisateurs de rester informés sur les derniers résultats en direct. Ainsi, notre application vise à simplifier l'expérience de billetterie tout en offrant des fonctionnalités pour suivre les actualités des Jeux Olympiques de Paris 2024.


## Informations pratiques

Pour installer les librairies SFML sous Linux, exécutez la commande suivante :

```bash
sudo apt-get install libsfml-dev
```
Pour compiler le projet, un makefile a été fait. Dans le dossier projet ou se trouve tous les fichiers sources entrez la commande :
```bash
make
```
La commande va ensuite générer l'exécutable applicationJO.out que l’on peut exécuter en faisant :
```bash
./applicationJO.out
```

Pour effectuer les tests, il faut se rendre dans le dossier tests. A l’intérieur de ce dossier se trouve un autre makefile. Compilez en exécutant la commande :
```bash
make
```
Lancez les tests en exécutant l'exécutable testcase.out :
```bash
/testcase.out
```



