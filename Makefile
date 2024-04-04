NAME = push_swap
NAME1 = checker

CC = cc -fsanitize=address -g3

CFLAGS = -Wall -Wextra -Werror 

SRC = push_swap.c sort_smalls.c actions1.c find_cost_index.c ft_parsing.c \
    a_to_b.c b_to_a.c actions2.c actions3.c free_exit.c min_max_index.c \
    libft/ft_split.c libft/ft_atoi.c libft/ft_lstsize_bonus.c \
    libft/ft_lstnew_bonus.c libft/ft_lstlast_bonus.c \
    libft/ft_isdigit.c libft/ft_lstadd_back_bonus.c libft/ft_isalpha.c \
    libft/ft_strlen.c libft/ft_strdup.c libft/ft_substr.c \

BONUSF = bonus/checker_bonus.c bonus/ft_parcing1_bonus.c bonus/moves1_bonus.c \
    bonus/moves2_bonus.c bonus/moves3_bonus.c bonus/free_stacks_bonus.c \
    libft/ft_strncmp.c get_next_line/get_next_line.c libft/ft_lstnew_bonus.c \
    get_next_line/get_next_line_utils.c libft/ft_split.c libft/ft_atoi.c \
    libft/ft_lstsize_bonus.c libft/ft_lstlast_bonus.c \
    libft/ft_isdigit.c libft/ft_lstadd_back_bonus.c libft/ft_isalpha.c \
    libft/ft_strlen.c libft/ft_strdup.c libft/ft_substr.c libft/ft_strchr.c \

OBJ = $(SRC:.c=.o)

BONUSO = $(BONUSF:.c=.o)

all: $(NAME)

bonus: $(NAME1)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
    
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME1): $(BONUSO)
	$(CC) $(CFLAGS) -o $(NAME1) $(BONUSO)

clean:
	rm -rf $(OBJ) $(BONUSO)

fclean: clean
	rm -rf $(NAME) $(NAME1)

re: fclean all
