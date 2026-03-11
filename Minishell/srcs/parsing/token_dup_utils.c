/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_dup_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:05:31 by ebenoist          #+#    #+#             */
/*   Updated: 2025/10/01 16:38:09 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	handle_consecutive_quotes(char **out, size_t *olen)
{
	const char	*s;
	char		q;
	size_t		pos;
	int			cnt;

	s = _data()->input;
	q = s[_data()->i];
	pos = _data()->i;
	cnt = count_and_advance(s, &pos, q);
	_data()->i = pos;
	if ((cnt % 2) == 0)
		return (1);
	return (handle_quotes_inner(out, olen, s, q));
}

int	read_unquoted_segment(char *s, int *count)
{
	int	start;

	start = *count;
	while (s[*count] && !is_boundary(s[*count]) && !ft_isspace(s[*count])
		&& !(s[*count] == '\'' || s[*count] == '\"'))
		(*count)++;
	return (*count - start);
}

int	count_and_advance(const char *s, size_t *pos_ptr, char q)
{
	int		cnt;
	size_t	p;

	cnt = 0;
	p = *pos_ptr;
	while (s[p] && s[p] == q)
	{
		cnt++;
		p++;
	}
	*pos_ptr = p;
	return (cnt);
}

int	process_literal_segment(char **out, size_t *olen, const char *s,
		int start)
{
	t_append_ctx	ctx;

	ctx.out = out;
	ctx.olen = olen;
	ctx.s = &s[start];
	ctx.len = (size_t)(_data()->i - start);
	ctx.quote_type = 0;
	if (!append_expand_segment(&ctx))
		return (0);
	return (1);
}

int	add_segment(char **out, size_t *olen, char *seg)
{
	size_t	l;

	if (!seg)
		return (0);
	l = strlen(seg);
	if (l && !append_buf(out, olen, seg, l))
		return (0);
	return (1);
}
