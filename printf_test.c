
// This file tests 42 printf exercises.

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"


static void	print_sep(const char *title)
{
	printf("\n================ %s ================\n", title);
}

static void	print_ret(const char *who, int ret)
{
	printf("%s return: %d\n", who, ret);
}

int	main(void)
{
	int		ret_sys;
	int		ret_ft;
	int		x;
	char	*null_str;

	x = 42;
	null_str = NULL;

    ret_sys = printf("abc");
    printf("\n");
    ret_ft = ft_printf("abc");
    printf("\n");
    print_ret("printf", ret_sys);
	print_ret("ft_printf", ret_ft);

	print_sep("0) Basic sanity");
	ret_sys = printf("printf: Hello, world!\n");
	ret_ft = ft_printf("ft_printf: Hello, world!\n");
	print_ret("printf", ret_sys);
	print_ret("ft_printf", ret_ft);

	print_sep("1) Percent edge cases");
	ret_sys = printf("printf: [%%]\n");
	ret_ft = ft_printf("ft_printf: [%%]\n");
	print_ret("printf", ret_sys);
	print_ret("ft_printf", ret_ft);

	/* Undefined behavior in real printf: "%" alone.
	   We include it to ensure you DON'T crash.
	   Your output/return may differ from system printf. */
	ret_ft = ft_printf("ft_printf (should not crash): [%]\n");
	print_ret("ft_printf", ret_ft);

	print_sep("2) %c including NUL char");
	ret_sys = printf("printf: A[%c]B\n", 'Z');
	ret_ft = ft_printf("ft_printf: A[%c]B\n", 'Z');
	print_ret("printf", ret_sys);
	print_ret("ft_printf", ret_ft);

	/* NUL char test: it won't "show", but return value must count it */
	ret_sys = printf("printf: A[%c]B (NUL)\n", '\0');
	ret_ft = ft_printf("ft_printf: A[%c]B (NUL)\n", '\0');
	print_ret("printf", ret_sys);
	print_ret("ft_printf", ret_ft);

	print_sep("3) %s edge cases (empty, NULL)");
	ret_sys = printf("printf: [%s]\n", "");
	ret_ft = ft_printf("ft_printf: [%s]\n", "");
	print_ret("printf", ret_sys);
	print_ret("ft_printf", ret_ft);

	ret_sys = printf("printf: [%s]\n", null_str);
	ret_ft = ft_printf("ft_printf: [%s]\n", null_str);
	print_ret("printf", ret_sys);
	print_ret("ft_printf", ret_ft);

	print_sep("4) %p edge cases (stack ptr, NULL)");
	ret_sys = printf("printf: [&x=%p]\n", (void *)&x);
	ret_ft = ft_printf("ft_printf: [&x=%p]\n", (void *)&x);
	print_ret("printf", ret_sys);
	print_ret("ft_printf", ret_ft);

	ret_sys = printf("printf: [NULL=%p]\n", (void *)0);
	ret_ft = ft_printf("ft_printf: [NULL=%p]\n", (void *)0);
	print_ret("printf", ret_sys);
	print_ret("ft_printf", ret_ft);

	print_sep("5) %d / %i extremes");
	ret_sys = printf("printf: [%d] [%i] [%d] [%d]\n", 0, -1, INT_MAX, INT_MIN);
	ret_ft = ft_printf("ft_printf: [%d] [%i] [%d] [%d]\n", 0, -1, INT_MAX, INT_MIN);
	print_ret("printf", ret_sys);
	print_ret("ft_printf", ret_ft);

	print_sep("6) %u wrap and extremes");
	ret_sys = printf("printf: [%u] [%u] [%u]\n", 0u, 42u, (unsigned int)-1);
	ret_ft = ft_printf("ft_printf: [%u] [%u] [%u]\n", 0u, 42u, (unsigned int)-1);
	print_ret("printf", ret_sys);
	print_ret("ft_printf", ret_ft);

	print_sep("7) %x / %X extremes");
	ret_sys = printf("printf: [%x] [%x] [%X] [%X]\n", 0u, UINT_MAX, 0u, UINT_MAX);
	ret_ft = ft_printf("ft_printf: [%x] [%x] [%X] [%X]\n", 0u, UINT_MAX, 0u, UINT_MAX);
	print_ret("printf", ret_sys);
	print_ret("ft_printf", ret_ft);

	print_sep("8) Mixed conversions (common failure zone)");
	ret_sys = printf("printf: c=%c s=%s p=%p d=%d i=%i u=%u x=%x X=%X %%\n",
			'A', "mix", (void *)&x, -42, 42, 3000000000u, 48879u, 48879u);
	ret_ft = ft_printf("ft_printf: c=%c s=%s p=%p d=%d i=%i u=%u x=%x X=%X %%\n",
			'A', "mix", (void *)&x, -42, 42, 3000000000u, 48879u, 48879u);
	print_ret("printf", ret_sys);
	print_ret("ft_printf", ret_ft);

	print_sep("9) Tight packing (no spaces) + empties");
	ret_sys = printf("printf: [%s%s%s]\n", "", "A", "");
	ret_ft = ft_printf("ft_printf: [%s%s%s]\n", "", "A", "");
	print_ret("printf", ret_sys);
	print_ret("ft_printf", ret_ft);

	ret_sys = printf("printf: [%d%d%d]\n", 0, -1, 1);
	ret_ft = ft_printf("ft_printf: [%d%d%d]\n", 0, -1, 1);
	print_ret("printf", ret_sys);
	print_ret("ft_printf", ret_ft);

	print_sep("10) Many NULs (return value torture)");
	ret_sys = printf("printf: [%c%c%c]\n", '\0', '\0', '\0');
	ret_ft = ft_printf("ft_printf: [%c%c%c]\n", '\0', '\0', '\0');
	print_ret("printf", ret_sys);
	print_ret("ft_printf", ret_ft);

	print_sep("11) Done");
	return (0);
}
