/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 09:58:44 by ebenoist          #+#    #+#             */
/*   Updated: 2025/08/04 14:49:25 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <sys/wait.h>

typedef struct s_pipe
{
	char	*cmd1_path;
	char	*cmd2_path;
	char	**cmd1_arg;
	char	**cmd2_arg;
	char	***cmdi_arg;
	char	**cmdi_path;
	int		pid;
	int		pipe[2];
	int		nb_cmd;
	int		nb_pipe;
	int		(*fd)[2];
	int		fd_in;
	int		sortie;
	int		fd_out;
	char	**paths;
	char	**path_cmd;
	int		here_doc;
}			t_pipe;

void		ft_free_tab(char **tab);
void		ft_free_tab_bonus(char **tab, t_pipe *pipex);
char		*find_path(char *cmd, char *envp);
char		*find_path_2(char *cmd, char *paths);
void		ft_test_arg(int ac);
char		*ft_management_arg(char *av, char **envp);
void		ft_end_programme(t_pipe *pipex);
int			ft_close_pipe_waitpid(pid_t pid1, pid_t pid2, t_pipe pipex, int i);
void		ft_erreur127(t_pipe *pipex);
void		ft_init_pipex(t_pipe *pipex);
void		test_arg(int ac);
char		*ft_management_arg_bonus(char *av, char **envp);
void		ft_end_programme_bonus(t_pipe *pipex);
void		ft_free_tab_tab(char ***tab, t_pipe *pipex);
void		ft_init_pipex_bonus(int ac, char **av, t_pipe *pipex);
void		ft_creat_path(int ac, char **av, char **envp, t_pipe *pipex);
void		ft_erreur127_bonus(t_pipe *pipex);
void		ft_close_pipe_bonus(t_pipe *pipex);
int			her_doc_fd(char *limiter);
void		creat_pipe(t_pipe *pipex);
#endif