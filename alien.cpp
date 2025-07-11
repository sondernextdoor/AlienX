#include "alien.h"


void alien::design( alien& newborn )
{
	if ( newborn.dna_sequence.empty() != true )
	{
		return;
	}


	vector <int> macro_variation_array{ random_integer_array( 4, 0, 20 ) };
	vector <int> micro_variation_array{ random_integer_array( 3, 0, 20 ) };
        int super_gene{ random_integer( 0, 1000 ) };
        int species_choice{ random_integer( 0, 4) };
        int random_height{ random_integer( 0, 20 ) };
        int random_weight{ random_integer( 0, 20 ) };


        if ( species_choice == 4 )
	{
		newborn = reptilian();
	} 
	else
	{
		newborn = grey();
	}


	cell base_cell{ cell::base_cell( newborn.chromosome_count, newborn.standard_sequence ) };


        for ( int i = 0; i < 1000; i++ )
        {
                cells.push_back( base_cell );
        }

        bool intelligence_super = (super_gene == 999);
        bool health_super = (super_gene == 444);
        bool strength_super = (super_gene == 777);
        bool lung_super = (super_gene == 333);
        bool liver_super = (super_gene == 111);
        bool kidney_super = (super_gene == 222);
        bool eye_super = (super_gene == 888);
        bool skin_super = (super_gene == 555);

        std::shared_ptr<brain> brain_ptr = std::make_shared<brain>(intelligence_super);
        std::shared_ptr<heart> heart_ptr = std::make_shared<heart>(health_super);
        std::shared_ptr<muscle> muscle_ptr = std::make_shared<muscle>(strength_super);
        std::shared_ptr<lung> lung_ptr = std::make_shared<lung>(lung_super);
        std::shared_ptr<liver> liver_ptr = std::make_shared<liver>(liver_super);
        std::shared_ptr<kidney> kidney_ptr = std::make_shared<kidney>(kidney_super);
        std::shared_ptr<eye> eye_ptr = std::make_shared<eye>(eye_super);
        std::shared_ptr<epidermis> skin_ptr = std::make_shared<epidermis>(skin_super);

        tissue neural{"Neural"};
        tissue cardiac{"Cardiac"};
        tissue muscular{"Muscle"};
        tissue pulmonary{"Pulmonary"};
        tissue hepatic{"Hepatic"};
        tissue renal{"Renal"};
        tissue ocular{"Ocular"};
        tissue dermal{"Dermal"};

        for (int i = 0; i < cells.size(); ++i)
        {
                if (i < 150)
                        neural.cells.push_back(cells[i]);
                else if (i < 300)
                        cardiac.cells.push_back(cells[i]);
                else if (i < 450)
                        muscular.cells.push_back(cells[i]);
                else if (i < 600)
                        pulmonary.cells.push_back(cells[i]);
                else if (i < 700)
                        hepatic.cells.push_back(cells[i]);
                else if (i < 800)
                        renal.cells.push_back(cells[i]);
                else if (i < 900)
                        ocular.cells.push_back(cells[i]);
                else
                        dermal.cells.push_back(cells[i]);
        }

        brain_ptr->tissues.push_back(neural);
        heart_ptr->tissues.push_back(cardiac);
        muscle_ptr->tissues.push_back(muscular);
        lung_ptr->tissues.push_back(pulmonary);
        liver_ptr->tissues.push_back(hepatic);
        kidney_ptr->tissues.push_back(renal);
        eye_ptr->tissues.push_back(ocular);
        skin_ptr->tissues.push_back(dermal);

        newborn.anatomy.organs.push_back(brain_ptr);
        newborn.anatomy.organs.push_back(heart_ptr);
        newborn.anatomy.organs.push_back(muscle_ptr);
        newborn.anatomy.organs.push_back(lung_ptr);
        newborn.anatomy.organs.push_back(liver_ptr);
        newborn.anatomy.organs.push_back(kidney_ptr);
        newborn.anatomy.organs.push_back(eye_ptr);
        newborn.anatomy.organs.push_back(skin_ptr);


	char height_allele{
		( random_height <= 16 ? 'G' : 
			( random_height == 17 ? 'A' : 
				( random_height == 18 ? 'C' : 
					( random_height == 19 ? 'T' : 
						( random_height == 20 ? 'X' : 'G' ) )))) 
	};


	char weight_allele{
		( random_weight <= 16 ? 'G' : 
			( random_weight == 17 ? 'A' : 
				( random_weight == 18 ? 'C' : 
					( random_weight == 19 ? 'T' : 
						( random_weight == 20 ? 'X' : 'G' ) ))))
	};


	cell::set_height_gene( newborn.cells, newborn.chromosome_count, height_allele );
	cell::set_weight_gene( newborn.cells, newborn.chromosome_count, weight_allele );


	newborn.height = ( 
		height_allele == 'G' ? random_float( std::get<0>( newborn.height_range ) + 1.0f, std::get<0>( newborn.height_range ) + 1.5f ) : (
			height_allele == 'A' ? random_float( std::get<0>( newborn.height_range ), std::get<0>( newborn.height_range ) + 0.5f ) : (
				height_allele == 'C' ? random_float( std::get<0>( newborn.height_range ) + 0.5f, std::get<0>( newborn.height_range ) + 1.0f ) : (
					height_allele == 'T' ? random_float( std::get<0>( newborn.height_range ) + 1.5f, std::get<0>( newborn.height_range ) + 2.0f ) : (
						height_allele == 'X' ? random_float( std::get<0>( newborn.height_range ) + 2.0f, std::get<1>( newborn.height_range ) ) : random_float( 2.5f, 10.0f )
					)
				)
			)
		)
	);


	newborn.weight = ( 
		weight_allele == 'G' ? random_float( std::get<0>( newborn.weight_range ) + 30.0f, std::get<0>( newborn.weight_range ) + 60.0f ) : (
			weight_allele == 'A' ? random_float( std::get<0>( newborn.weight_range ), std::get<0>( newborn.weight_range ) + 10.0f ) : (
				weight_allele == 'C' ? random_float( std::get<0>( newborn.weight_range ) + 10.0f, std::get<0>( newborn.weight_range ) + 40.0f ) : (
					weight_allele == 'T' ? random_float( std::get<0>( newborn.weight_range ) + 60.0f, std::get<0>( newborn.weight_range ) + 80.0f ) : (
						weight_allele == 'X' ? random_float( std::get<0>( newborn.weight_range ) + 80.0f, std::get<1>( newborn.weight_range ) ) : random_float( 60.0f, 400.0f )
					)
				)
			)
		)
	);


	if ( super_gene == 444 )
	{
		cell::set_health_gene( newborn.cells, newborn.chromosome_count, "GGGG" );
	}
	else if ( macro_variation_array.at( 0 ) == 1 )
	{
		cell::set_health_gene( newborn.cells, newborn.chromosome_count, "GGGA" );
	}
	else
	{
		micro_variation_array.at( 0 ) == 5 ? cell::set_health_gene( newborn.cells, newborn.chromosome_count, "GAAA" ) : cell::set_health_gene( newborn.cells, newborn.chromosome_count, "GGAA" );
	}


	if ( super_gene == 777 )
	{
		cell::set_strength_gene( newborn.cells, newborn.chromosome_count, "CCCC" );
	}
	else if ( macro_variation_array.at( 1 ) == 2 )
	{
		cell::set_strength_gene( newborn.cells, newborn.chromosome_count, "CCCA" );
	}
	else
	{
		micro_variation_array.at( 1 ) == 6 ? cell::set_strength_gene( newborn.cells, newborn.chromosome_count, "CCXA" ) : cell::set_strength_gene( newborn.cells, newborn.chromosome_count, "CCAA" );
	}


	if ( super_gene == 999 )
	{
		cell::set_intelligence_gene( newborn.cells, newborn.chromosome_count, "XXXX" );
	}
	else if ( macro_variation_array.at( 2 ) == 3 )
	{
		cell::set_intelligence_gene( newborn.cells, newborn.chromosome_count, "XXXA" );
	}
	else
	{
		micro_variation_array.at( 2 ) == 7 ? cell::set_intelligence_gene( newborn.cells, newborn.chromosome_count, "XXCA" ) : cell::set_intelligence_gene( newborn.cells, newborn.chromosome_count, "XXAA" );
	}


	newborn.dna_sequence.append(
		newborn.cells.at( 0 ).nucleus_data.chromosome[0].dna.HE1.allele1
			).append(
				newborn.cells.at( 0 ).nucleus_data.chromosome[0].dna.HE1.allele2
					).append(
						newborn.cells.at( 0 ).nucleus_data.chromosome[0].dna.HE1.allele3
							).append(
								newborn.cells.at( 0 ).nucleus_data.chromosome[0].dna.HE1.allele4
								);

	newborn.dna_sequence.append(
		newborn.cells.at( 0 ).nucleus_data.chromosome[0].dna.ST1.allele1
			).append(
				newborn.cells.at( 0 ).nucleus_data.chromosome[0].dna.ST1.allele2
					).append(
						newborn.cells.at( 0 ).nucleus_data.chromosome[0].dna.ST1.allele3
							).append(
								newborn.cells.at( 0 ).nucleus_data.chromosome[0].dna.ST1.allele4
								);

	newborn.dna_sequence.append(
		newborn.cells.at( 0 ).nucleus_data.chromosome[0].dna.IN1.allele1
			).append(
				newborn.cells.at( 0 ).nucleus_data.chromosome[0].dna.IN1.allele2
					).append(
						newborn.cells.at( 0 ).nucleus_data.chromosome[0].dna.IN1.allele3
							).append(
								newborn.cells.at( 0 ).nucleus_data.chromosome[0].dna.IN1.allele4
								);

	newborn.dna_sequence.append(
		newborn.cells.at( 0 ).nucleus_data.chromosome[0].dna.AP1.allele1
			).append(
				newborn.cells.at( 0 ).nucleus_data.chromosome[0].dna.AP1.allele2
					).append(
						newborn.cells.at( 0 ).nucleus_data.chromosome[0].dna.AP1.allele3
							).append(
								newborn.cells.at( 0 ).nucleus_data.chromosome[0].dna.AP1.allele4
								);
}


