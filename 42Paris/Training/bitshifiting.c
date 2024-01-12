/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitshifiting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 09:44:31 by whamdi            #+#    #+#             */
/*   Updated: 2023/12/16 10:14:41 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010"*/
#include <unistd.h>
void	print_bits(unsigned int octet)
{
	unsigned char bit;
	int i = 8;
	while(i--)
	{
		bit = ((octet >>i &1) + '0');
		write(1,&bit,1);
	}
	
}

int	main(){
	print_bits(97);
}

