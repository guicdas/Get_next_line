#include <stdlib.h>

typedef struct s_list
{
void *content;
struct s_list *next;
} t_list;

t_list *ft_lstnew(void *content)
{
	t_list	*new;


	new = (t_list *)malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	if (!*lst)
		return ;
	new->next = *lst;
	*lst = new;
}

int ft_lstsize(t_list *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list *ft_lstlast(t_list *lst)
{
	while (lst)
	{
		lst = lst->next;
	}
	return (lst);
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ult;

	if (!lst)
		return (NULL);
	if (*lst)
	{
		ult = ft_lstlast(*lst);
		ult->next = new;
	}
	else
		*lst = new;
}

void ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}

void ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*prox;

	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		prox = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = prox;
	}
}

void ft_lstiter(t_list *lst, void (*f)(void *))
{

}