
Travail pratique tp3

   ## Description

   On cherche la liste des nombres parfaits qui n'existe pas
   dans le cours INF3135 a UQAM

   ## Approche

   Dans le cadre du cours, on a constate que un ombre est parfait si ET seulement si (2^p)-1 est un nombre premier.
   
   Donc, pour notre premiere boucle, on parcours de 2 jusqu'a 31 puisque qu'on travaille avec des nombres de 32 bits.
   
   Ensuite, on verifie si c'est un nombre parfait potentiel en appliquant la formule 2^(p-1)*(2^p)-1 ET en verifiant que (2^p)-1 est un nb premier.

   Finalement, si la somme des diviseurs de notre nombre parfait potentiel est egale a notre nombre, on peut conclure que notre nombre est un nombre parfait.   
   ## Auteur

   Andy Chen CHEA23099303	

   ## Fonctionnement

   ./tp3 -c abcd12345678 -i fichierentree.txt -o fichiersortie.txt

   ./tp3 -c abcd12345678 -i fichierentree.txt

   ./tp3 -c abcd12345678 -o fichiersortie.txt 

   ./tp3 -c abcd12345678 < fichierentree.txt > fichiersortie.txt

   (demande a l'utilisateur d'enter un fichier de sortie)

   les resultats sont dirigees dans le fichier de sortie

   ## Contenu du projet

   Makefile - fichier makefile pour automatiser 
   tp3.c 
   README.md - fichier markdown
   outils.h
   outils.c
   cp.txt - fichier avec code permanent
   
   evaluer.sh - script pour automatiser nos tests, ou le format est:

   1: compteur

   2: le code de retour attendu

   3: notre code de retour

   4: resultat de nos tests

   5: la commande

   ## References
   https://forums.opensuse.org/showthread.php/443685-How-to-call-a-script-in-Makefile-and-capture-its-output

   https://www.geeksforgeeks.org/perfect-number/

   https://stackoverflow.com/questions/17509479/switch-case-for-parsing-options

   https://www.tutorialspoint.com/cprogramming/c_input_output.htm
     
   https://www.tutorialspoint.com/cprogramming/c_data_types.htm

   https://www.maths-et-tiques.fr/index.php/histoire-des-maths/nombres/les-nombres-parfaits   

   https://chgi.developpez.com/arbre/binaire/?fbclid=IwAR24E2Im9m-wGb7XPIcyczTQdnIUy2zT67KVI4BVjLLHgOHZc65DAJq1CCE
   
   Note de cours..

   ## Statut
   
   Tous les tests du fichier inf3135-h2019-tp3.correction passent sur le serveur Java et sur la machine locale.
