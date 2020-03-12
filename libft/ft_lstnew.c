/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:36:47 by fallard           #+#    #+#             */
/*   Updated: 2019/09/20 20:20:39 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		node->content = NULL;
		node->content_size = 0;
	}
	else
	{
		node->content = (void *)malloc(sizeof(*content) * (content_size));
		if (node->content == NULL)
		{
			free(node);
			return (NULL);
		}
		node->content = ft_memcpy(node->content, (void *)content, content_size);
		node->content_size = content_size;
	}
	node->next = NULL;
	return (node);
}
