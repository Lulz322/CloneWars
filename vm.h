#ifndef VM_H
# define VM_H

#define ERROR(ex) {printf("%s\n", ex);exit(0);}
#define _SET_CHAMP(ex) {ft_strcat(ex, chmp); return ;}

enum	e_bool { false, true } __attribute__((packed));

# define _BOOL	typedef enum e_bool bool

_BOOL;

typedef struct s_champ_first
{
	char name[255];
	//char commnet[255];
}t_champ_first;

typedef struct s_champ_second
{
	char name[255];
	//char commnet[255];
}t_champ_second;

typedef struct s_champ_third
{
	char name[255];
	//char commnet[255];
}t_champ_third;

typedef struct s_champ_fourth
{
	char name[255];
	//char commnet[255];
}t_champ_fourth;


typedef struct s_flags
{
	bool flag_n;
	bool flag;
};

typedef struct s_general
{
	struct s_champ_first f_champ;
	struct s_champ_second s_champ;
	struct s_champ_third t_champ;
	struct s_champ_fourth fh_champ;
	struct s_flags flags;
}				t_gen;

t_gen g_gen;
#endif
