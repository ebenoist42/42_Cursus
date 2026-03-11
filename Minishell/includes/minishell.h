/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:01:57 by dbhujoo           #+#    #+#             */
/*   Updated: 2025/10/02 10:20:42 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termcap.h>
# include <termios.h>
# include <unistd.h>

extern int				g_signal_status;

typedef struct s_env
{
	char				*key;
	char				*value;
	struct s_env		*next;
}						t_env;

typedef enum e_token_type
{
	T_WORD,
	T_PIPE,
	T_REDIR_IN,
	T_REDIR_OUT,
	T_APPEND,
	T_HEREDOC,
	T_ERROR,
}						t_tokentype;

typedef enum e_asttype
{
	N_CMD,
	N_PIPE,
	N_REDIR,
	N_REDIR_OUT,
	N_HEREDOC,
	N_REDIR_IN,
	N_APPEND,
}						t_asttype;

typedef enum e_redirtype
{
	R_IN,
	R_OUT,
	R_APPEND,
	R_HEREDOC
}						t_redirtype;

typedef struct s_redir	t_redir;

struct					s_redir
{
	t_redirtype			kind;
	char				*word;
	int					quoted;
	t_redir				*next;
};

typedef struct s_ast
{
	t_asttype			type;
	struct s_ast		*left;
	struct s_ast		*right;
	char				**argv;
	char				*target;
}						t_ast;

typedef struct s_append_ctx
{
	char				**out;
	size_t				*olen;
	const char			*s;
	size_t				len;
	int					quote_type;
}						t_append_ctx;

typedef struct s_tok
{
	t_tokentype			type;
	char				*str;
	int					priority;
	int					quote;
	struct s_tok		*next;
}						t_token;

typedef struct s_data
{
	char				*input;
	char				*prompt;
	char				**env_tab;
	int					i;
	int					exit_code;
	int					fd[2];
	t_env				*env_list;
	t_token				*token;
	t_ast				*ast;
}						t_data;

// ENV
t_env					*env_to_list(char **envp);
t_env					*env_to_node(char *env);
char					**env_to_array(t_env *env_list);
char					*replace_expand(char *str);
void					update_existing_env(t_env *current, char *value);
// UTILS
void					error_malloc(void);
t_data					*_data(void);
void					last_free(void);
void					signal_handler(int sig);
// BUILDINS
int						exec_builtins(t_ast *node);
int						is_builtin(char *str);
void					cd_builtin(t_ast *node);
char					apply_path(char *cd, char *oldpwd);
void					echo_builtin(t_ast *node);
void					exit_builtin(t_ast *node);
int						pwd_builtin(void);
int						env_builtin(void);
char					*get_env_value(const char *key);
void					export_builtin(t_ast *node);
void					print_export(t_env *env);
int						is_valid_key(char *key);
void					unset_builtin(t_ast *node);
char					*get_export_key(char *argv);
char					*get_value(char *argv);
void					sigquit_handler(int sig);

// PARSING
t_token					*tok_new(t_tokentype type);
void					tok_push_back(t_token **head, t_token *node);
int						ft_check_quote(char *str);
int						ft_check_quote_double(char *str, int i);
int						ft_check_quote_simple(char *str, int i);
t_token					*ft_creat_token_list(void);
void					tok_free_all(t_token **head);
void					split_unquoted_words(char *str);
int						is_boundary(unsigned char c);
char					*strndup_token(char *s);
char					*help_strndup(int c, char quote);
int						parsing(char *input);
int						check_redir_glue(char *str, int i, int count, int len);
int						ft_isspace(int c);
int						ft_parsing_quote(char *input, int i);
int						ms_priority(t_tokentype type);
int						operator_erreur(const char *s, int i);
int						ft_quote_twins(char *str, int i, char q);
char					*strndup_quote(char *s);
int						passe_quote(char *str, int i);
int						double_operateur(char *str, int i);
t_token					*find_first_subshell(t_token *tokens,
							t_token **out_rparen);
int						is_redirection_token(t_token *jeton);
t_token					*tokens_droite(t_token *op);
t_token					*tokens_gauche(t_token *tokens, t_token *op);
t_asttype				token_to_asttype(t_tokentype type);
t_token					*find_matching_rparen(t_token *lpar);
t_token					*clone_tokens_range(t_token *from, t_token *to_excl);
void					print_minishell_state(void);
void					print_token_list(t_token *head);
int						ft_operateur(char *str, int i);
int						skip_space_break(void);
char					*remove_quotes(const char *str);
int						peek_token_quote(void);
int						append_buf(char **dst, size_t *dlen, const char *src,
							size_t len);
int						read_unquoted_segment(char *s, int *count);
int						handle_consecutive_quotes(char **out, size_t *olen);
int						count_and_advance(const char *s, size_t *pos_ptr,
							char q);
int						process_literal_segment(char **out, size_t *olen,
							const char *s, int start);
int						add_segment(char **out, size_t *olen, char *seg);
int						handle_quotes_inner(char **out, size_t *olen,
							const char *s, char q);
void					set_ctx(t_append_ctx *c, const char *s, size_t len,
							int qt);
int						append_expand_segment(t_append_ctx *ctx);

// AST
t_ast					*create_ast_node(t_token *tokens);
t_token					*find_highest_priority_operator(t_token *tokens);
void					handle_regular_node(t_ast *node, t_token *rt);
// AST UTILS
char					**extract_argv(t_token *token);
void					free_ast(t_ast *ast);
void					free_token_list(t_token *tokens);
int						count_args(t_token *token);

// EXEC
void					execute_recursive(t_ast *ast, int fd_in, int fd_out);
int						exec_simple_cmd(t_ast *ast, int fd_in, int fd_out);
void					exec(t_ast *ast, char **envp);
char					*get_path(char *cmd);
char					*get_env(char *path, char **envp);
int						execute_redirect(t_ast *ast);
int						execute_pipe(t_ast *ast, int in_fd, int out_fd);
int						open_file_heredoc(char *eof, int *tmp);
int						open_file_heredoc_chain(t_ast *heredoc_root, int *tmp);
int						get_heredoc_fd(const char *limiter, int *tmp);
void					close_redirect_fds_in_child(void);
int						pipe_error(int ret, const char *msg);

// REDIR
int						apply_redirection(t_ast *node, int *saved_in,
							int *saved_out, int *tmp);
bool					is_redirection(t_ast *node);
char					*get_filename(t_ast *node);
bool					should_close_fd(int fd);
bool					is_heredoc_chain(t_ast *node);
int						process_heredoc_chain(t_ast *node, int *saved_in,
							int *tmp);
void					init_tmp_array(int *tmp);

// HEREDOC
void					strip_eol(char *s);
int						handle_redir_in(char *file, int *saved_in);
int						handle_redir_out(char *file, int *saved_out);
void					close_tmp_fds(int *tmp);
int						heredoc_parent(pid_t pid, int *p);
void					print_eof_warning(const char *limiter);
void					cleanup_and_exit(int *tmp, int write_fd);
#endif
