/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 14:05:43 by echatela          #+#    #+#             */
/*   Updated: 2025/10/19 12:27:22 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_par.h"
#include "sh_exp.h"

struct s_shell;

static const char *kind_str(int k)
{
	if (k == N_SIMPLE) return "SIMPLE";
	if (k == N_SUBSHELL) return "SUBSHELL";
	if (k == N_PIPELINE) return "PIPELINE";
	if (k == N_ANDOR) return "ANDOR";
	return "?";
}

static const char *op_str(int op)
{
	if (op == AO_AND) return "&&";
	if (op == AO_OR)  return "||";
	return "?";
}

static const char *rtype_str(int r)
{
	if (r == R_IN)   return "<";
	if (r == R_HDOC) return "<<";
	if (r == R_OUT)  return ">";
	if (r == R_APP)  return ">>";
	return "?";
}

static void print_indent(int depth)
{
	while (depth-- > 0) printf("  ");
}

void print_cmd(struct s_shell *sh, struct s_cmd *c, int depth)
{
	char **av = c->argv;
	struct s_redir *r = c->redv;

	(void)sh;
	print_indent(depth); printf("argv:");
	if (av) {
		for (int i = 0; av[i]; i++) printf(" [%s]", av[i]);
	}
	printf("\n");
	if (r) {
		for (int i = 0; r[i].arg && r[i].type >= 0; i++) {
			print_indent(depth);
			printf("redir: %s %s", rtype_str(r[i].type), r[i].arg);
			printf("\n");
		}
	}
}

static void print_node(struct s_shell *sh, struct s_node *n, int depth)
{
	if (!n) { print_indent(depth); printf("(null)\n"); return; }
	print_indent(depth); printf("%s", kind_str(n->kind));
	if (n->kind == N_SIMPLE) {
		printf("\n");
		print_cmd(sh, &n->u.s_simple, depth + 1);
	} else if (n->kind == N_SUBSHELL) {
		printf(" (\n");
		print_node(sh, n->u.s_subshell.list, depth + 1);
		print_indent(depth); printf(")\n");
	} else if (n->kind == N_PIPELINE) {
		printf(" n=%d\n", n->u.s_pipeline.n);
		for (int i = 0; i < n->u.s_pipeline.n; i++)
			print_node(sh, n->u.s_pipeline.v[i], depth + 1);
	} else if (n->kind == N_ANDOR) {
		printf(" op=%s\n", op_str(n->u.s_andor.op));
		print_node(sh, n->u.s_andor.lhs, depth + 1);
		print_node(sh, n->u.s_andor.rhs, depth + 1);
	} else {
		printf(" (?)\n");
	}
}

/* Appelle ceci pour imprimer l’AST complet */
void ast_print(struct s_shell *sh, struct s_node *root)
{
	print_node(sh, root, 0);
}