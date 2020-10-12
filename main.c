/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 15:58:43 by mhori             #+#    #+#             */
/*   Updated: 2020/09/13 01:10:36 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int			check_file_name(char *s)
{
	char *tmp;

	tmp = ft_substr(s, ft_strlen(s) - 3, 3);
	if (ft_strncmp(tmp, ".rt", 3) == 0)
	{
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}

void		check_vector_norm(double *v)
{
	if (vec_norm(v) == 0)
		err_exit(ERR_VECTOR_N);
}

void		create_images(t_objs *objs)
{
	int i;

	objs->mlx = mlx_init();
	objs->mlx_win =
		mlx_new_window(objs->mlx, objs->r.x, objs->r.y, "window");
	i = 0;
	while (i < objs->num[h("C")])
	{
		objs->img[i] =
			mlx_new_image(objs->mlx, objs->r.x, objs->r.y);
		objs->addr =
			mlx_get_data_addr(objs->img[i], &objs->bpp, \
			&objs->line, &objs->endian);
		objs->c_num = i;
		ft_mlx(objs, i);
		i++;
	}
}

int			main(int argc, char *argv[])
{
	t_objs		objs;

	objs = (t_objs){0};
	if (argc < 2 || argc > 3)
		err_exit(ERR_WRONG_NUMBER_ARGUMENT_N);
	if (check_file_name(argv[1]) == 0)
		err_exit(ERR_INVALID_FILE_N);
	if (argc == 3 && (ft_strncmp(argv[2], "--save", 6) != 0
		|| ft_strlen(argv[2]) != 6))
		err_exit(ERR_WRONG_OPTION_N);
	input_data(argv[1], &objs);
	if (is_out_of_range(objs) == 1)
		err_exit(ERR_OUT_OF_RANGE_N);
	if (objs.rac != 1)
		err_exit(ERR_RAC_N);
	if (objs.error == 1)
		err_exit(ERR_WRONG_INPUT_N);
	if (objs.num[h("c")] == 0)
		err_exit(ERR_NO_CAMERA_N);
	create_images(&objs);
	if (argc == 2)
		start_window(objs);
	if (argc == 3)
		start_bmp(objs);
	return (0);
}