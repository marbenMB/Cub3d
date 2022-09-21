SRCS =  ft_isalpha.c \
		ft_isalnum.c \
		ft_bzero.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memcpy.c \
		ft_memset.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_strlcat.c \
		ft_memmove.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_strcmp.c \


BONUS_SRCS = 	ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \

NAME = libft.a

CC = cc

CFlAGS = -Wall -Wextra -Werror

OBJECT = $(SRCS:.c=.o)

BONUS_OBJECT = $(BONUS_SRCS:.c=.o)

%.o:%.c
	@$(CC) $(CFlAGS) -c $<  -o  $@

all : $(NAME)

$(NAME) : $(OBJECT)
	@ar rc $(NAME) $(OBJECT)

bonus : $(OBJECT) $(BONUS_OBJECT)
	@ar rc $(NAME) $(OBJECT) $(BONUS_OBJECT)

clean :
	@rm -f $(OBJECT) $(BONUS_OBJECT)
fclean : clean
	@rm -f $(NAME)
re : fclean all

.PHONY : clean fclean all re bonus
