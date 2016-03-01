#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>


// Prototypen
int error_1();
int fileFinder(char *dir, char inputname[]);

char *get_current_dir_name(void);


int main(int argc, char * argv[])
{
	//char path[] = NULL;

	//if (strcmp(argv[1], "-name") == 0 || strcmp(argv[1], "-user") == 0 || strcmp(argv[1], "-type") == 0) {
		//printf("erfolgreich");
		fileFinder("/home/ic15b081/", "bla.c");



	//}

	//else if (strcmp(argv[1], path) == 0) {
	//	if (strcmp(argv[2], "-name") == 0 || strcmp(argv[2], "-user") == 0 || strcmp(argv[2], "-type") == 0) {
	//	}


	//else
    //error_1();
	getchar();
	return 0;

} // End of Main



int error_1()
{
	printf("  -> ERROR: Wrong entry syntc - please check --help for syntax-Info\n");
	return 1;
}



int fileFinder(char *dir,char inputname[])
{
	struct dirent *entry;
	DIR *dirpointer;
	struct stat fileInfo;

	if (((dirpointer = opendir(dir)) == NULL) && (errno != 0))
	{
        switch (errno)
        {
	case 1: printf("Operation not permitted \n");
		break;
	case 2: printf("No such file or directory\n");
		break;
	case 3: printf("No such process\n");
		break;
	case 4: printf("Interrupted function call\n");
		break;
	case 5: printf("Input/output error\n");
		break;
	case 6: printf("No such device or address\n");
		break;
	case 7: printf("Argument list too long\n");
		break;
	case 8: printf("Exec format error\n");
		break;
	case 9: printf("Bad file descriptor\n");
		break;
	case 10: printf("No child processes\n");
		break;
	case 11: printf("Resource temporarily unavailable\n");
		break;
	case 12: printf("Not enough space\n");
		break;
	case 13: printf("Permission denied\n");
		break;
	case 14: printf("Bad address\n");
		break;
	case 16: printf("Device or resource busy\n");
		break;
	case 17: printf("File exists\n");
		break;
	case 18: printf("Improper link\n");
		break;
	case 19: printf("No such device\n");
		break;
	case 20: printf("Not a directory\n");
		break;
	case 21: printf("Is a directory\n");
		break;
	case 23: printf("Too many open files in system\n");
		break;
	case 24: printf("Too many open files\n");
		break;
	case 25: printf("Inappropriate I/O control operation\n");
		break;
	case 27: printf("File too large\n");
		break;
	case 28: printf("No space left on device\n");
		break;
	case 29: printf("Invalid seek\n");
		break;
	case 30: printf("Read-only filesystem\n");
		break;
	case 31: printf("Too many links\n");
		break;
	case 32: printf("Broken pipe\n");
		break;
	case 33: printf("Mathematics argument out of domain of function\n");
		break;
	case 36: printf("Resource deadlock avoided\n");
		break;
	case 38: printf("Filename too long\n");
		break;
	case 39: printf("No locks available\n");
		break;
	case 40: printf("Function not implemented\n");
		break;
	case 41: printf("Directory not empty\n");
		break;
	default: printf("Unknown Error\n");
		break;
        }
		return -1;


//		fprintf(stderr, "Dir cannot open: %s\n", dir);
//		return;
    }
    else

		chdir(dir);

		while ((entry = readdir(dirpointer)) != NULL)
		{
			lstat(entry->d_name, &fileInfo);


                if (S_ISDIR(fileInfo.st_mode) == 1) // Wenn Verzeichnis dann oeffnen
			{
                if (strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0)
                        continue;

				fileFinder(entry->d_name, inputname);
			}

			if(strcmp(inputname, entry->d_name) == 0)
			{
                 printf(" %s/%s \n",  get_current_dir_name(), inputname);
             if (0 /*Eingabe -ls*/)
                {
                    fprintf("%zu    ", fileInfo.st_ino);
                    fprintf("%zu    ", fileInfo.st_blksize);
                    fprintf("%zu    ", fileInfo.st_mode);
                    fprintf("%zu    ", fileInfo.st_nlink);
                    fprintf("%zu    ", fileInfo.st_uid);
                    fprintf("%zu    ", fileInfo.st_gid);
                    fprintf("%zu    ", fileInfo.st_mtime);
                    fprintf("%zu    ", fileInfo.st_dev);
                }
			}
		}
		chdir("..");
		closedir(dirpointer);
		return 0;
    }







