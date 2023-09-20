#include "disease.h"

cell disease::make_disease_cell( int chromosome_count, string sequence )
{
	return cell::make_cell( chromosome_count, sequence );
}

bool disease::attack( cell disease_cell, alien* subject, int replication_rate )
{
	cell::replicate( disease_cell, subject->cells, replication_rate );
	return true;
}