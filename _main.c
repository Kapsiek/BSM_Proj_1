#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>


int error_1();
int error_dir(char own_path);

void findFile(char *dir,char name[], int depth)
{
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;

	if ((dp = opendir(dir)) == NULL) {
		fprintf(stderr, "cannot open directory: %s\n", dir);
		return;
		}
    else{
		chdir(dir);
		while ((entry = readdir(dp)) != NULL) {
			lstat(entry->d_name, &statbuf);
			if (S_ISDIR(statbuf.st_mode)) {
				/* Found a directory, but ignore . and .. */
	    		if (strcmp(".", entry->d_name) == 0 ||
					strcmp("..", entry->d_name) == 0)
                        continue;
				//printf("%*s%s/\n", depth, "", entry->d_name);
				/* Recurse at a new indent level */
				findFile(entry->d_name, name, depth + 4);
			}
			//else printf("%*s%s\n", depth, "", entry->d_name);
			if(strcmp(name, entry->d_name)==0)
                printf("%s / %s / %s\n", depth, entry->d_name, name);

		}
		chdir("..");
		closedir(dp);
		}
}


int main(int argc, char * argv[])
{
	//char path[] = NULL;

	//if (strcmp(argv[1], "-name") == 0 || strcmp(argv[1], "-user") == 0 || strcmp(argv[1], "-type") == 0) {
		//printf("erfolgreich");
		findFile("/home/ic15b081/GDI/", "copy.c", 0);



	//}

	//else if (strcmp(argv[1], path) == 0) {
	//	if (strcmp(argv[2], "-name") == 0 || strcmp(argv[2], "-user") == 0 || strcmp(argv[2], "-type") == 0) {
	//	}


	//else
		error_1();




	getchar();
	return 0;

}

int error_1()
{
	printf("  -> ERROR: Wrong entry syntc - please check --help for syntax-Info\n");
	return 1;
}








