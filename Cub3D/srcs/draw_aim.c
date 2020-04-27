#include "cube.h"
#include <stdio.h>

void	draw_weapon(t_hud h, t_img *img)
{
	int	i;
	int	j;
	int	k;
	int	*p;

	j = 0;
	p = img->d_ptr;
	p += h.offset_y * img->size_l;
	p += h.offset;
	while (j * h.s < h.t.y)
	{
		i = 0;
		while (i  * h.s < h.t.x)
		{
			if ((k = get_txt_color(h.t, i * h.s, j * h.s)))
				*p = k;
			i++;
			p++;
		}
		p += img->size_l - i;
		j++;
	}
}

void	draw_aim(t_game g)
{
//	int	i;
//	int	j;
	t_img	t;

	t = g.txt[6];
//	j = 0;
	printf("t.x : %d\tt.y : %d\n", t.x, t.y);
}
/*	while (j < g.set.res_y)
	{
		i = 0;
		while (i < g.set.res_x)
		{
			if (
*/
