# SFML-FloconKoch
Test de la librairie SFML avec C++ afin de jouer avec des fractales, notamment le flocon de Koch. 

# Principe Mathématique (à peaufiner)

On partira d'une figure composer de plusieurs segments. A chaque itération de notre algorithme, chaque segment sera découpé en 3 parties égales et deux nouveaux segments seront créés pour former un triangle équilatéral. 

Graphiquement, on part du segment AB si dessous (qui est orienté selon un angle quelconque).
![KOCH_LI](https://user-images.githubusercontent.com/57157757/143775276-51eddd29-80cf-4ed9-bf39-fce3fee921b9.jpg)

Et on calculera les coordonnées des points C, D et E. 

Les points C et D sont facilement trouvés:

Avec  A(Ax,Ay), B(Bx, By), C(Cx,Cy) et D(Dx, Dy)

Cx = Ax + (Bx - Ax) / 3
Cy = Ay + (By - Ay) / 3

Dx = Ax + 2 * (Bx - Ax) / 3
Dy = Ay + 2 * (By - Ay) / 3

On fait la projection de nos points sur l'axe des abscisses que l'on fait ici démarrer à A. On peut ainsi calculer nos Cx et Dx. 

![KOCH_LI](https://user-images.githubusercontent.com/57157757/143775989-efd0a3b8-fda1-41a1-a19b-ff9e2cfb0f65.jpg)

Pour Cy et Dy, on fait la même chose mais avec une projection sur l'axe des ordonnées.

Pour le calcule de E les choses deviennent plus compliqués. Nous sommes obligés de faire tourner CD autour de C juqu'à arriver à notre point E. 
Je n'ai pas réussi à le trouver par moi-même (Ouch, je sais). Je vous laisse avec ça https://math.stackexchange.com/questions/1687901/how-to-rotate-a-line-segment-around-one-of-the-end-points

![image](https://user-images.githubusercontent.com/57157757/143775138-0aaaa46e-cd8b-4dfb-9a00-963108797600.png)


On aurait également pu ne pas utiliser les coordonnées de nos points pour construire nos segments mais utiliser un point de repère, une longueur et un angle.
J'ai choisi de construire mes segments avec leurs points car cela me sembler plus facile à dessiner en utilisant SFML.

Pour la prochaine fois je pense que je passerai direct par OpenGL plutôt que SFML. 


# Résultat final

Dans mon programme je fait varier ma variable niveau de 0 à 8 (à automatiser, c'est pas pratique de devoir recompiler à chaque fois)

Itération 0: C'est la forme de base que je donne à mon algorithme, ici un triangle équilatéral

![image](https://user-images.githubusercontent.com/57157757/143776382-f90a0102-4ec9-4abb-8578-35bf1282a328.png)

Itération 1:

![image](https://user-images.githubusercontent.com/57157757/143776398-6a7cbd60-de62-4ff9-b6d4-30fccdc5f5f9.png)

Itération 2:

![image](https://user-images.githubusercontent.com/57157757/143776415-6c99c31e-1dce-4e3e-a57a-0f6e5478df64.png)

Itération 3:

![image](https://user-images.githubusercontent.com/57157757/143776440-f7d64f00-ea12-4c28-b250-081c22ba0406.png)

Itération 4:

![image](https://user-images.githubusercontent.com/57157757/143776464-ba6a2bc4-0cc5-49b9-a5a8-c8b818457791.png)

Itération 5:

![image](https://user-images.githubusercontent.com/57157757/143776475-14412fd3-631b-49df-bb19-9ae99cb5b4b4.png)

Itération 8: Dernière itération avant que le programme plante

![image](https://user-images.githubusercontent.com/57157757/143724163-174e42c3-517c-406e-ad92-365f4ff90ffa.png)


# Comment lancer le programme depuis votre PC ? (à faire, j'ai fait un peu nimp dans ce repo de test)

