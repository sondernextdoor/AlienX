#pragma once
#include "includes.h"

/*
	A = standard allele
	C = contributes to strength; Presence with X reduces strength
	G = contributes to health; presence with 3 A alleles reduces health
	T = standard allele
	X = contributes to intelligence. presence with C reduces strength
	

	appearance gene ( standard = ACCA )

	allele 1 = color ( T = green, A = grey, C = red, G = black, X = blue )
	allele 2 = height ( A = tiny, C = short, G = average, T = tall, X = giant )
	allele 3 = weight ( A = boney, C = skinny, G = average, T = fat, X = obese )
	allele 4 = skin ( A = standard, C = slimy, G = scaley, T = bark, X = translucent )

	4-7 ( height )
	80-200 ( weight );

	tiny = 4 - 4.5
	short = 4.5 - 5
	average = 5 - 5.5
	tall = 5.5 - 6
	giant = 6 - 7

	boney = 80-90
	skinny = 90-110
	average = 110-140
	fat = 140-160
	obese = 160-200
*/


struct replication_structure;


class telomere
{
public:

	float length{ 1000.0f };
};


class gene
{
public:

	string allele1;
	string allele2;
	string allele3;
	string allele4;
};


class DNA
{
public:

	gene HE1; // Health Gene 1
	gene ST1; // Strength Gene 1
	gene IN1; // Intelligence Gene 1
	gene AP1; // Appearance Gene 1
};


class chromosome_pair
{
public:

	DNA dna;
	chromosome_pair* chromosome2 = this;
};


class nucleus
{
public:

	chromosome_pair chromosome[23];
};


class cell
{
public:


	nucleus nucleus;
	telomere telomere;

	static void set_all_genes(  vector <cell>& cells, int chromosome_count, string sequence );
	static void set_health_gene(  vector <cell>& cells, int chromosome_count, string sequence );
	static void set_strength_gene( vector <cell>& cells, int chromosome_count, string sequence );
	static void set_intelligence_gene( vector <cell>& cells, int chromosome_count, string sequence );
	static void set_appearance_gene( vector <cell>& cells, int chromosome_count, string sequence );
	static void set_height_gene( vector <cell>& cells, int chromosome_count, char allele );
	static void set_weight_gene( vector <cell>& cells, int chromosome_count, char allele );
	static void replication_thread( replication_structure* data );
	static void replicate( cell target_cell, vector<cell>& cells, int rate );
	static cell base_cell( int chromosome_count, string sequence );
	static cell make_cell( int chromosome_count, string sequence );
};


struct replication_structure
{
	cell target_cell;
	vector <cell>& cells;
	int rate;
};