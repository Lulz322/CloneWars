#ifndef VM_H
# define VM_H

#include <stdio.h>
#include <stdlib.h>
#include "op.h"
#include "../libft/includes/libft.h"

#define ERROR(ex) {printf("%s\n", ex);exit(0);}
#define _SET_CHAMP(ex) {ft_strcat(ex, chmp); return ;}
#define _READ_CHAMP(ex, name) {read_champ(ex,name);return ;}


enum	e_bool { false, true } __attribute__((packed));

# define _BOOL	typedef enum e_bool bool

_BOOL;

typedef struct s_champ
{
	int32_t magic_header;
	char name[255];
	char comment[255];
}				t_champ;


typedef struct s_general
{
	struct s_champ champ[4];
}				t_gen;

t_gen g_gen;

void read_champ(int a, char *file_name);
#endif
