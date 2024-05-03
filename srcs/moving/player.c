#include "cub3d-bis.h"

void update_player_position(t_player *player, int key) 
{
    // Déplacer le joueur vers le haut
    if (key == KEY_W)
        player->y_pos -= player->speed;
    // Déplacer le joueur vers le bas
    else if (key == KEY_S)
        player->y_pos += player->speed;
    // Déplacer le joueur vers la gauche
    else if (key == LEFT_ARR)
        player->x_pos -= player->speed;
    // Déplacer le joueur vers la droite
    else if (key == RIGHT_ARR)
        player->x_pos += player->speed;
}


int key_hook(int key, t_player *player, t_data *data) {
    update_player_position(&player, key);
    draw_map(data->image, &data->map);
    return (0);
}