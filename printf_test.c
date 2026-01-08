// Simple tester: same exact format strings for printf and ft_printf,
// so return values should match (except UB cases).

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

static void	sep(const char *title)
{
	printf("\n================ %s ================\n", title);
}

static void	ret_pair(int sys, int ft)
{
	printf("printf return   : %d\n", sys);
	printf("ft_printf return: %d\n", ft);
}

int	main(void)
{
	int		ret_sys;
	int		ret_ft;
	int		x = 42;
	char	*null_str = NULL;

	sep("%");
	printf("System printf output (UB):\n");
	printf("%", "PF");
	ft_printf("ft_printf output (should not crash):\n");
	ft_printf("%", "FT_PF");
	ret_pair(ret_sys, ret_ft);

	sep("Control");
	ret_sys = printf("abc\n");
	ret_ft = ft_printf("abc\n");
	ret_pair(ret_sys, ret_ft);

	sep("Basic sanity");
	ret_sys = printf("Hello, world!\n");
	ret_ft = ft_printf("Hello, world!\n");
	ret_pair(ret_sys, ret_ft);

	sep("Percent");
	ret_sys = printf("[%%]\n");
	ret_ft = ft_printf("[%%]\n");
	ret_pair(ret_sys, ret_ft);

	sep("%c normal");
	ret_sys = printf("A[%c]B\n", 'Z');
	ret_ft = ft_printf("A[%c]B\n", 'Z');
	ret_pair(ret_sys, ret_ft);

	sep("%c NUL (counts in return)");
	ret_sys = printf("A[%c]B (NUL)\n", '\0');
	ret_ft = ft_printf("A[%c]B (NUL)\n", '\0');
	ret_pair(ret_sys, ret_ft);

	sep("%s empty");
	ret_sys = printf("[%s]\n", "");
	ret_ft = ft_printf("[%s]\n", "");
	ret_pair(ret_sys, ret_ft);

	sep("%s NULL");
	ret_sys = printf("[%s]\n", null_str);
	ret_ft = ft_printf("[%s]\n", null_str);
	ret_pair(ret_sys, ret_ft);

	sep("%p stack ptr");
	ret_sys = printf("[&x=%p]\n", (void *)&x);
	ret_ft = ft_printf("[&x=%p]\n", (void *)&x);
	ret_pair(ret_sys, ret_ft);

	sep("%p NULL");
	ret_sys = printf("[NULL=%p]\n", (void *)0);
	ret_ft = ft_printf("[NULL=%p]\n", (void *)0);
	ret_pair(ret_sys, ret_ft);

	sep("%d / %i extremes");
	ret_sys = printf("[%d] [%i] [%d] [%d]\n", 0, -1, INT_MAX, INT_MIN);
	ret_ft = ft_printf("[%d] [%i] [%d] [%d]\n", 0, -1, INT_MAX, INT_MIN);
	ret_pair(ret_sys, ret_ft);

	sep("%u extremes");
	ret_sys = printf("[%u] [%u] [%u]\n", 0u, 42u, (unsigned int)-1);
	ret_ft = ft_printf("[%u] [%u] [%u]\n", 0u, 42u, (unsigned int)-1);
	ret_pair(ret_sys, ret_ft);

	sep("%x / %X extremes");
	ret_sys = printf("[%x] [%x] [%X] [%X]\n", 0u, UINT_MAX, 0u, UINT_MAX);
	ret_ft = ft_printf("[%x] [%x] [%X] [%X]\n", 0u, UINT_MAX, 0u, UINT_MAX);
	ret_pair(ret_sys, ret_ft);

	sep("Mixed conversions");
	ret_sys = printf("c=%c s=%s p=%p d=%d i=%i u=%u x=%x X=%X %%\n",
			'A', "mix", (void *)&x, -42, 42, 3000000000u, 48879u, 48879u);
	ret_ft = ft_printf("c=%c s=%s p=%p d=%d i=%i u=%u x=%x X=%X %%\n",
			'A', "mix", (void *)&x, -42, 42, 3000000000u, 48879u, 48879u);
	ret_pair(ret_sys, ret_ft);

	sep("Tight packing");
	ret_sys = printf("[%s%s%s]\n", "", "A", "");
	ret_ft = ft_printf("[%s%s%s]\n", "", "A", "");
	ret_pair(ret_sys, ret_ft);

	ret_sys = printf("[%d%d%d]\n", 0, -1, 1);
	ret_ft = ft_printf("[%d%d%d]\n", 0, -1, 1);
	ret_pair(ret_sys, ret_ft);

	sep("Many NULs");
	ret_sys = printf("[%c%c%c]\n", '\0', '\0', '\0');
	ret_ft = ft_printf("[%c%c%c]\n", '\0', '\0', '\0');
	ret_pair(ret_sys, ret_ft);


	ft_printf("\n");

	sep("Done");
	return (0);
}
