#ifndef VM_H
# define VM_H

#include <stdio.h>
#include <stdlib.h>
#include "op.h"
#include "../libft/includes/libft.h"

# define ER_START	"\033[41m"
# define ER_END		"\033[40m"

#define ERROR(ex) {printf("%s%s%s\n",ER_START,ex,ER_END);exit(0);}
#define _SET_CHAMP(ex) {ft_strcat(ex, chmp); return ;}
#define _READ_CHAMP(ex, name) {read_champ(ex,name);return ;}
#define _ERR_CHAMP(ex) {if (!ex) ERROR("Missing first champ");}
#define st g_gen

enum	e_bool { false, true } __attribute__((packed));

# define _BOOL	typedef enum e_bool bool

_BOOL;

typedef struct s_kareta
{
	unsigned int id;
	bool carry;
	uint8_t code;
	int last_alive;
	int reg[REG_NUMBER];
	int pos;
	int l_step;
	struct s_kareta *next;
} t_kareta;

typedef struct s_champ
{
	char file_name[255];
	bool hard_set;
	char name[255];
	char comment[255];
	int length;
	uint8_t *algo;
}				t_champ;


typedef struct s_general
{
	t_champ champ[4];
	uint8_t field[MEM_SIZE];
	t_kareta *kareta;
}				t_gen;

t_gen g_gen;

void read_champ(int a, char *file_name);
void create_field(void);
void add_elem(t_kareta **list, int pos);
void print_list(t_kareta *list);
void set_karetu();
void print_info_champs();
#endif
