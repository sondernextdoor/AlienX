#pragma once
#include "cell.h"
#include "biology.h"


class alien
{
public:

	int allele_max{ 4 };
	int gene_count{ 4 };
	int chromosome_count{ 46 };
	float standard_telomere_length{ 1000.0f };
	string standard_sequence{ "GGAACCAAXXAAACCA" };
        string species{};
	std::tuple<float, float> height_range;
	std::tuple<float, float> weight_range;


	float health;
	float strength;
	float intelligence;
	float height;
	float weight;
	string skin;
        string color;
        string dna_sequence;
        vector <cell> cells;
        body anatomy;


	void design( alien& newborn );
	static alien create();
	static int super_gene_carrier( alien subject );
        string calculate_color();
        std::string representation() const;
	static vector <alien> create( int count );
	alien();
};


class grey : public alien
{
public:

        grey()
        {
                this->species = "Grey";

		std::get<0>( this->height_range ) = 4.0f;
		std::get<1>( this->height_range ) = 7.0f;
		std::get<0>( this->weight_range ) = 80.0f;
		std::get<1>( this->weight_range ) = 200.0f;
	}
};


class reptilian : public alien 
{
public:

        reptilian()
        {
                this->species = "Reptilian";
		this->standard_sequence = "GGAACCAAXXAATTGG";

		std::get<0>( this->height_range ) = 6.0f;
		std::get<1>( this->height_range ) = 9.0f;
		std::get<0>( this->weight_range ) = 200.0f;
		std::get<1>( this->weight_range ) = 320.0f;
	}
};
