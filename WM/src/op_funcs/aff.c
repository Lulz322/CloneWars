#include "../../includes/vm.h"

void		aff(t_kareta *kareta)
{
	int32_t	reg;
	int32_t	value;

	kareta->step += OP_LEN + ARG_LEN;
	reg = st.field[find_adress(kareta->pos + kareta->step)];
	value = kareta->reg[reg - 1];
	kareta->step += REG_LEN;
	if (st.aff && st.flag_visual)
		ft_printf("%c\n", (char)value);
}
