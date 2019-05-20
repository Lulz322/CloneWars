/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 12:20:38 by iruban            #+#    #+#             */
/*   Updated: 2019/05/14 12:20:39 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H
# define OP_LEN 1
# define ARG_LEN 1
# define REG_LEN 1

# include <ncurses.h>
# include "vm.h"

/*
** enum	e_bool { false, true } __attribute__((packed));
** # define _BOOL	typedef enum e_bool bool
** _BOOL;
*/

typedef struct		s_kareta
{
	unsigned int	id;
	int				pos;
	int				step;
	int				living;
	bool			carry;
	uint8_t			code;
	int				last_alive;
	int				reg[REG_NUMBER];
	int				argc_types[3];
	int				wait;
	struct s_kareta	*next;
}					t_kareta;

typedef struct		s_champ
{
	char			file_name[255];
	bool			hard_set;
	char			*name;
	char			*comment;
	int				length;
	int				last_alive;
	int				live;
	uint8_t			*algo;
}					t_champ;

typedef struct		s_vis
{
	int				y;
	int				x;
	WINDOW			*main;
	WINDOW			*stat;
}					t_vis;

typedef struct		s_general
{
	t_champ			champ[4];
	t_vis			v;
	uint8_t			field[MEM_SIZE];
	int				v_field[MEM_SIZE];
	t_kareta		*kareta;
	ssize_t			cycles_to_die;
	ssize_t			cycles;
	ssize_t			cycles_after_check;
	ssize_t			check_in;
	ssize_t			live_in;
	int				last_alive;
	int				log;
	int				aff;
	int				am_champs;
	int				am_karet;
	bool			flag_dump;
	bool			flag_d;
	bool			flag_visual;
	bool			f_p;
	bool			sounds;
	bool			flag_l;
	int				flag_l_d;
	int				flag_dump_d;
}					t_gen;

t_gen	g_gen;

void				live(t_kareta *kareta);
void				ld(t_kareta *kareta);
void				op_st(t_kareta *kareta);
void				add(t_kareta *kareta);
void				sub(t_kareta *kareta);
void				and(t_kareta *kareta);
void				or(t_kareta *kareta);
void				xor(t_kareta *kareta);
void				zjmp(t_kareta *kareta);
void				ldi(t_kareta *kareta);
void				sti(t_kareta *kareta);
void				op_fork(t_kareta *kareta);
void				lld(t_kareta *kareta);
void				lldi(t_kareta *kareta);
void				lfork(t_kareta *kareta);
void				aff(t_kareta *kareta);

typedef struct		s_operation
{
	char			*name;
	uint8_t			code;
	uint8_t			args_num;
	int				args_types_code;
	uint8_t			args_types[3];
	bool			is_carry;
	uint8_t			t_dir_size;
	int				cycles;
	void			(*func)(t_kareta *);
}					t_operation;

static				t_operation	g_op[16] = {
	{
		.name = "live",
		.code = 0x01,
		.args_num = 1,
		.args_types_code = 0,
		.args_types = {T_DIR, 0, 0},
		.is_carry = false,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &live
	},
	{
		.name = "ld",
		.code = 0x02,
		.args_num = 2,
		.args_types_code = 1,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.is_carry = true,
		.t_dir_size = 4,
		.cycles = 5,
		.func = &ld
	},
	{
		.name = "st",
		.code = 0x03,
		.args_num = 2,
		.args_types_code = 1,
		.args_types = {T_REG, T_REG | T_IND, 0},
		.is_carry = false,
		.t_dir_size = 4,
		.cycles = 5,
		.func = &op_st
	},
	{
		.name = "add",
		.code = 0x04,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG, T_REG, T_REG},
		.is_carry = true,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &add
	},
	{
		.name = "sub",
		.code = 0x05,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG, T_REG, T_REG},
		.is_carry = true,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &sub
	},
	{
		.name = "and",
		.code = 0x06,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.is_carry = true,
		.t_dir_size = 4,
		.cycles = 6,
		.func = &and
	},
	{
		.name = "or",
		.code = 0x07,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.is_carry = true,
		.t_dir_size = 4,
		.cycles = 6,
		.func = &or
	},
	{
		.name = "xor",
		.code = 0x08,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.is_carry = true,
		.t_dir_size = 4,
		.cycles = 6,
		.func = &xor
	},
	{
		.name = "zjmp",
		.code = 0x09,
		.args_num = 1,
		.args_types_code = 0,
		.args_types = {T_DIR, 0, 0},
		.is_carry = false,
		.t_dir_size = 2,
		.cycles = 20,
		.func = &zjmp
	},
	{
		.name = "ldi",
		.code = 0x0A,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.is_carry = false,
		.t_dir_size = 2,
		.cycles = 25,
		.func = &ldi
	},
	{
		.name = "sti",
		.code = 0x0B,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
		.is_carry = false,
		.t_dir_size = 2,
		.cycles = 25,
		.func = &sti
	},
	{
		.name = "fork",
		.code = 0x0C,
		.args_num = 1,
		.args_types_code = 0,
		.args_types = {T_DIR, 0, 0},
		.is_carry = false,
		.t_dir_size = 2,
		.cycles = 800,
		.func = &op_fork
	},
	{
		.name = "lld",
		.code = 0x0D,
		.args_num = 2,
		.args_types_code = 1,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.is_carry = true,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &lld
	},
	{
		.name = "lldi",
		.code = 0x0E,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.is_carry = true,
		.t_dir_size = 2,
		.cycles = 50,
		.func = &lldi
	},
	{
		.name = "lfork",
		.code = 0x0F,
		.args_num = 1,
		.args_types_code = 0,
		.args_types = {T_DIR, 0, 0},
		.is_carry = false,
		.t_dir_size = 2,
		.cycles = 1000,
		.func = &lfork
	},
	{
		.name = "aff",
		.code = 0x10,
		.args_num = 1,
		.args_types_code = 1,
		.args_types = {T_REG, 0, 0},
		.is_carry = false,
		.t_dir_size = 4,
		.cycles = 2,
		.func = &aff
	}
};

static uint8_t			g_arg_code[3] = {
	T_REG,
	T_DIR,
	T_IND
};

#endif
