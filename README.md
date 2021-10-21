## Navy

# Subject:

You must code a terminal version of the famous battleship game. The two players are ONLY allowed to comunicate using the signals SIGUSER1 and SIGUSER2 in C. The map size is 8x8. On each turn, you must display your positions, and then your enemy’s positions. At the end of the game (when all the ships of a player have been hit), you must display whether “I won” or “Enemy won”.

# Usage:

  - make re (If you don't have Make : sudo dnf install make automake gcc gcc-c++ kernel-devel)
  - ./navy [first_player_pid] navy_positions
  - first_player_pid: only for the 2nd player. navy_positions: file representing the positions of the ships (found in maps/)

# Exemple:

  - first terminal: ./navy maps/my_navy.txt
  - second terminal: ./navy [first_player_pid] maps/my_navy2.txt

# Unit Test for the Navy Project:

This is a first year project at EPITECH and there is unit tests where everything is tested except the signals part.

Coverage :
      
      - Lines : 55.3%
      - Branches : 61%

![navycover](https://user-images.githubusercontent.com/72025226/138266413-e6b15e4d-b1af-4d48-9be3-69be19c20b2c.jpeg)

# Score:

100% at Epitech Mouli

![navytest](https://user-images.githubusercontent.com/72025226/138267128-5e791a3e-931d-4c80-9f0c-7c7839cc171a.jpeg)