alien alien::create()
{
	alien newborn{};
	signed int health_addition{ 0 };
	signed int strength_addition{ 0 };
	signed int intelligence_addition{ 0 };


	newborn.design( newborn );


	for ( int i = 0; i < newborn.allele_max * newborn.gene_count; i++ )
	{
		if ( newborn.dna_sequence.at( i ) != newborn.standard_sequence.at( i ) )
		{
			switch ( int section{ ( i / newborn.gene_count ) + 1 } )
			{
				case 1: 
				{ 
					health_addition = ( newborn.dna_sequence.at( i ) == 'G' ? 50 : -50 ); 
				} break;


				case 2:
				{
					strength_addition = ( newborn.dna_sequence.at( i ) == 'C' ? 5 : -5 ); 

					if ( newborn.dna_sequence.at( i ) == 'X' )
					{
						intelligence_addition += 20;
					}

				} break;


				case 3: { 

					intelligence_addition = ( newborn.dna_sequence.at( i ) == 'X' ? 50 : -50 ); 

					if ( newborn.dna_sequence.at( i ) == 'G' )
					{
						health_addition += 20;
					}
					else if ( newborn.dna_sequence.at( i ) == 'C' )
					{
						strength_addition += 3;
					}

				} break;
			}
		}
	}

	newborn.health = 100 + health_addition + ( newborn.cells.at( 0 ).nucleus_data.chromosome[0].dna.HE1.allele4.at( 0 ) == 'G' ? 100 : 0 );
	newborn.strength = 10 + strength_addition + ( newborn.cells.at( 0 ).nucleus_data.chromosome[0].dna.ST1.allele4.at( 0 ) == 'C' ? 10 : 0 );
	newborn.intelligence = 100 + intelligence_addition + ( newborn.cells.at( 0 ).nucleus_data.chromosome[0].dna.IN1.allele4.at( 0 ) == 'X' ? 100 : 0 );
	newborn.color = newborn.calculate_color();

	return newborn;
}


