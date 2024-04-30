#include "cub3d-bis.h"

t_keys	*keys_struct_init(void)
{
	t_keys *keys;

	if (!(keys = (t_keys *)malloc(sizeof(t_keys))))
		return (NULL);
	keys->w = 0;
	keys->a = 0;
	keys->s = 0;
	keys->d = 0;
	keys->esc = 0;
	keys->left = 0;
	keys->right = 0;
	return (keys);
}
