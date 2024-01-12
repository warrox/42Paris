/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:51:14 by whamdi            #+#    #+#             */
/*   Updated: 2023/12/30 16:55:42 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// de ce que je comprend tu rentre les 2 files en ligne de commande + 
// 2 commande et ca les executes dans le terminal
//TODO read man pipe et autres fonctions 
// bien comprendre le but de pipex etre sur a 100%
#include <unistd.h>
       #include <sys/wait.h>

int ft_pipex(const char *file1, const char *file2, const char *cmd1, const char *cmd2)
{
	int fd[2];
	int pid1;
	if (pipe(fd) == -1)
		return(-1);
	pid1 = fork();
	if(pid1 < 0)
		return(0);
	if (pid1 == 0)
	{
		execlp("ls","-a"); // tu vas devoir le coder je crois.
	}
	waitpid(pid1,NULL,0);
	// close fd[0] and fd[1];
}
int main(int argc, char **argv)
{
	ft_pipex(argv[1],argv[4],cmd1,cmd2);
}