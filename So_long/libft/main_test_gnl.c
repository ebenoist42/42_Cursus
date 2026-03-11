#include <fcntl.h>
#include <stdio.h>
#include "libft.h"

int	main(int argc, char **argv)
{
	int   fd;
	char *line;
	int   n = 1;

	/* 1) choisir la source : fichier ou stdin -------------------------------- */
	if (argc == 1)                      /* aucun argument → lire stdin          */
		fd = 0;                         /* 0 = STDIN_FILENO                     */
	else if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (perror("open"), 1);     /* message d’erreur puis exit           */

	/* 2) boucle de lecture ---------------------------------------------------- */
	while ((line = get_next_line(fd)))
	{
		printf("Ligne %d: %s", n++, line);   /* \n déjà présent dans line          */
		free(line);                          /* indispensable pour éviter les leaks */
	}

	/* 3) fermer le fichier si besoin ----------------------------------------- */
	if (fd > 0)
		close(fd);
	return (0);
}
