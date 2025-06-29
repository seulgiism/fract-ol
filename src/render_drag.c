#include "fractol_utils.h"
#include "MLX42.h"

void    drag_hook(void *param)
{
    t_render    *render = (t_render *)param;
    static int32_t   prev_x = -1;
    static int32_t   prev_y = -1;
    int32_t     x;
    int32_t     y;

    if (mlx_is_mouse_down(render->mlx, MLX_MOUSE_BUTTON_LEFT))
    {
        mlx_get_mouse_pos(render->mlx, &x, &y);
        if (prev_x != -1 && prev_y != -1)
        {
            if (x > prev_x)
                move_right(render, x - prev_x);
            else if (x < prev_x)
                move_left(render, prev_x - x);
            if (y > prev_y)
                move_down(render, y - prev_y);
            else if (y < prev_y)
                move_up(render, prev_y - y);
            render_fract(render);
        }
        prev_x = x;
        prev_y = y;
    }
    else
    {
        prev_x = -1;
        prev_y = -1;
    }
}
