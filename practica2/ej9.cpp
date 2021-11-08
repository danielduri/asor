#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysmacros.h>

int main(int argc, char *argv[]){

	struct stat sb;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (lstat(argv[1], &sb) == -1) {
		perror("lstat");
		exit(EXIT_FAILURE);
	}

	printf("ID of containing device:  [%lx (major),%lx (minor)]\n",
		(long) major(sb.st_dev), (long) minor(sb.st_dev));

	printf("I-node number:            %ld\n", (long) sb.st_ino);

	printf("File type:                ");

	switch (sb.st_mode & S_IFMT) {
		case S_IFDIR:  printf("directory\n");               break;
		case S_IFLNK:  printf("symlink\n");                 break;
		case S_IFREG:  printf("regular file\n");            break;
		default:       printf("unknown?\n");                break;
	}

	printf("Last file modification:   %s", ctime(&sb.st_mtime));

	exit(EXIT_SUCCESS);
}

//st_mtime muestra la fecha de la última modificación del contenido del fichero.
//st_ctime muestra la fecha del último cambio al status
//si cambiamos el nombre del fichero, o le añadimos más enlaces por ejemplo, cambia ctime pero no mtime.
/*EJEMPLO:

	usuario_vms@pto0604:~/pr2$ stat dummyfile
  Fichero: dummyfile
  Tamaño: 0         	Bloques: 0          Bloque E/S: 4096   fichero regular vacío
Dispositivo: 809h/2057d	Nodo-i: 5775633     Enlaces: 1
Acceso: (0640/-rw-r-----)  Uid: (  565/usuario_vms)   Gid: (  100/   users)
Acceso: 2021-11-08 10:01:41.409743368 +0100
Modificación: 2021-11-08 10:01:40.761745178 +0100
      Cambio: 2021-11-08 10:01:40.761745178 +0100
    Creación: -

usuario_vms@pto0604:~/pr2$ mv dummyfile dummyfile3

usuario_vms@pto0604:~/pr2$ stat dummyfile3
  Fichero: dummyfile3
  Tamaño: 0         	Bloques: 0          Bloque E/S: 4096   fichero regular vacío
Dispositivo: 809h/2057d	Nodo-i: 5775633     Enlaces: 1
Acceso: (0640/-rw-r-----)  Uid: (  565/usuario_vms)   Gid: (  100/   users)
Acceso: 2021-11-08 10:01:41.409743368 +0100
Modificación: 2021-11-08 10:01:40.761745178 +0100
      Cambio: 2021-11-08 10:21:39.589884089 +0100
    Creación: -

/*