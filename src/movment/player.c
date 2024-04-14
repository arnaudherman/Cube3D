#include "cub3d.h"

// Initialise la position du joueur
void init_player(t_player *player) {
    player->x_pos_px = 1;
    player->y_pos_px = 1;
    player->speed = SPEED;
    player->fov = FOV;
    player->rotate = ROTATION;
}

// Met à jour la position du joueur en fonction de la touche pressée
void update_player_position(t_player *player, int key) 
{
    // Déplacer le joueur vers le haut
    if (key == KEY_UP)
        player->y_pos_px -= player->speed;
    // Déplacer le joueur vers le bas
    else if (key == KEY_DOWN)
        player->y_pos_px += player->speed;
    // Déplacer le joueur vers la gauche
    else if (key == KEY_LEFT)
        player->x_pos_px -= player->speed;
    // Déplacer le joueur vers la droite
    else if (key == KEY_RIGHT)
        player->x_pos_px += player->speed;
}

// Fonction pour dessiner le joueur sur l'image MLX
void draw_player(void *mlx_ptr, void *win_ptr, t_player *player)
{
    // Dessiner le joueur comme un carré bleu à sa position
    int player_size = TILE_SIZE / 2; // Taille du joueur
    int player_color = 0x0000FF; // Couleur bleue

    draw_square(mlx_ptr, win_ptr, &player);
}


// Fonction pour écouter les événements du clavier
int key_hook(int key, t_player *player, t_data *data) {
    // Appeler la fonction pour mettre à jour la position du joueur en fonction de la touche pressée
    update_player_position(&player, key);
    // Rafraîchir l'affichage de la carte après avoir mis à jour la position du joueur
    draw_map(data->mlx_ptr, data->win_ptr, &player);
    return (0);
}