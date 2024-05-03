#include "cub3d-bis.h"

// // Met à jour la position du joueur en fonction de la touche pressée
// void update_player_position(t_player *player, int key) 
// {
//     // Déplacer le joueur vers le haut
//     if (key == KEY_UP)
//         player->y_pos -= player->speed;
//     // Déplacer le joueur vers le bas
//     else if (key == KEY_DOWN)
//         player->y_pos += player->speed;
//     // Déplacer le joueur vers la gauche
//     else if (key == KEY_LEFT)
//         player->x_pos -= player->speed;
//     // Déplacer le joueur vers la droite
//     else if (key == KEY_RIGHT)
//         player->x_pos += player->speed;
// }


// // Fonction pour écouter les événements du clavier
// int key_hook(int key, t_player *player, t_data *data) {
//     // Appeler la fonction pour mettre à jour la position du joueur en fonction de la touche pressée
//     update_player_position(&player, key);
//     // Rafraîchir l'affichage de la carte après avoir mis à jour la position du joueur
//     draw_map(data->mlx_ptr, data->win_ptr, &player);
//     return (0);
// }