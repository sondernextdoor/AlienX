#include "cell.h"


void cell::set_all_genes( vector <cell>& cells, int chromosome_count, string sequence )
{
	for ( int i = 0; i < cells.size(); i++ )
	{

		for ( int j = 0; j < chromosome_count / 2; j++ )
		{
			cells.at( i ).nucleus.chromosome[j].dna.HE1.allele1 = sequence.at( 0 );
			cells.at( i ).nucleus.chromosome[j].dna.HE1.allele2 = sequence.at( 1 );
			cells.at( i ).nucleus.chromosome[j].dna.HE1.allele3 = sequence.at( 2 );
			cells.at( i ).nucleus.chromosome[j].dna.HE1.allele4 = sequence.at( 3 );

			cells.at( i ).nucleus.chromosome[j].dna.ST1.allele1 = sequence.at( 4 );
			cells.at( i ).nucleus.chromosome[j].dna.ST1.allele2 = sequence.at( 5 );
			cells.at( i ).nucleus.chromosome[j].dna.ST1.allele3 = sequence.at( 6 );
			cells.at( i ).nucleus.chromosome[j].dna.ST1.allele4 = sequence.at( 7 );

			cells.at( i ).nucleus.chromosome[j].dna.IN1.allele1 = sequence.at( 8 );
			cells.at( i ).nucleus.chromosome[j].dna.IN1.allele2 = sequence.at( 9 );
			cells.at( i ).nucleus.chromosome[j].dna.IN1.allele3 = sequence.at( 10 );
			cells.at( i ).nucleus.chromosome[j].dna.IN1.allele4 = sequence.at( 11 );

			cells.at( i ).nucleus.chromosome[j].dna.AP1.allele1 = sequence.at( 12 );
			cells.at( i ).nucleus.chromosome[j].dna.AP1.allele2 = sequence.at( 13 );
			cells.at( i ).nucleus.chromosome[j].dna.AP1.allele3 = sequence.at( 14 );
			cells.at( i ).nucleus.chromosome[j].dna.AP1.allele4 = sequence.at( 15 );
		}
	}
}


void cell::set_health_gene(  vector <cell>& cells, int chromosome_count, string sequence )
{
	for ( int i = 0; i < cells.size(); i++ )
	{
		for ( int j = 0; j < chromosome_count / 2; j++ )
		{
			cells.at( i ).nucleus.chromosome[j].dna.HE1.allele1 = sequence.at( 0 );
			cells.at( i ).nucleus.chromosome[j].dna.HE1.allele2 = sequence.at( 1 );
			cells.at( i ).nucleus.chromosome[j].dna.HE1.allele3 = sequence.at( 2 );
			cells.at( i ).nucleus.chromosome[j].dna.HE1.allele4 = sequence.at( 3 );
		}
	}
}


void cell::set_strength_gene( vector <cell>& cells, int chromosome_count,  string sequence )
{
	for ( int i = 0; i < cells.size(); i++ )
	{
		for ( int j = 0; j < chromosome_count / 2; j++ )
		{
			cells.at( i ).nucleus.chromosome[j].dna.ST1.allele1 = sequence.at( 0 );
			cells.at( i ).nucleus.chromosome[j].dna.ST1.allele2 = sequence.at( 1 );
			cells.at( i ).nucleus.chromosome[j].dna.ST1.allele3 = sequence.at( 2 );
			cells.at( i ).nucleus.chromosome[j].dna.ST1.allele4 = sequence.at( 3 );
		}
	}
}


void cell::set_intelligence_gene( vector <cell>& cells, int chromosome_count,  string sequence )
{
	for ( int i = 0; i < cells.size(); i++ )
	{
		for ( int j = 0; j < chromosome_count / 2; j++ )
		{
			cells.at( i ).nucleus.chromosome[j].dna.IN1.allele1 = sequence.at( 0 );
			cells.at( i ).nucleus.chromosome[j].dna.IN1.allele2 = sequence.at( 1 );
			cells.at( i ).nucleus.chromosome[j].dna.IN1.allele3 = sequence.at( 2 );				
			cells.at( i ).nucleus.chromosome[j].dna.IN1.allele4 = sequence.at( 3 );
		}
	}
}


void cell::set_appearance_gene( vector <cell>& cells, int chromosome_count, string sequence )
{
	for ( int i = 0; i < cells.size(); i++ )
	{
		for ( int j = 0; j < chromosome_count / 2; j++ )
		{
			cells.at( i ).nucleus.chromosome[j].dna.AP1.allele1 = sequence.at( 0 );
			cells.at( i ).nucleus.chromosome[j].dna.AP1.allele2 = sequence.at( 1 );
			cells.at( i ).nucleus.chromosome[j].dna.AP1.allele3 = sequence.at( 2 );
			cells.at( i ).nucleus.chromosome[j].dna.AP1.allele4 = sequence.at( 3 );
		}
	}
}


