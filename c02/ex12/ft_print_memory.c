/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 04:33:17 by jshin             #+#    #+#             */
/*   Updated: 2021/09/25 21:43:37 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void	*ft_print_memory(void *addr, unsigned int size);
void ft_putstr(char* p)
{
	write(1, p, strlen(p));
}
#include <unistd.h>

void	ft_putchar(unsigned char	c)
{
	write(1, &c, 1);
}

void	ft_put_addr(unsigned char	*addr)
{
	int				i;
	unsigned char	ch[16];

	i = 0;
	while (*addr > 0)
	{
		if ((*addr % 16) >= 10)
			ch[i] = ((*addr % 16) - 10 + 'a');
		else
			ch[i] = ((*addr % 16) + '0');
		*addr /= 16;
		i++;
	}
	while (i < 16)
	{
		ch[i] = '0';
		i++;
	}
	while (i >= 0)
	{
		i--;
		ft_putchar(ch[i]);
	}
	write(1, &": ", 2);
}

void	ft_puthex(unsigned char	*addr, int	print_size)
{
	int	i;

	i = 0;
	while (i < print_size)
	{
		if (addr[i] / 16 >= 10)
			ft_putchar(addr[i] / 16 - 10 + 'a');
		else
			ft_putchar(addr[i] / 16 + '0');
		if (addr[i] % 16 >= 10)
			ft_putchar(addr[i] % 16 - 10 + 'a');
		else
			ft_putchar(addr[i] % 16 + '0');
		i++;
		if (i % 2 == 0)
			write(1, &" ", 1);
	}
}

void	ft_printstr(void	*addr, int	print_size)
{
	int				i;
	unsigned char	*char1;

	if (print_size < 16)
	{
		if (print_size % 2 == 1)
			write(1, " ", 1);
		i = 0;
		while (i++ < 16 - print_size)
		{
			write(1, " ", 2);
			if (i % 2 == 0)
				write(1, " ", 1);
		}
	}
	i = 0;
	char1 = (unsigned char *)addr;
	while (i < print_size)
	{
		if (char1[i] < 32 || char1[i] >= 127)
			ft_putchar('.');
		else
			ft_putchar(char1[i]);
		i++;
	}
}

void	*ft_print_memory(void	*addr, unsigned int	size)
{
	int				off;
	unsigned char	*ptr;

	off = 0;
	ptr = (unsigned char *)addr;
	while (size > 0)
	{
		ft_put_addr(ptr + off);
		if (size >= 16)
		{
			ft_puthex(ptr + off, 16);
			ft_printstr(ptr + off, 16);
			size -= 16;
		}
		else
		{
			ft_puthex(ptr + off, size);
			ft_printstr(ptr + off, size);
			size = 0;
		}
		write(1, &"\n", 1);
		off += 16;
	}
	return (addr);
}
int main(void)
{
	char mem[] = {
		0x42, 0x6f, 0x6e, 0x6a, 0x6f, 0x75, 0x72, 0x20, 0x6c, 0x65, 0x73, 0x20, 0x61, 0x6d, 0x69, 0x6e,
		0x63, 0x68, 0x65, 0x73, 0x09, 0x0a, 0x09, 0x63, 0x20, 0x20, 0x65, 0x73, 0x74, 0x20, 0x66, 0x6f,
		0x75, 0x09, 0x74, 0x6f, 0x75, 0x74, 0x09, 0x63, 0x65, 0x20, 0x71, 0x75, 0x20, 0x6f, 0x6e, 0x20,
		0x70, 0x65, 0x75, 0x74, 0x20, 0x66, 0x61, 0x69, 0x72, 0x65, 0x20, 0x61, 0x76, 0x65, 0x63, 0x09,
		0x0a, 0x09, 0x70, 0x72, 0x69, 0x6e, 0x74, 0x5f, 0x6d, 0x65, 0x6d, 0x6f, 0x72, 0x79, 0x0a, 0x0a,
		0x0a, 0x09, 0x6c, 0x6f, 0x6c, 0x2e, 0x6c, 0x6f, 0x6c, 0x0a, 0x20, 0x00, 0x72, 0x79, 0x0a, 0x0a,
		0x0a, 0x09, 0x6c, 0x6f, 0x6c, 0x2e, 0x6c, 0x6f, 0x6c, 0x0a, 0x20, 0x00, 0x72, 0x79, 0x0a, 0x0a,
		0x0a, 0x09, 0x6c, 0x6f, 0x6c, 0x2e, 0x6c, 0x6f, 0x6c, 0x0a, 0x20, 0x00, 0x72, 0x79, 0x0a, 0x0a,
		0x0a, 0x09, 0x6c, 0x6f, 0x6c, 0x2e, 0x6c, 0x6f, 0x6c, 0x0a, 0x20, 0x00 };

	for (int i = 0; i < 140; i++)
	{
		char buffer[64];
		sprintf(buffer, "\n-[%d]--------------------\n", i);
		ft_putstr(buffer);
		void *r = ft_print_memory(mem, i);
		if (mem != r)
		{
			ft_putstr("Error: ret addr check is failed!!!\n");
			return 1;
		}
		usleep(50000);
	}
	return 0;
}

