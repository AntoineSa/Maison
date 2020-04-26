#include "cube.h"
#include <stdio.h>

void	draw_weapon(t_game g, t_hud h)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	g.img.d_ptr += h.offset_y * g.img.size_l;
	g.img.d_ptr += h.offset;
	while (j * h.s < h.t.y)
	{
		i = 0;
		while (i  * h.s < h.t.x)
		{
			if ((k = get_txt_color(h.t, i * h.s, j * h.s)))
				*(g.img.d_ptr) = k;
			i++;
			g.img.d_ptr++;
		}
		g.img.d_ptr += g.img.size_l - i;
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
