# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttran <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/19 14:55:54 by ttran             #+#    #+#              #
#    Updated: 2018/01/19 14:55:59 by ttran            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = grimly
SRCS_DIR = ./srcs/
INCLUDES = ./includes/
RM = /bin/rm -f

FILES = grimly dup_check
CFILES = $(patsubst %, $(SRCS_DIR)%.c, $(FILES))
OFILES = $(patsubst %, %.o, $(FILES))
CFLAGS = -Wall -Wextra -Werror

#libft
LFT = ./libft/
LFT_LIB = $(addprefix $(LFT), ft.a)
LFT_INC = -I $(LFT)
LFT_LINK = -L $(LFT) -l ft

all: $(LFT_LIB) $(NAME)

$(OFILES):
	@gcc $(CFLAGS) -c -I$(INCLUDES) $(LFT_INC) $(CFILES)

$(LFT_LIB):
	@make -C $(LFT)

$(NAME): $(OFILES)
	@gcc $(CFLAGS) $(OFILES) $(LFT_LINK) -o $(NAME)

clean:
	@make -C $(LFT) clean
	@$(RM) $(OFILES)

fclean: clean
	@make -C $(LFT) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re