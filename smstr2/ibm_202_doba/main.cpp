#include "Muzeu.h"

main()
{
	int choice;
	int N = 1;
	struct Muzeu *m;

	do
	{

		printf("\n\nAlegeti un punct din menu:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:

			MemoryAllocation(m, N);
			;
			break;

		case 2:

			DeleteMemory(m);

			break;
		case 3:

			EnterElements(m, N);

			break;
		case 4:

			OutPutElements(m, N);

			break;
		case 5:

			ReadFromFile(m, N);

			break;
		case 6:

			WritetoFile(m, N);

			break;
		case 7:

			SearchElement(m, N);

			break;
		case 8:

			SortMuzeu(m, N);

			break;
		case 9:

			ReWriteElement(m, N);

			break;
		case 10:

			AddNewElement(m, N);

			break;
		case 11:

			DeleteElement(m, N);

			break;
		case 12:

			InsertElement(m, N);

			break;
		case 13:
			if (m != NULL)
				DeleteMemory(m);
			printf("\n Esirea din programa e succesa!\n");
			return 0;

		default:
			printf("\n Scrierea e incorecta. Selecnati un numar din menu: ");
			break;
		}
	} while (choice < 13);
	getch();
	return 0;
}
