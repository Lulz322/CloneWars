#ifndef OPERATIONS_H
#define OPERATIONS_H
# define OP_LEN 1
# define ARG_LEN 1
# define REG_LEN 1

#include <ncurses.h>
#include "vm.h"

/*
enum	e_bool { false, true } __attribute__((packed));

# define _BOOL	typedef enum e_bool bool

_BOOL;
*/
typedef struct s_kareta
{
	unsigned int id;
	int pos;
	int step;
	bool carry;
	uint8_t code;
	int last_alive;
	int reg[REG_NUMBER];
	int argc_types[3];
	int wait;
	struct s_kareta *next;
} 	t_kareta;

typedef struct s_champ
{
	char file_name[255];
	bool hard_set;
	char *name;
	char *comment;
	int length;
	int last_alive;
	int live;
	uint8_t *algo;
}				t_champ;

typedef struct	s_vis
{
	int			y;
	int			x;
	WINDOW		*main;
	WINDOW		*stat;
}				t_vis;


typedef struct s_general
{
	t_champ champ[4];
	t_vis	v;
	uint8_t field[MEM_SIZE];
	int		v_field[MEM_SIZE];
	t_kareta *kareta;
	ssize_t cycles_to_die;
	ssize_t cycles;
	ssize_t cycles_after_check;
	ssize_t check_in;
	ssize_t live_in;
	int last_alive;
	int log;
	int aff;
	int am_champs;
	int am_karet;
	bool flag_dump;
	bool flag_d;
	bool flag_visual;
	bool flag_l;
	int flag_l_d;
	int	flag_dump_d;
}				t_gen;

t_gen g_gen;

void	vs_update_stats(t_vis *v);

void				op_live(t_kareta *kareta);
void				op_ld(t_kareta *kareta);
void				op_st(t_kareta *kareta);
void				op_add(t_kareta *kareta);
void				op_sub(t_kareta *kareta);
void				op_and(t_kareta *kareta);
void				op_or(t_kareta *kareta);
void				op_xor(t_kareta *kareta);
void				op_zjmp(t_kareta *kareta);
void				op_ldi(t_kareta *kareta);
void				op_sti(t_kareta *kareta);
void				op_fork(t_kareta *kareta);
void				op_lld(t_kareta *kareta);
void				op_lldi(t_kareta *kareta);
void				op_lfork(t_kareta *kareta);
void				op_aff(t_kareta *kareta);

typedef struct		s_operation
{
	char			*name;
	uint8_t			code;
	uint8_t			args_num;
	int				args_types_code;
	uint8_t			args_types[3];
	int				modify_carry;
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
		.modify_carry = 0,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &op_live
	},
	{
		.name = "ld",
		.code = 0x02,
		.args_num = 2,
		.args_types_code = 1,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 5,
		.func = &op_ld
	},
	{
		.name = "st",
		.code = 0x03,
		.args_num = 2,
		.args_types_code = 1,
		.args_types = {T_REG, T_REG | T_IND, 0},
		.modify_carry = 0,
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
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &op_add
	},
	{
		.name = "sub",
		.code = 0x05,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG, T_REG, T_REG},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &op_sub
	},
	{
		.name = "and",
		.code = 0x06,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 6,
		.func = &op_and
	},
	{
		.name = "or",
		.code = 0x07,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 6,
		.func = &op_or
	},
	{
		.name = "xor",
		.code = 0x08,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 6,
		.func = &op_xor
	},
	{
		.name = "zjmp",
		.code = 0x09,
		.args_num = 1,
		.args_types_code = 0,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = 0,
		.t_dir_size = 2,
		.cycles = 20,
		.func = &op_zjmp
	},
	{
		.name = "ldi",
		.code = 0x0A,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.modify_carry = 0,
		.t_dir_size = 2,
		.cycles = 25,
		.func = &op_ldi
	},
	{
		.name = "sti",
		.code = 0x0B,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
		.modify_carry = 0,
		.t_dir_size = 2,
		.cycles = 25,
		.func = &op_sti
	},
	{
		.name = "fork",
		.code = 0x0C,
		.args_num = 1,
		.args_types_code = 0,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = 0,
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
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &op_lld
	},
	{
		.name = "lldi",
		.code = 0x0E,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.modify_carry = 1,
		.t_dir_size = 2,
		.cycles = 50,
		.func = &op_lldi
	},
	{
		.name = "lfork",
		.code = 0x0F,
		.args_num = 1,
		.args_types_code = 0,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = 0,
		.t_dir_size = 2,
		.cycles = 1000,
		.func = &op_lfork
	},
	{
		.name = "aff",
		.code = 0x10,
		.args_num = 1,
		.args_types_code = 1,
		.args_types = {T_REG, 0, 0},
		.modify_carry = 0,
		.t_dir_size = 4,
		.cycles = 2,
		.func = &op_aff
	}
};

static uint8_t			g_arg_code[3] = {
	T_REG,
	T_DIR,
	T_IND
};

#endif
