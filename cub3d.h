/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:13:07 by gleal             #+#    #+#             */
/*   Updated: 2021/03/05 21:46:44 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
#include <mlx.h>

# include "./libft_cub3d/libft.h"
# include "./libft_cub3d/get_next_line.h"

#define MAX_X_SIZE 2560
#define MAX_Y_SIZE 1440
#define MAP_CHARS "012NSEW"
#define MAP_INSIDE "02NSEW"
#define PLAYER "NSEW"

typedef struct	s_map
{
	int		lnbr;
	char	**text;
	int		error;
	int		rx;
	int		ry;
	char	*no_text;
	char	*so_text;
	char	*we_text;
	char	*ea_text;
	char	*sprite_text;
	int		rfloor;
	int		gfloor;
	int		bfloor;
	int		rceil;
	int		gceil;
	int		bceil;
	int		map_size;
	char	player_or;
	char	**mapstr;
}				t_map;

enum e_errors
{
	MALLOCERROR,
	MULTIRES,
	BADSCREEN,
	MULTINO,
	BADNO,
	MULTISO,
	BADSO,
	MULTIWE,
	BADWE,
	MULTIEA,
	BADEA,
	MULTISPRITE,
	BADSPRITE,
	MULTIFLOOR,
	BADFLOOR,
	MULTICEIL,
	BADCEIL,
	INVALIDMAP,
	INVALIDCHAR
};

void	*ft_freetext(char **strs);
void	*ft_realloctabs(char *str, int tab_nbr, t_map *map);
void	ft_start_tmap(t_map *map);
void	ft_new_line(t_map *map);
int		ft_countchr(char *str, char c);
void	cub_extract(t_map *map, int fd);
void	cub3d(char *cubname);
void	ft_printcub(char **cub);
int		ft_parse_cub(char **text, t_map *map);
int		ft_isspace(char c);
int		ft_error(int errornbr);
int		ft_parsenorthtext(char *str, t_map *map);
int		ft_parsesouthtext(char *str, t_map *map);
int		ft_parsewesttext(char *str, t_map *map);
int		ft_parseeasttext(char *str, t_map *map);
int		ft_parsespritetext(char *str, t_map *map);
int		ft_parsefloorcolor(char *str, t_map *map);
int		ft_parseceilcolor(char *str, t_map *map);
int		is_map(char *str);
int		checkwall(char *str);
int		playeringame(t_map *map);
int		checkmapclosed(char **strs);
int		checkmultiplayer(char *str, t_map *map);
int		check_valid_map(char **strs, t_map *map);
int		checkfirstwall(char *str);
int		ft_copy_map(char **map_start, t_map *map);
void	free_all_strs(char **strs);

#endif
