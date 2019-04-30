#ifndef VM_H
# define VM_H

#include <stdio.h>
#include <stdlib.h>
#include "op.h"
#include "../libft/includes/libft.h"
#include "operations.h"
#include "vis.h"


# define ER_START	"\033[41m"
# define ER_END		"\033[40m"
# define _ERROR_MALLOC(ex) if(!(ex)) {_ERROR("ERROR IN ALLOCATION MEMMORY")};
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
#define _READING(ex, ex2) if(ex) {_ERROR(ex2);}
#define _SET_OOP(ex) ex = st.field[kareta->pos];
#define _CWAIT(ex) ex = g_op[kareta->code - 1].cycles;
#define _POOP st.field[kareta->pos] >= 0x01 && st.field[kareta->pos] <= 0x10
#define _VS {if (st.flag_visual){vs_update_stats(&st.v);vs_update_main(&st.v);}}
#define _FDUMP st.flag_dump
#define _RAVNO st.flag_dump_d == st.cycles
#define _PBF if (_RAVNO && (_FD || _FDUMP)){_PRINT_B}
#define _CHECK_VISUALISATION {if (st.flag_visual == true){vs_main();}_VS;}
#define _CHECK_WAIT kareta->code >= 0x01 && kareta->code <= 0x10
#define _LOG(ex, ex1) {if (st.log == 2){logs(ex, ex1);}}
#define _PREPARE(ex) {st.cycles++;st.cycles_after_check++;ex = st.kareta;}
#define _PRINT_B2 {if (st.flag_dump)print_field(32);exit(13);}
#define _PRINT_B {if (st.flag_d){print_field(64);}_PRINT_B2;}
#define _CHECKSSS st.check_in == MAX_CHECKS || st.live_in >= NBR_LIVE
#define _CYCLE_D {st.cycles_to_die -= CYCLE_DELTA;st.check_in = 0;}
#define _IS_CYCLE if  (_CHECKSSS){_CYCLE_D}
#define _ZERO {	st.live_in = 0;	st.cycles_after_check = 0;}
#define _REGO reg = st.field[find_adress(pos + step)];
#define _PREP_ARGC {i = 0;step = (1 + (oop->args_types_code ? 1 : 0));}
#define _LIVE {id = take_op(kareta, 1, 0);st.live_in++;champ = NULL;}
#define _LIVE2 {champ = &st.champ[id - 1];champ->last_alive = st.cycles;}
#define _LIVE3 {champ->live++;st.last_alive = id - 1;}
#define _LD {value = take_op(kareta, 1, 1);kareta->carry = !value;}
#define _LD2 {kareta->reg[reg - 1] = value;kareta->step += REG_LEN;}
#define _ST {i = kareta->reg[reg - 1];kareta->step += REG_LEN;}
#define _ST1 {kareta->reg[addr - 1] = i;kareta->step += REG_LEN;}
#define _SSST {addr = st.field[find_adress(kareta->pos + kareta->step)];_ST1;}
#define _AD1 kareta->step += REG_LEN;
#define _ADD(ex) {ex = st.field[find_adress(kareta->pos + kareta->step)];_AD1}

#define st g_gen

int 	karettta(int i);
bool is_dat_is_a_child(int i);
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
bool	check_args(t_kareta *kareta, t_operation *oop);
bool	validate_args(t_kareta *kareta, t_operation *oop);
void	read_argtype(t_kareta *kareta, t_operation *oop);
t_kareta	*copy_kareta(t_kareta *kareta, int32_t addr);
void add_elem(t_kareta **list, int pos);
void print_list(t_kareta *list);
void set_karetu();
void logs(int i, int d);
void 	parsing_argc(int argc, char **argv);
int check_where(char *where);
void swap(t_champ *first, t_champ *second);
void print_info_champs();
void	print_last_alive();
void print_player_code();
void jason_born(void);
void set_death(void);
void set_music(void);
void kill_sounds(void);
int32_t	bytecode_to_int32(uint8_t *bytecode, int size);
#endif
