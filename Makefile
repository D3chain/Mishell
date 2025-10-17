# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: garivoir <garivoir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/05 12:02:13 by echatela          #+#    #+#              #
#    Updated: 2025/10/17 15:19:26 by garivoir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	minishell
CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror -g3
SRC_DIR		:=	src
OBJ_DIR		:=	build
LIBFT_DIR	:=	libft
INC_DIRS	:=	include $(LIBFT_DIR)
CFLAGS		+=	$(addprefix -I,$(INC_DIRS))

SUBDIRS		:=	core lexer parser expand exec builtins env err utils

CORE_SRCS		:=	repl.c signals.c print_tree.c
LEXER_SRCS		:=	lexer.c tok.c
PARSER_SRCS		:=	parser.c par_cmd.c free_tree.c
EXPAND_SRCS		:=	expand.c exp_var.c exp_wc.c exp_unquote.c
BUILTINS_SRCS	:=	pwd.c cd.c echo.c env.c exit.c export.c unset.c
EXEC_SRCS		:=	exe_run.c exe_pipeline.c exe_simple.c exec_command.c redir.c here_doc.c exe_path.c exe_builtin.c
ENV_SRCS		:=	env_create_list.c env_utils.c env_new.c
ERR_SRCS		:=	error.c fill.c
UTIL_SRCS		:=	char.c vec.c vec_free.c str_builder.c exit_utils.c

ROOT_SRCS		:=	main.c

SRC_NAMES	:= \
	$(addprefix core/,$(CORE_SRCS)) \
	$(addprefix lexer/,$(LEXER_SRCS)) \
	$(addprefix parser/,$(PARSER_SRCS)) \
	$(addprefix expand/,$(EXPAND_SRCS)) \
	$(addprefix builtins/,$(BUILTINS_SRCS)) \
	$(addprefix exec/,$(EXEC_SRCS)) \
	$(addprefix env/,$(ENV_SRCS)) \
	$(addprefix error/,$(ERR_SRCS)) \
	$(addprefix util/,$(UTIL_SRCS)) \
	$(ROOT_SRCS)

SRCS		:=	$(addprefix $(SRC_DIR)/,$(SRC_NAMES))

OBJS		:=	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

DEPS		:=	$(OBJS:.o=.d)

LIBFT		:=	$(LIBFT_DIR)/libft.a

.PHONY:	all clean fclean re test

all:	$(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR) bonus

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@ \
		-lreadline

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean:		clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	
re: fclean all

test: all
	@valgrind \
	--leak-check=full \
	--show-leak-kinds=all \
	--trace-children=yes \
	--track-fds=yes \
	--suppressions=./.minishell.supp \
 	--log-file=valgrind.log \
	./minishell
	@echo "\n"
	@cat valgrind.log
	@rm -f valgrind.log
