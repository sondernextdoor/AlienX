#pragma once
#include "alien.h"


class disease
{
	cell make_disease_cell( int chromosome_count, string sequence );
	bool attack( cell disease_cell, alien* subject, int replication_rate );
};
