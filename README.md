# BE_POO_Template

README PROJET C++ : 

Le jeu se déroule en 3 parties.

La première est la distribution des rôles, durant laquelle chaque personne apprend individuellement son rôle.  Pour cela, le premier joueur regarde l’écran LED, et les autres ferment les yeux. Il appuie sur son bouton, regarde son rôle, rappuie dessus et passe l’écran LED au prochain joueur qui répète l’action. 

La seconde partie est la Nuit. Ici, chaque personne agit selon son rôle. Lorsque le joueur est appelé, il se réveille, joue son rôle (par exemple, le barman rajoute une gorgée à un joueur, il appuie sur le bouton du joueur souhaité pour cela). 

Voici les différents rôles et ce qu’ils font :
-Barman : Peut rajouter une gorgée au joueur de son choix
-Protège Verre : Peut immuniser un verre de son choix
-Gratteur de verre : Enlève deux gorgées à une personne de leur choix
-Maladroit : Enlève une gorgée au joueur de son choix
-Éthylotest : Regarde le nombre de gorgées d’un joueur

Ensuite, il y a le Jour. Ici, nous avons un récapitulatif des gorgées de chacun et précise si quelqu’un est mort la nuit. Puis, nous avons le vote du village où ils choisissent d’enlever deux gorgées à un joueur. Nous avons remis ensuite, le récapitulatif des gorgées et si un joueur est mort pendant le vote.
Un joueur meurt lorsque son nombre de gorgées est égal à 0.

La partie se termine lorsque les gratteurs gagnent ou les villageois (tous les autres rôles) gagnent. Pour que les villageois gagnent, il faut que tous les gratteurs soient morts. Pour que les gratteurs gagnent, il faut qu’il y ait autant ou moins de villageois que de gratteurs. 

MATÉRIEL :
-ESP8266EX
-Capteurs I2C touch sensor ( avec 6 touch feelers)
-Grove MP3 V2
-Grove LCD RGB backlight 


Bibliothèque :
A installer sur Arduino directement :
-  https://github.com/Seeed-Studio/Grove_I2C_Touch_Sensor : librairie (.zip)  à télécharger et à ajouter sur le projet Arduino
-  https://github.com/Seeed-Studio/Grove_LCD_RGB_Backlight/archive/master.zip à télécharger et à ajouter sur le projet Arduino
-  Seeed_Serial_MP3_Player dans la librairie arduino à télécharger également


