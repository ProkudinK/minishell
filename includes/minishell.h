/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:00:30 by wtalea            #+#    #+#             */
/*   Updated: 2019/07/25 14:39:51 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <termios.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"
# include <dirent.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <sys/signal.h>
# include <sys/stat.h>
# include <termios.h>

# define SIZECH(x) sh_is_unicode(x)
# define LEN_ES 4

struct s_tree		*g_tree;

typedef union		u_ch
{
	int				n;
	signed char		c[4];
}					t_ch;

typedef struct		s_sh_int
{
	int				pos;
	int				len;
	int				size;
}					t_sh_int;

typedef struct		s_tree
{
	char			symbol;
	struct s_tree	*left;
	struct s_tree	*down;
	char			*path;
}					t_tree;

typedef struct		s_auts
{
	int				cols;
	int				rows;
	char			flag;
}					t_auts;

typedef struct		s_parse
{
	char			**agv;
	int				agc;
	struct s_parse	*next;
}					t_parse;

enum				e_escape
{
	LEFT = 0x445B1B,
	RIGHT = 0x435B1B,
	UP = 0x415B1B,
	DOWN = 0x425B1B
};

signed char			getch(void);
int					sh_is_ascii(t_ch ch);
int					sh_is_comm(t_ch ch);
int					sh_is_unicode(char c);
int					sh_getch(void);
void				sh_sd_left(char *ch, int *pos, int *len);
void				sh_right(int *pos, int len);
void				sh_left(int *pos);
int					sh_escape(void);
void				printf_escape(int *pos, int len, int n);
void				sh_ic(int n, char **ch, t_sh_int *lengths);
int					sh_size_pos(char *ch, int pos);
void				sh_rewrite(int size, int pos, int len, char *ch);
int					start_shell(char **ch, char ***g_env);

/*
**Auto
*/
void				sh_print_auto(char **ch, t_sh_int *lens);

/*
**read_programm
*/
void				initialize_cmd(char *env, t_tree **tree);

/*
**Parsing
*/
void				start_parse(char *str, t_parse **parse);

/*
**Lexer
*/
void				start_lexer(t_parse **parse, char ***g_env);
char				*search_bucks(char *str, char ***g_env);
char				*lexer_split(char *str1, int len1, char *str2, char *str3);
void				replace_dol(char **str, int *b, char ***g_env);
void				replace_tilda(char **str, int *b);
void				search_bucks_dop(char *str, char **result,
					int len, char ***g_env);
void				replace_tilda_path(char **str, int *b, char ***g_env);

/*
**Exec
*/
char				*sh_find_prog(char *str, int len);
void				start_programm(t_parse *parse, char ***g_env);
char				*sh_str_path_split(char *str1, char *str2);

/*
**env
*/
void				add_env(char *var, char *con, char ***g_env);
char				**search_env(char *var, char ***g_env);
int					env_len(char ***g_env);
void				env_del_split(int len, char ***g_env);
void				env_del(char *var, char ***g_env);
int					sh_equal_len(char *str);

/*
**prog
*/
void				start_cd(t_parse *parse, char ***g_env);
void				start_exit(t_parse *parse);
void				start_setenv(t_parse *parsem, char ***g_env);
void				start_env(t_parse *parse, char ***g_env);
void				start_unsetenv(t_parse *parse, char ***g_env);
void				start_echo(t_parse *parse);

/*
**Signal
*/
void				sh_signal(int signo);

/*
**Quotes
*/
void				del_quotes(t_parse **parse);

/*
**sh_input
*/
void				sh_back(char **c, t_sh_int *lens);
void				sh_sigint(char **c, t_sh_int *lens);
void				sh_check_enter(char *c, char ***g_env);
void				sh_read_unicode(t_ch *ch);
int					sh_escape_check(int *esch, int len);
int					es_full_check(int n, int len, int *esch);
int					sh_spos(char *ch, int pos);

/*
**init_env
*/
void				fill_tree(char *cmd, char *path, t_tree **tree);
void				initialize_env(char **env, char ***min_env, t_tree **tree);
void				open_dir(char *path, t_tree **tree);
void				del_tree(t_tree **tree);
void				sh_lstdel(t_parse **alst);
void				check_dot(char **pwd, char *env, char *envt);

/*
**lib
*/
void				del_double_memdel(char ***dstr);

#endif
