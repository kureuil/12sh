##
## Makefile for Makefile in /home/rius_b/rendu/Piscine_C_J11/lib/my
## 
## Made by brendan rius
## Login   <rius_b@epitech.net>
## 
## Started on  Mon Oct 20 08:51:07 2014 brendan rius
## Last update Sun May 24 00:09:16 2015 Brendan Rius
##

CP	= cp
CFLAGS	+= -Wextra -Wall
CFLAGS	+= -pedantic
CFLAGS	+= -std=c99 -g
CFLAGS	+= -Wno-unused-result
CFLAGS	+= -I ./inc/

NAME	= libmy

SRCS_BTREES	= btrees/destroy.c \
		btrees/get.c \
		btrees/get_tree.c \
		btrees/init.c \
		btrees/new.c \
		btrees/set.c \
		btrees/set_tree.c \
		btrees/root.c \
		btrees/iterator_dfr.c \
		btrees/iterator_dfl.c

SRCS_VECTOR	= vector/destroy.c \
		vector/empty.c \
		vector/filter.c \
		vector/foreach.c \
		vector/from.c \
		vector/init.c \
		vector/map.c \
		vector/new.c \
		vector/pop.c \
		vector/push.c \
		vector/last.c \
		vector/iterator.c \
		vector/serialize.c

SRCS_DICT	= dictionnary/dictionnary.c \
		dictionnary/dictionnary_utils.c \
		dictionnary/dictionnary_get_entries.c \
		dictionnary/dictionnary_length.c

SRCS_HTABLE	= hashtable/hashtable.c \
		hashtable/ht_hash.c \
		hashtable/ht_new.c \
		hashtable/ht_dict_set.c \
		hashtable/ht_dict_get.c \
		hashtable/ht_dict_remove.c \
		hashtable/ht_dict_destroy.c \
		hashtable/ht_dict_get_entries.c \
		hashtable/ht_dict_length.c \
		hashtable/ht_hash_string.c

SRCS_LLIST	= llist/llist_add.c \
		llist/llist_destroy.c \
		llist/llist_new.c \
		llist/llist_remove.c \
		llist/llist_replace.c \
		llist/llist_search.c \
		llist/llist_toarray.c \
		llist/llist_nget.c \
		llist/llist_napply.c \
		llist/llist_nremove.c \
		llist/llist_apply.c \
		llist/llist_patch.c \
		llist/llist_dict.c \
		llist/llist_dict_get_entries.c \
		llist/llist_dict_length.c \
		llist/llist_iterator_ltr.c \
		llist/llist_iterator_rtl.c

SRCS_STRING	= string/new.c \
		string/init.c \
		string/destroy.c \
		string/cat.c \
		string/contains.c \
		string/replace.c \
		string/push.c \
		string/split.c \
		string/delete.c

SRCS	+= $(SRCS_LLIST)
SRCS	+= $(SRCS_DICT)
SRCS	+= $(SRCS_HTABLE)
SRCS	+= $(SRCS_VECTOR)
SRCS	+= $(SRCS_BTREES)
SRCS	+= $(SRCS_STRING)
SRCS	+= get_next_line.c

OBJS	= $(SRCS:.c=.o)

all: link
	$(MAKE) ranlib
	$(MAKE) copylib
	$(MAKE) copyheader

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

link: $(OBJS)
	ar rc $(NAME).a $(OBJS)

ranlib:
	ranlib $(NAME).a

copylib:
	$(CP) $(NAME).a ../$(NAME).a

copyheader:
	$(CP) ./inc/llist.h ../../inc/my/llist.h
	$(CP) ./inc/my.h ../../inc/my/my.h
	$(CP) ./inc/dictionnary.h ../../inc/my/dictionnary.h
	$(CP) ./inc/hashtable.h ../../inc/my/hashtable.h
	$(CP) ./inc/vector.h ../../inc/my/vector.h
	$(CP) ./inc/btrees.h ../../inc/my/btrees.h
	$(CP) ./inc/str.h ../../inc/my/str.h

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME).a

re: fclean
	$(MAKE) -j all
