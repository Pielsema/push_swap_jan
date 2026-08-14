/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pielsema <pielsema@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:36:48 by jsobotka          #+#    #+#             */
/*   Updated: 2026/08/14 16:27:21 by pielsema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define SIMPLE   1
# define MEDIUM   2
# define COMPLEX  3
# define ADAPTIVE 4
# define OP_SA 0
# define OP_SB 1
# define OP_SS 2
# define OP_PA 3
# define OP_PB 4
# define OP_RA 5
# define OP_RB 6
# define OP_RR 7
# define OP_RRA 8
# define OP_RRB 9
# define OP_RRR 10

# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}				t_stack;

typedef struct s_options
{
	int		mode;
	int		debug;
	int		bench;
}				t_options;

typedef struct s_bench
{
	int		enabled;
	double	disorder;
	char	*strategy;
	char	*complexity;
	int		ops[11];
}				t_bench;

typedef struct s_app
{
	t_stack		*a;
	t_stack		*b;
	t_bench		bench;
	t_options	options;
}				t_app;

void		adaptive_sort(t_stack **a, t_stack **b, t_bench *bench);
void		sort_stack(t_stack **a, t_stack **b, int mode, t_bench *bench);
void		parse_options(int *argc, char ***argv, t_options *options);
int			parse_debug(int *argc, char **argv);
int			parse_bench(int *argc, char **argv);
int			parse_mode(int *argc, char ***argv);
void		init_bench(t_bench *bench, t_options *options, t_stack *a);
void		count_op(t_bench *bench, int op);
void		emit_op(t_bench *bench, int op);
char		*op_name(int op);
void		print_bench(t_bench *bench);
int			total_ops(t_bench *bench);

t_stack		*ft_lstnew_stack(int value);
t_stack		*ft_lstlast_stack(t_stack *head);
void		ft_lstadd_front_stack(t_stack **stack, t_stack *new);
void		ft_lstadd_back_stack(t_stack **stack, t_stack *new);
void		print_stack(t_stack *head, int fd);
int			ft_lstsize_stack(t_stack *head);
void		stack_alloc_error(t_stack **stack, char **args, int argc);

void		ft_error(char *msg);
void		ft_check_args(int argc, char **argv);
int			is_sorted(t_stack *stack);
int			get_distance(t_stack **stack, int index);
void		free_stack(t_stack **stack);
void		ft_free_array(char **str);
double		compute_disorder(t_stack *a);

void		radix_sort(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
int			get_min(t_stack **stack, int val);
void		simple_sort(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
int			sort_four_special(t_stack **a, t_bench *bench);
void		sort_two(t_stack **a, t_bench *bench);
void		sort_three(t_stack **a, t_bench *bench);
void		sort_four(t_stack **a, t_stack **b, t_bench *bench);
void		sort_five(t_stack **a, t_stack **b, t_bench *bench);
void		index_stack(t_stack **stack);
int			max_index(t_stack *stack);
void		chunk_sort(t_stack **a, t_stack **b, t_bench *bench);
void		push_back(t_stack **a, t_stack **b, t_bench *bench);
int			find_position(t_stack *stack, int index);
void		almost_sorted(t_stack **a, t_stack **b, t_bench *bench);
int			find_min_pos(t_stack *stack);
void		move_min_to_top(t_stack **a, t_bench *bench);
void		simple_generico(t_stack **a, t_stack **b, t_bench *bench);
int			is_almost_sorted(t_stack *a);

int			swap(t_stack **stack);
int			push(t_stack **stack_to, t_stack **stack_from);
int			rotate(t_stack **stack);
int			reverse_rotate(t_stack **stack);

int			sa(t_stack **stack_a, t_bench *bench);
int			sb(t_stack **stack_b, t_bench *bench);
int			ss(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
int			pa(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
int			pb(t_stack **stack_b, t_stack **stack_a, t_bench *bench);
int			ra(t_stack **stack_a, t_bench *bench);
int			rb(t_stack **stack_b, t_bench *bench);
int			rr(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
int			rra(t_stack **stack_a, t_bench *bench);
int			rrb(t_stack **stack_b, t_bench *bench);
int			rrr(t_stack **stack_a, t_stack **stack_b, t_bench *bench);

#endif