void cell::set_height_gene( vector <cell>& cells, int chromosome_count, char allele )
{
	for ( int i = 0; i < cells.size(); i++ )
	{
		for ( int j = 0; j < chromosome_count / 2; j++ )
		{
			cells.at( i ).nucleus.chromosome[j].dna.AP1.allele2 = allele;
		}
	}
}


void cell::set_weight_gene( vector <cell>& cells, int chromosome_count, char allele )
{
	for ( int i = 0; i < cells.size(); i++ )
	{
		for ( int j = 0; j < chromosome_count / 2; j++ )
		{
			cells.at( i ).nucleus.chromosome[j].dna.AP1.allele3 = allele;
		}
	}
}


void cell::replication_thread( replication_structure* data )
{
	for (;;)
	{
		if ( data->cells.empty() == true )
		{
			return;
		}

		Sleep( data->rate );

		data->cells.push_back( data->target_cell );

		for ( int i = 0; i < data->cells.size(); i++ )
		{
			if ( data->cells.empty() == false )
			{
				data->cells.at( i ).telomere.length -= 0.01f;
			}
		}
	}
}


void cell::replicate( cell target_cell, vector <cell>& cells, int rate = 10000 )
{
	replication_structure data{ target_cell, cells, rate };
	CreateThread( nullptr, 0, (LPTHREAD_START_ROUTINE)( replication_thread ), &data, 0, nullptr );
}


cell cell::base_cell( int chromosome_count, string sequence )
{
	cell basic_cell{};

	for ( int j = 0; j < chromosome_count / 2; j++ )
	{
		basic_cell.nucleus.chromosome[j].dna.HE1.allele1 = sequence.at( 0 );
		basic_cell.nucleus.chromosome[j].dna.HE1.allele2 = sequence.at( 1 );
		basic_cell.nucleus.chromosome[j].dna.HE1.allele3 = sequence.at( 2 );
		basic_cell.nucleus.chromosome[j].dna.HE1.allele4 = sequence.at( 3 );

		basic_cell.nucleus.chromosome[j].dna.ST1.allele1 = sequence.at( 4 );
		basic_cell.nucleus.chromosome[j].dna.ST1.allele2 = sequence.at( 5 );
		basic_cell.nucleus.chromosome[j].dna.ST1.allele3 = sequence.at( 6 );
		basic_cell.nucleus.chromosome[j].dna.ST1.allele4 = sequence.at( 7 );

		basic_cell.nucleus.chromosome[j].dna.IN1.allele1 = sequence.at( 8 );
		basic_cell.nucleus.chromosome[j].dna.IN1.allele2 = sequence.at( 9 );
		basic_cell.nucleus.chromosome[j].dna.IN1.allele3 = sequence.at( 10 );
		basic_cell.nucleus.chromosome[j].dna.IN1.allele4 = sequence.at( 11 );

		basic_cell.nucleus.chromosome[j].dna.AP1.allele1 = sequence.at( 12 );
		basic_cell.nucleus.chromosome[j].dna.AP1.allele2 = sequence.at( 13 );
		basic_cell.nucleus.chromosome[j].dna.AP1.allele3 = sequence.at( 14 );
		basic_cell.nucleus.chromosome[j].dna.AP1.allele4 = sequence.at( 15 );
	}

	return basic_cell;
}


cell cell::make_cell( int chromosome_count, string sequence )
{
	cell custom_cell{};

	for ( int j = 0; j < chromosome_count / 2; j++ )
	{
		custom_cell.nucleus.chromosome[j].dna.HE1.allele1 = sequence.at( 0 );
		custom_cell.nucleus.chromosome[j].dna.HE1.allele2 = sequence.at( 1 );
		custom_cell.nucleus.chromosome[j].dna.HE1.allele3 = sequence.at( 2 );
		custom_cell.nucleus.chromosome[j].dna.HE1.allele4 = sequence.at( 3 );

		custom_cell.nucleus.chromosome[j].dna.ST1.allele1 = sequence.at( 4 );
		custom_cell.nucleus.chromosome[j].dna.ST1.allele2 = sequence.at( 5 );
		custom_cell.nucleus.chromosome[j].dna.ST1.allele3 = sequence.at( 6 );
		custom_cell.nucleus.chromosome[j].dna.ST1.allele4 = sequence.at( 7 );

		custom_cell.nucleus.chromosome[j].dna.IN1.allele1 = sequence.at( 8 );
		custom_cell.nucleus.chromosome[j].dna.IN1.allele2 = sequence.at( 9 );
		custom_cell.nucleus.chromosome[j].dna.IN1.allele3 = sequence.at( 10 );
		custom_cell.nucleus.chromosome[j].dna.IN1.allele4 = sequence.at( 11 );

		custom_cell.nucleus.chromosome[j].dna.AP1.allele1 = sequence.at( 12 );
		custom_cell.nucleus.chromosome[j].dna.AP1.allele2 = sequence.at( 13 );
		custom_cell.nucleus.chromosome[j].dna.AP1.allele3 = sequence.at( 14 );
		custom_cell.nucleus.chromosome[j].dna.AP1.allele4 = sequence.at( 15 );
	}
}