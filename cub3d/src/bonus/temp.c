/*

void	drawline(t_cub3d *game, t_vectord start, t_vectord end, int color)
{
    int dx = end.x - (start.x * 100 + 50);
    int dy = end.y - (start.y * 100 + 50);
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;
    float X = start.x * 100 + 50;
    float Y = start.y * 100 + 50;
    for (int i = 0; i <= steps; i++)
    {
		my_mlx_pixel_put(game->img, X, Y, color);
        X += Xinc;
        Y += Yinc;
    }
}

void	drawsquare(t_cub3d *game, double x, double y, int color)
{
	int	_x;
	int	_y;
	int	i;
	int	j;

	if (color == 0)
	{
		_x = x * 100;
		_x -=50;
		i = _x + 100;
		while (_x < i)
		{
			_y = y * 100;
			_y -=50;
			j = _y + 100;
			while (_y < j)
			{
				my_mlx_pixel_put(game->img, _x + 50, _y + 50, color);
				_y++;
			}
			_x++;
		}
		return ;
	}
}

*/
