# HOMEWORK

This file is part of homework and it is distributed under the terms of the
GNU Lesser General Public License (Lesser GPL)

A.Y. 2017/2018<br>
University of Verona (Italy)

![homework](https://github.com/simonemene/homework/blob/master/image.png)

The file in homework contain the ROS based implementation in order to print name,age,degree course or the whole string.

I file in homework contengono una implementazione basata su ROS per stampare un nome, un'età, un corso di laurea o tutta la stringa.

In order to execute the code, it is required to write "roslaunch homework homework.launch" on the control terminal or start "roscore" and open a terminal for each node with the command "rosrun homework name_node", execute the nodes in the following order : node3,node1 and then node2.

Per eseguire il codice basta scrivere sul terminale, dopo aver effettuato correttamente il "catkin_make", il comando "roslaunch homework homework.launch" o avviare "roscore" e aprire un terminale per ogni nodo con il comando "rosrun homework name_node" , eseguire prima il node3 dopo il node1 e per ultimo il node2.

The three nodes communicate through messages. First, node1 registers for the topic "dato" and publishes the string each second.
Then,node2 registers for the topic "comando" and prints a possible choices in menù.
In the end, node3 registers for the topic "dato" and "comando", and, after receiving the command and the string, it prints the selected choice.
Node3 and node2 register for another topic in order to allow the synchronization of the menù print.

I Tre nodi comunicano tra loro attraverso dei messaggi. Inizialmente il node1 si iscrive al topi "dato" e pubblica ogni secondo la stringa, subito dopo il node2 si iscrive al topic "comando" e stampa a video un menù delle scelte possibili, infine il node3 si iscrive sia al topic "dato" che a quello "comando" e dopo aver ricevuto il comando e la stringa stampa la scelta effettuata.
Il node3 e il node2 si iscrivono ad un ulteriore topic "menu" per permettere la sincronizzazione della stampa del menù.





