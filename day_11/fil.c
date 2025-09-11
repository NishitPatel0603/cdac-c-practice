#include <stdio.h>
#include <stdlib.h>


struct student
{
	char name[20];
	int age;
	char course[10];
	int roll;
	float marks;
};

int main(void)
{
	struct student s[2];
	float total = 0.0f; 

	for (int i = 0; i < 2; i++)
	{
		printf("Enter details for student %d (name age course roll marks):\n", i + 1);
		if (scanf("%19s %d %9s %d %f",
				  s[i].name, &s[i].age, s[i].course, &s[i].roll, &s[i].marks) != 5)
		{
			fprintf(stderr, "Invalid input. Exiting.\n");
			return 1;
		}
		total += s[i].marks;
	}

	FILE *a = fopen("student_info.txt", "w");
	if (a == NULL)
	{
		perror("fopen student_info.txt");
		return 1;
	}

	fprintf(a, "Name\tAge\tCourse\tRoll no. Marks\n");
	for (int i = 0; i < 2; i++)
	{
		fprintf(a, "%s\t%d\t%s\t%d\t%.1f\n",
				s[i].name, s[i].age, s[i].course, s[i].roll, s[i].marks);
	}
	fclose(a);

	a = fopen("student_info.txt", "r");
	if (a == NULL)
	{
		perror("fopen student_info.txt for reading");
		return 1;
	}
	int ch;
	while ((ch = fgetc(a)) != EOF)
	{
		putchar(ch);
	}
	fclose(a);

	float avg = total / (float)2;

	a = fopen("student_avg.txt", "w");
	if (a == NULL)
	{
		perror("fopen student_avg.txt");
		return 1;
	}
	fprintf(a, "avg. of students is %0.2f\n", avg);
	fclose(a);

	printf("Average marks: %.2f\n", avg);

	return 0;
}
