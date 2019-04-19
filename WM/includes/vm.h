#ifndef VM_H
# define VM_H

#include <stdio.h>
#include <stdlib.h>
#include "op.h"
#include "../libft/includes/libft.h"
#include "operations.h"


# define ER_START	"\033[41m"
# define ER_END		"\033[40m"
#define _ERROR(ex) {printf("%s%s%s\n",ER_START,ex,ER_END);errrorrororo();}
#define _SET_CHAMP(ex) {ft_strcat(ex, chmp); return ;}
#define _READ_CHAMP(ex, name) {read_champ(ex,name);return ;}
#define _ERR_CHAMP(ex) {if (!ex) _ERROR("Missing first champ");}
#define _SET_L(ex) {if (ex == 3){st.flag_l = true;}st.log = a;}
#define _SET_DUMP_D(ex) {if (ex == 2){st.flag_d = true;}st.flag_dump_d = a;}
#define _SET_DUMP(ex) {if (ex == 1){st.flag_dump = true;}st.flag_dump_d = a;}
#define _SET_DUMPS(ex) {_SET_DUMP(ex);_SET_DUMP_D(ex);_SET_L(ex);}
#define _DIE st.cycles_to_die
#define _AM_I_DIE _DIE == st.cycles_after_check || st.cycles_to_die <= 0
#define _FD st.flag_d
#define _VS {vs_update_stats(&st.v);vs_update_main(&st.v);}
#define _FDUMP st.flag_dump
#define _RAVNO st.flag_dump_d == st.cycles
#define _PBF if (_RAVNO && (_FD || _FDUMP)){_PRINT_B}
#define _CHECK_VISUALISATION {if (st.flag_visual == true){vs_main();}}
#define _CHECK_WAIT kareta->code >= 0x01 && kareta->code <= 0x10
#define _LOG(ex, ex1) {if (st.log == 2){logs(ex, ex1);}}
#define _PREPARE(ex) {st.cycles++;st.cycles_after_check++;ex = st.kareta;}
#define _PRINT_B2 {if (st.flag_dump)print_field(32);exit(13);}
#define _PRINT_B {if (st.flag_d){print_field(64);}_PRINT_B2;}

#define st g_gen

bool is_dat_is_a_child(int i);
void	vs_main(void);
void			errrorrororo(void);
void	check_who_die();
void	next_op(t_kareta *kareta);
void print_field(int i);
int		find_adress(int i);
int			take_op(t_kareta *kareta, uint8_t i, int mod);
void read_champ(int a, char *file_name);
int32_t		byte_to_int(int32_t addr, int32_t size);
void		int_to_byte(int32_t addr, int32_t value, int32_t size);
void		set_field(int32_t addr, uint8_t i, int32_t size);
void create_field(void);
int		count_step(uint8_t type, t_operation *oop);
int8_t	count_size(int pos, int step);
int		check_args(t_kareta *kareta, t_operation *oop);
int		validate_args(t_kareta *kareta, t_operation *oop);
void	read_argtype(t_kareta *kareta, t_operation *oop);
t_kareta	*copy_kareta(t_kareta *kareta, int32_t addr);
void add_elem(t_kareta **list, int pos);
void print_list(t_kareta *list);
void set_karetu();
void print_info_champs();
#endif
