#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void blobchecker(char***);

main()
{

	FILE *fp;
	fp = fopen("blobfile.txt", "r");
	if ((fp = fopen("blobfile.txt", "r")) == NULL) 
		printf("File not read \n");


	int c;
	char **myarray;
	int i, j;

	fscanf(fp, "%d", &c);
	myarray = malloc(c*sizeof(char*));

	for (i = 0; i < c; i++)
		myarray[i] = malloc(c);

	for (i = 0; i < c; i++)
		for (j = 0; j < c; j++)
			fscanf(fp, "%c", &myarray[i][j]);

	for (i = 0; i < c; i++)
		for (j = 0; j < c; j++)
			printf("%c", myarray[i][j]);

	printf("\n Now checking for blobs \n");

	blobchecker(&myarray);

	fclose(fp);

	for (i = 0; i<c; i++)
		free(myarray[i]);
	free(myarray);


}


void blobchecker(char ***a)
{
	int i, j;
	int found =0;
	for (i = 0; i < sizeof(*a); i++)
		for (j = 0; j < sizeof(*a); j++)
			if ((*a)[i][j] = '*')
				found = found + 1;

	printf("Number of blobs = %d\n", found);

}
