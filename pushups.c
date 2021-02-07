#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

// TODO: organize code better
int main(int argc, char* args[])
{
	char* file_path = "pushups.dat"; // TODO: make universal
	FILE *file = fopen(file_path, "r"); // TODO: simplify
	time_t now = time(NULL);
	struct tm *now_tm = localtime(&now);
	// printf("Today: %d (%jd)\n", now_tm->tm_mday, now);

	// read from file
	uint8_t pushups = 0;
	time_t prev = 0;
	struct tm *prev_tm;
	fscanf(file, "%hhu\n%jd", &pushups, &prev);
	fclose(file);
	prev_tm = localtime(&prev); // TODO: better solution maybe? string parsing perhaps
	// printf("Last modified: %d (%jd)\n", prev_tm->tm_mday, prev);

	if (now_tm->tm_mday != prev_tm->tm_mday) // TODO: do better checking
		pushups = 0;

	if (argc == 1)
	{
		printf("Count: %hhu\n", pushups);
	} else if (argc == 2)
	{
		pushups += atoi(args[1]);
		printf("New count: %hhu\n", pushups);
	}

	file = fopen(file_path, "w");
	fprintf(file, "%hhu\n%jd\n", pushups, now);
	fclose(file);
}