int alien::super_gene_carrier( alien subject )
{
        if ( subject.cells.at( 0 ).nucleus_data.chromosome[0].dna.HE1.allele4.at( 0 ) == 'G' )
        {
                return 444;
        }
		
	if ( subject.cells.at( 0 ).nucleus_data.chromosome[0].dna.ST1.allele4.at( 0 ) == 'C' )
	{
		return 777;
	}
		
        if ( subject.cells.at( 0 ).nucleus_data.chromosome[0].dna.IN1.allele4.at( 0 ) == 'X' )
        {
                return 999;
        }

        for (const auto& org : subject.anatomy.organs)
        {
                if (auto lu = dynamic_cast<lung*>(org.get()); lu && lu->capacity > 1000)
                        return 333;
                if (auto li = dynamic_cast<liver*>(org.get()); li && li->detox_level > 1)
                        return 111;
                if (auto ki = dynamic_cast<kidney*>(org.get()); ki && ki->filter_rate > 1)
                        return 222;
                if (auto ey = dynamic_cast<eye*>(org.get()); ey && ey->night_vision)
                        return 888;
                if (auto sk = dynamic_cast<epidermis*>(org.get()); sk && sk->camouflage)
                        return 555;
        }

        return false;
}


string alien::calculate_color()
{	
	if ( this->cells.at( 0 ).nucleus_data.chromosome[0].dna.AP1.allele1.compare( "T" ) == 0 )
	{
		return "Green";
	}

	if ( this->cells.at( 0 ).nucleus_data.chromosome[0].dna.AP1.allele1.compare( "A" ) == 0 )
	{
		return "Grey";
	}

	if ( this->cells.at( 0 ).nucleus_data.chromosome[0].dna.AP1.allele1.compare( "C" ) == 0 )
	{
		return "Red";
	}

	if ( this->cells.at( 0 ).nucleus_data.chromosome[0].dna.AP1.allele1.compare( "G" ) == 0 )
	{
		return "Black";
	}

	if ( this->cells.at( 0 ).nucleus_data.chromosome[0].dna.AP1.allele1.compare( "X" ) == 0 )
	{
		return "Translucent";
	}

	return "Unknown";
}


vector <alien> alien::create( int count )
{
	vector <alien> aliens{};

	for ( int i = 0; i < count; i++ )
	{
		aliens.push_back( create() );
	}

	return aliens;
}


alien::alien()
{
		
}
