#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* readline();
char** split_string(char*);
// Complete la siguiente función climbingLeaderboard. NOTA: Se deberá elegir el tipo y estructura de datos usar.
int* climbingLeaderboard(int scores_count, int *scores, int alice_count, int *alice, int *result_count) {
	for(int i=0; i<alice_count; i++){
		for(int x=0; x<scores_count; x++){
			if(alice[i]==scores[x]){
				result_count[i]=x+1;
				break;
			}
		}
	}
	return result_count;
}
int main() {
	FILE *fptr = fopen(getenv("OUTPUT_PATH"), "w");
	char *scores_count_endptr;
	char *scores_count_str = readline();
	int scores_count = strtol(scores_count_str, &scores_count_endptr, 10);
	if (scores_count_endptr == scores_count_str
			|| *scores_count_endptr != '\0') {
		exit(EXIT_FAILURE);
	}
	char **scores_temp = split_string(readline());
	int *scores = malloc(scores_count * sizeof(int));
	for (int i = 0; i < scores_count; i++) {
		char *scores_item_endptr;
		char *scores_item_str = *(scores_temp + i);
		int scores_item = strtol(scores_item_str, &scores_item_endptr, 10);
		if (scores_item_endptr == scores_item_str
				|| *scores_item_endptr != '\0') {
			exit(EXIT_FAILURE);
		}
		*(scores + i) = scores_item;
	}
	char *alice_count_endptr;

	char *alice_count_str = readline();
	int alice_count = strtol(alice_count_str, &alice_count_endptr, 10);
	if (alice_count_endptr == alice_count_str || *alice_count_endptr != '\0') {
		exit(EXIT_FAILURE);
	}
	char **alice_temp = split_string(readline());
	int *alice = malloc(alice_count * sizeof(int));
	for (int i = 0; i < alice_count; i++) {
		char *alice_item_endptr;
		char *alice_item_str = *(alice_temp + i);
		int alice_item = strtol(alice_item_str, &alice_item_endptr, 10);
		if (alice_item_endptr == alice_item_str || *alice_item_endptr != '\0') {
			exit(EXIT_FAILURE);
		}
		*(alice + i) = alice_item;
	}
	int result_count;
	int *result = climbingLeaderboard(scores_count, scores, alice_count, alice,
			&result_count);
	for (int i = 0; i < result_count; i++) {
		fprintf(fptr, "%d", *(result + i));
		if (i != result_count - 1) {
			fprintf(fptr, "\n");
		}
	}
	fprintf(fptr, "\n");
	fclose(fptr);
	return 0;
}
char* readline() {
	size_t alloc_length = 1024;
	size_t data_length = 0;
	char *data = malloc(alloc_length);
	while (true) {
		char *cursor = data + data_length;
		char *line = fgets(cursor, alloc_length - data_length, stdin);
		7
		if (!line) {
			break;
		}
		data_length += strlen(cursor);
		if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
			break;
		}
		size_t new_length = alloc_length << 1;
		data = realloc(data, new_length);
		if (!data) {
			break;
		}
		alloc_length = new_length;
	}
	if (data[data_length - 1] == '\n') {
		data[data_length - 1] = '\0';
	}
	data = realloc(data, data_length);
	return data;
}
char** split_string(char *str) {
	char **splits = NULL;
	char *token = strtok(str, " ");
	int spaces = 0;
	while (token) {
		splits = realloc(splits, sizeof(char*) * ++spaces);
		if (!splits) {
			return splits;
		}
		splits[spaces - 1] = token;
		token = strtok(NULL, " ");
	}
	return splits;
}
