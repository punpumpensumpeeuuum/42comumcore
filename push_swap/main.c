/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:17:24 by dinda-si          #+#    #+#             */
/*   Updated: 2024/03/25 23:59:02 by elemesmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// void	printa(t_list *current)
// {
// 	int i = 0;
// 	while (current)
// 	{
// 		ft_printf("Node %d -> %d\n",i ,(current)->content);
// 		current = current->next;
// 		i++;
// 	}
// }

void	init(int argc, t_stack *stack)
{
	stack->head = NULL;
	stack->size = argc - 1;
}

int	nocasodeserstring(int argc, char **argv, t_stack *a)
{
	int	n;
	int	i;

	i = 0;
	if (!checknumb(argc, argv))
		return (0);
	argv = ft_split(argv[1], ' ');
	while (argv[i])
	{
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
			return (0);
		n = ft_atoi(argv[i]);
		if (!checkdup(a->head, n))
			ft_lstadd_back(&a->head, ft_lstnew(n));
		else
			return (0);
		i++;
	}
	argvfree(argv, argc);
	return (1);
}

int	getnumbers(int argc, char **argv, t_stack *a)
{
	int	i;
	int	n;

	i = 1;
	if (!checknumb(argc, argv))
		return (0);
	while (i < argc)
	{
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
			return (0);
		n = ft_atoi(argv[i]);
		if (!checkdup(a->head, n))
			ft_lstadd_back(&a->head, ft_lstnew(n));
		else
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	init(argc, &a);
	init(argc, &b);
	if (argc == 2 && !nocasodeserstring(argc, argv, &a))
	{
		ft_printf("Error\n");
		listfree(&(&a)->head);
		return (0);
	}
	if (argc > 2 && !getnumbers(argc, argv, &a))
	{
		ft_printf("Error\n");
		listfree(&(&a)->head);
		return (0);
	}
	if (!checknext((&a)->head))
	{
		if (ft_lstsize((&a)->head) == 3 || ft_lstsize((&a)->head) == 2)
			sort3(&(&a)->head);
		else
			sort_tudo(&(&a)->head, &(&b)->head);
	}
	listfree(&(&a)->head);
}
