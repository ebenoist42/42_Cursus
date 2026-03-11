/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:35:21 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/10/01 16:32:55 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	append_expand_segment(t_append_ctx *ctx)
{
	int	ok;

	auto char *seg, *exp, *tmp, *dup;
	seg = malloc(ctx->len + 1);
	if (!seg)
		return (0);
	memcpy(seg, ctx->s, ctx->len);
	seg[ctx->len] = '\0';
	exp = seg;
	if (ctx->quote_type != 1)
	{
		dup = ft_strdup(seg);
		if (dup)
		{
			tmp = replace_expand(dup);
			if (!tmp)
				return (free(seg), 0);
			exp = tmp;
		}
	}
	ok = append_buf(ctx->out, ctx->olen, exp, strlen(exp));
	free(seg);
	if (exp != seg)
		free(exp);
	return (ok);
}

void	set_ctx(t_append_ctx *c, const char *s, size_t len, int qt)
{
	c->s = s;
	c->len = len;
	c->quote_type = qt;
}

int	handle_quotes_inner(char **out, size_t *olen, const char *s, char q)
{
	size_t			j;
	t_append_ctx	ctx;

	auto int cnt2, quote_type = 1 + (q != '\'');
	while (s[_data()->i])
	{
		j = _data()->i;
		if (s[j] == q)
		{
			cnt2 = count_and_advance(s, &j, q);
			_data()->i = j;
			if ((cnt2 % 2) == 1)
				return (1);
			continue ;
		}
		while (s[j] && s[j] != q)
			j++;
		ctx.out = out;
		ctx.olen = olen;
		set_ctx(&ctx, &s[_data()->i], (size_t)(j - _data()->i), quote_type);
		if (!append_expand_segment(&ctx))
			return (0);
		_data()->i = j;
	}
	return (1);
}

char	*strndup_quote(char *s)
{
	size_t	olen;
	int		start;
	char	*out;

	olen = 0;
	out = NULL;
	while (s[_data()->i] && !is_boundary(s[_data()->i])
		&& !ft_isspace(s[_data()->i]))
	{
		if (s[_data()->i] == '\'' || s[_data()->i] == '\"')
		{
			if (!handle_consecutive_quotes(&out, &olen))
				return (free(out), NULL);
			continue ;
		}
		start = _data()->i;
		while (s[_data()->i] && s[_data()->i] != '\'' && s[_data()->i] != '\"'
			&& !is_boundary(s[_data()->i]) && !ft_isspace(s[_data()->i]))
			_data()->i++;
		if (_data()->i > start && !process_literal_segment(&out, &olen, s,
				start))
			return (free(out), NULL);
	}
	return (out || (out = ft_strdup("")), out);
}

char	*strndup_token(char *s)
{
	int		start;
	char	*out;
	char	*seg;

	out = NULL;
	auto size_t len, olen = 0;
	while (s[_data()->i] && !is_boundary(s[_data()->i])
		&& !ft_isspace(s[_data()->i]))
	{
		if (s[_data()->i] == '\'' || s[_data()->i] == '\"')
		{
			seg = strndup_quote(s);
			if (!seg || !add_segment(&out, &olen, seg))
				return (free(seg), free(out), NULL);
			free(seg);
			continue ;
		}
		start = _data()->i;
		len = read_unquoted_segment(s, &_data()->i);
		if (len && !process_literal_segment(&out, &olen, s, start))
			return (free(out), NULL);
	}
	if (!out)
		out = ft_strdup("");
	return (out);
}
