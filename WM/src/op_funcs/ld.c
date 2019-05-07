#include "../../includes/vm.h"

void				ld(t_kareta *kareta)
{
	int32_t	value;
	int32_t	reg;

	kareta->step += OP_LEN + ARG_LEN;
	_LD;
	reg = st.field[find_adress(kareta->pos + kareta->step)];
	_LD2;
}
