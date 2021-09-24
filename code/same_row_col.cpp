#include "same_row_col.h"
bool is_same_row(int zy, int py)
{
	if (zy == 80 && py == 85)
	{
		return true;
	}
	else if (py == zy + 35)
	{
		return true;
	}
	return false;
}