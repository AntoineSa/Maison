#include "cube.h"

static void	init_life_hud(t_game *g, t_hud *hud)
{
	hud->offset = g->set.res_x / 10;
	hud->offset_y = g->set.res_y / 50;
	hud->offset = g->set.res_x - (hud->offset + hud->offset / 9);
	hud->t = g->txt[7];
	hud->s = (float)hud->t.y / (float)hud->offset_y;
}

static void	init_stamina_hud(t_game *g, t_hud *hud)
{
	hud->offset = g->set.res_x / 10;
	hud->offset_y = g->set.res_y / 50;
	hud->offset = g->set.res_x - (hud->offset + hud->offset / 9);
	hud->t = g->txt[8];
	hud->s = (float)hud->t.y / (float)hud->offset_y;
	hud->offset_y *= 3;
}

static void	init_weapon_hud(t_game *g, t_hud *hud)
{
	hud->offset = (g->set.res_x - hud->t.x) / 2;
	hud->offset_y = g->set.res_y - hud->t.y;
	hud->t = g->txt[5];
	hud->s = (float)hud->t.y / (float)hud->offset_y;
}

static void	init_aim_hud(t_game *g, t_hud *hud)
{
	hud->offset = 0;
	hud->offset_y = 0;
	hud->t = g->txt[6];
	if (g->set.res_x > g->set.res_y)
		hud->s = (float)hud->t.y / g->set.res_y;
	else
		hud->s = (float)hud->t.x / g->set.res_x;
}

void		init_hud(t_game *g)
{
	init_life_hud(g, &g->hud[0]);
	init_stamina_hud(g, &g->hud[1]);
	init_weapon_hud(g, &g->hud[2]);
	init_aim_hud(g, &g->hud[3]);
}
