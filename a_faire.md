# Parsing
- Check si il y a que des caractere autorisé
- Regarder si elle est fermer
- Check si il y a pas deux fois la meme direction
- Check si il y a des texture pour toutes les direction
- Check si elle est possible
- Check si il n'y a pas de vide en plein millieu de la map

> Si il y a une erreur, on doit mettre OBLIGATOIREMENT **"Error\n{MESSAGE D'ERREUR}"**


# Raycasting
- 70 fov

Par où commencer concrètement ?

- Parse ta map 
- charge ton fichier .cub, stocke la grille dans un tableau 2D d'entiers
- Affiche la vue 2D avec MLX (joueur + murs) → valide que la map est bien lue
- Implante le DDA, commence par afficher juste des lignes de couleur dans la vue 3D
- Gère les mouvements
- translations et rotations du joueur Texture les murs
- calcule l'offset X dans la texture selon le point d'impact du rayon