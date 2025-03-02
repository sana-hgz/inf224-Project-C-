Build & Run
Commencer par lancer le serveur : Dans le dossier cpp, lancer : make pour compiler puis make run (Parfois il faut supprimer le fichier depend-myprog avant. On peut faire ceci soit manuellement soit via la ligne de commande en tapant rm depend-myprog puis make clean)
Le serveur se mettra en écoute sur le port 3331
Puis lancer le client swing : Dans le dossier swing, lancer : make run

Explication :
Le serveur C++ est chargé de recevoir les requêtes du client (Java Swing), de les analyser, puis d’exécuter les actions correspondantes sur la base de données
(Database). Il est basé sur TCP/IP et utilise des sockets pour la communication. server.cpp : Gestion de la connexion et des requêtes
 Le serveur démarre en créant un objet TCPServer, qui écoute sur un port spécifique
(3331).  Lorsqu’une requête est reçue, elle est analysée et traitée directement dans une
fonction lambda.  Chaque commande est interprétée et exécute une méthode de Database pour
effectuer l’action demandée.  La réponse est ensuite envoyée au client via la socket TCP. Partie Client (Java Swing)
Le client Java joue le rôle d’une interface graphique permettant d’envoyer des requêtes au serveur et d’afficher les réponses. Fonctionnement du client
 Connexion au serveur via un socket TCP (MediaClientGUI.java).  Envoi de commandes sous forme de texte (displayMedia, playMedia, etc.).  Réception des réponses du serveur, qui sont affichées dans l’interface Swing.  Boutons et menus interactifs pour exécuter des actions sans taper de commande
manuellement.
Synchronisation entre le Client et le Serveur
 Le serveur doit être lancé avant le client (make run côté C++).  Le client Swing envoie une requête sous forme de chaîne (String).  Le serveur interprète la requête, exécute l’action et renvoie une réponse.  Le client affiche la réponse dans la zone de texte Swing. Avec cette structure, le serveur C++ et le client Java peuvent interagir en temps
réel pour gérer les objets multimédias de manière fluide.
