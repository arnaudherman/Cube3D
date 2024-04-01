#include "cub3d.h"

// Fonction pour mettre à jour la position du joueur
void update_player_position(t_player *player, char **map, int map_width, int map_height)
{
    // Mettez à jour la position du joueur en fonction des entrées utilisateur
    // Par exemple, si la touche "W" est enfoncée, déplacez le joueur vers le haut, etc.
}

// Fonction pour dessiner le joueur sur l'image MLX
void draw_player(t_data *img, t_player *player)
{
    // Dessinez le joueur à sa position actuelle sur l'image MLX
    // Vous pouvez utiliser my_mlx_pixel_put ou d'autres fonctions de dessin
    my_mlx_pixel_put(img, (int)player->x_pos_px, (int)player->y_pos_px, 0x00FF0000); // Par exemple, dessinez un pixel rouge pour représenter le joueur
}

// Fonction pour écouter les événements clavier
int key_hook(int keycode, void *param)
{
    t_player *player = (t_player *)param;

    // Mettez à jour la position du joueur en fonction de la touche enfoncée
    // Par exemple, si la touche "W" est enfoncée, déplacez le joueur vers le haut
    // Vous pouvez utiliser mlx_key_hook pour attacher cette fonction à votre fenêtre MLX
}