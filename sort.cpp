#include "define.h"


Sort::Sort(Location* locations, int size) :
	locations(locations),
	size(size)
{
}

void Sort::alphabet()
{
	Location temp;
	bool check = locations != nullptr;
	if (check)
	{
		for (int i = 0; i < size; ++i)
		{
			for (int j = i + 1; j < size; ++j)
			{
				if (locations[i].cityGet() > locations[j].cityGet())
				{
					temp = locations[i];
					locations[i] = locations[j];
					locations[j] = temp;
				}
			}

		}
	}
}
