#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* args[])
{
	char* file_path = "C:\\Users\\Abhijay\\Documents\\Github\\Pushups\\c\\pushups.dat";
	FILE *file = fopen(file_path, "r");
	int pushups;
	fscanf(file, "%d\n", &pushups);

	if (argc == 1)
	{
		printf("Pushups %d\n", pushups);
		fclose(file);
	} else if (argc == 2)
	{
		fclose(file);
		FILE *file = fopen(file_path, "w+");
		pushups += atoi(args[1]);
		printf("Total %d\n", pushups);
		fprintf(file, "%d\n", pushups);
		fclose(file);
	}
}
