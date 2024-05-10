#include "cub3d-bis.h"

int ray_color(int distance)
{
	 // Couleur de départ et de fin pour le dégradé
    int color_start = 0xffd55c; // Jaune
    int color_end = 0xffff80; // Vert

	// Calculer le dégradé de couleur en fonction de la distance
    int red = ((color_start >> 16) & 0xFF) * (1 - distance / RAY_LENGTH) + ((color_end >> 16) & 0xFF) * (distance / RAY_LENGTH);
    int green = ((color_start >> 8) & 0xFF) * (1 - distance / RAY_LENGTH) + ((color_end >> 8) & 0xFF) * (distance / RAY_LENGTH);
    int blue = (color_start & 0xFF) * (1 - distance / RAY_LENGTH) + (color_end & 0xFF) * (distance / RAY_LENGTH);
    int color = (red << 16) | (green << 8) | blue;
	return (color);
}