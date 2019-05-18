/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:16:48 by dlenskyi          #+#    #+#             */
/*   Updated: 2019/05/15 17:16:50 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"

/*
** ERRORS
*/

# define RD_ERR ("Unable to get data from argument!\n")
# define ST_CMD_ERR ("Starting command is too long")
# define DCM_ERR ("Unable to complete recoding!\n")
# define QUOTE_ERR ("Better put ending quote for name or comment!")
# define LANG_ERR ("Wrong lexeme in (")
# define INPUT_ERR ("Incorrect input!\n")
# define UMRK_ERR ("Marker unknown ")
# define UMRK_ERR_2 (" during lexeme's processing \"")
# define CMT_ERR ("Comment of champion exceeds characters' limit of ")
# define NAME_ERR ("Name of champion exceeds characters' limit of ")
# define RES ("Placing champion in file ")
# define USAGE ("./asm: Try `./asm --help` for more information.\n")
# define BWD_REV dir_bwd = (dir_bwd << 8)
# define SYMBOL_CHARS		":%,.-+"
# define BWD_REV dir_bwd = (dir_bwd << 8)
# define EOL write (1, "\n", 1)

short					show_message(char *txt);
short					show_cmt_name_limit(int x);
void					show_mistake(char *msg);
short int				show_details(char *txt);
short					take_option(char *word);
long					provide_source(char *object, int mode);

struct					s_case
{
	short				ac;
	short				k;
	short				code_set;
};

struct					s_disp
{
	long				display;
	long				get;
	short				z;
	char				s;
	short				i;
	char				*txt;
};

struct					s_nodes
{
	void				*object;
	ssize_t				sz_obj;
	struct s_nodes		*after;

};

typedef struct			s_np
{
	char				mn;
	char				pl;
	short				neg_pos;
}						t_np;

typedef	enum
{
	true,
	false,
}	t_boolean;

t_boolean				check_option(char *cmd, short int mode);
t_boolean				check_num_in_str(char *txt, short int mode);
t_boolean				check_reg(char *cmd, short int mode);

size_t					make_backwards_2(unsigned int x);
size_t					make_backwards_1(unsigned int x);

short					add_node_end(struct s_nodes **start_list,
									struct s_nodes *moded_list);

struct s_nodes			*create_linked_nodes(void *obj_src, size_t sz_src);

char					*validate_arg_title(char *title, size_t mode);
short					if_safe_marker(short int a);

struct					s_flag
{
	int					name;
	int					cmt;
	int					flag;
	char				name_tmp[PROG_NAME_LENGTH + 4];
	char				cmt_tmp[COMMENT_LENGTH + 4];
	int					dsm;
	int					orig;
};
short					error_mem_release(void);

short					mem_release(const char *s, struct s_flag *flg);

struct					s_hold
{
	char				*type;
	char				*result;
	char				*t;
	unsigned			k;
	int					c1;
	int					c2;
	short int			res;
};

struct					s_dcm
{
	long				display;
	long				get;
	long				bz;
	long				mode;
	long				r;
};

struct					s_lbs
{
	long				ord_num;
	char				*cmd_cm;
	long				border;
	long				k;
	char				*kind;
	char				*cmd_nm;
	long				get;
	long				display;
	short				result;
};

/*
** TOKENIZER
*/

enum					e_kind
{
	Invalid = -1,
	No_mode = 0,
	Num,
	Eol,
	Cmt,
	Option,
	Str,
	Reg,
	Symbol,
	Space,
	Marker,
};

short					check_sp_and_eol(enum e_kind k);

struct					s_lexeme
{
	char				string[COMMENT_LENGTH + 1];
	long				row;
	long				column;
	enum e_kind			kind;
};

struct s_lexeme			tokenizer(int fd);

/*
** LOADER
*/

struct s_param			load_param_indir(long get, struct s_lexeme *lxm,
						struct s_param param);
struct s_param			load_param_dir(long get, struct s_lexeme *lxm,
						short code_set, struct s_param param);

struct					s_param
{
	char				kind;
	long				val;
	long				sz;
};

struct					s_load
{
	long				display;
	long				get;
	int					amount;
	short				res;
};

void					check_name_cmt(struct s_flag *flg,
									struct s_lexeme *lexeme);

short					skip_all_spaces(long get, struct s_lexeme *lxm);
short					read_handle_markers(long get, struct s_lexeme *lxm);

short					print_starting_commands(long display, int *amount,
												struct s_flag *flg);
short					validate_starting_commands(long get,
							struct s_lexeme *lxm, struct s_flag *flg);
short					load_code_set(long get, long display,
						struct s_lexeme *lxm, short code_set);

short					run_assemble(char *input_name, char *output_name,
									struct s_flag *flg);

/*
** MARKER
*/

struct					s_ptr
{
	long				ord_num;
	struct s_nodes		*mrk;
};

short					find_neg_pos(short *neg_pos, struct s_lexeme *l);
struct s_param			param_dir_picking(long get, struct s_lexeme *lexeme,
										short code_set, struct s_param param);
struct s_param			param_indir_picking(long get, struct s_lexeme *lxm,
											struct s_param param);

struct s_ptr			*load_markers(int z);
struct s_ptr			*load_markers_work(int z);
long int				marker_title(char *title, int i);
long					place_marker(char *title, int ident);
long					marker_num(char *name);

short					validate_name_cmt(long get, struct s_lexeme *lxm,
									struct s_flag *flg);
struct s_param			handle_args(long get, struct s_lexeme *lxm,
						short code_set);
short					pick_set_of_codes(long get, int *value,
						struct s_lexeme *lxm, short op);
short					create_marker_list(short z, long get, int *amount,
									struct s_flag *flg);

/*
** READER
*/

struct					s_txt
{
	long				row;
	char				x;
	long				column;
};

long					handle_spaces(long get, struct s_lexeme *lxm);
void					lang_mistake(struct s_lexeme lxm);

/*
** DECOMPILER
*/

short					load_bwd(long get, long display);
short int				load_bwd_starting (long get, long display);
short					make_recoding(char *input_name, char *output_name);

void					bwd_comb_handler(struct s_disp d, size_t actnum,
										size_t res, int mode);
void					bwd_load_oct_handler(long get, long display,
												size_t actnum);
void					bwd_load_else_handler(long get, long display,
												size_t actnum);

void					state_machine(struct s_txt *smb, int file_index);
short					is_cmt(char x);
t_boolean				spacing_check(char x);
struct s_txt			handle_whitespace(struct s_lexeme *lxm,
									struct s_txt smb, int file_index);
ssize_t					display_static(long num_data, void *storage,
									size_t bt_count);
size_t					get_into_2(long num_data);
size_t					get_into_1(long num_data);

typedef struct			s_op
{
	char				*name;
	unsigned char		nb_arg;
	t_arg_type			args[3];
	unsigned char		code_set;
	unsigned int		cycle;
	char				*info;
	unsigned char		octal;
	unsigned char		marker;
}						t_op;

long					find_param_sz(t_op g_op_tab);
struct s_param			parse_arg(long get, struct s_lexeme *lxm,
						short code_set);

extern	t_op			g_op_tab[17];

#endif
