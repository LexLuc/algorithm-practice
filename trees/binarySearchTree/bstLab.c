#include <stdio.h>
#include <string.h>
#include "bst.h"

int readKey();
void *readItem();

int main(int argc, char *argv[]) {
	if (argc != 1 && argc != 2) {
		fprintf(stderr, "Usage: $ %s --help for more info\n", argv[0]);
		return -1;
	}
	if (argc == 2) {
		if (strcmp(argv[1], "--help") == 0) {
			// print help info and exit
			fprintf(stderr, "Not implemented yet!\n");
			return 1;
		} else {
			fprintf(stderr, "Unrecognized option \"%s\"\n", argv[1]);
			return -1;
		}
	}

	TreeType bst = NULL;
	int key;
	void *item = NULL;
	char op;
	while (1) {
		printf("\nOperation? ");
		scanf(" %c", &op);
		switch (op) {
			case 'i':
				// insert node to BST:
				printf("Insert: ");
				key = readKey();
				//Todo: read items from io stream by "readItem()"
				bst = bstInsert(bst, key, item);
				break;

			case 'r':
				// remove node from BST:
				fprintf(stderr, "Not implemented yet! Try other operations\n");
				break;
			case 'd':
				// display structure of BST:
				printf("Display:\n");
				bstShow(bst);
				break;
			case 's':
				// search node in BST:
				printf("Search: ");
				key = readKey();
				TreeType subBst = bstSearch(bst, key);
				if (subBst == NULL) {
					printf("Node with key \"%d\" not found!\n", key);
				} else {
					bstDisplayRoot(subBst);
				}
				break;
			case 'e':
				// pre-order traversal on BST
				fprintf(stderr, "Not implemented yet! Try other operations\n");
				break;
			case 'n':
				// in-order traversal on BST
				fprintf(stderr, "Not implemented yet! Try other operations\n");
				break;
			case 'o':
				// post-order traversal on BST
				fprintf(stderr, "Not implemented yet! Try other operations\n");
				break;
			case 'l':
				// level-order traversal on BST
				fprintf(stderr, "Not implemented yet! Try other operations\n");
				break;
			case 'q':
				// exit the program
				printf("Bye~\n");
				return 0;
			default:
				fprintf(stderr, "Error: Unrecognized operation \"%c\"\n", op);
		}
	}
	return 0;
}

/**
 * read an integer as key of node
 */
int readKey() {
	int key;
	do {
		printf("Expect an non-negative integer as key: ");
		scanf("%d", &key);
	} while (key < 0);

	return key;
}

/**
 * read a string as item of node
 */
void *readItem() {
	fprintf(stderr, "Warning: \"Read item\" has not been implemented yet!\n");
	return NULL;
}
