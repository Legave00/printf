/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ydorene <ydorene@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/01/17 16:13:41 by ydorene		   #+#	#+#			 */
/*   Updated: 2021/01/25 23:28:01 by ydorene		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	char	*p = "erwgvwe";

	ft_printf("%---s" ,"abcdef");
	write(1, "\n\n", 2);
	//printf("%0-0-0-00-s" ,"abcdef");
	
	//printf("\n\n\n%d\n", printf("hello, %s.", NULL));

	//printf("\n%s\n", ft_itoa(43567));
    //sleep(100);
	return 0;
}