#include "disease.h"
#include <iomanip>

int main()
{	
	auto aliens = alien::create( 1000 );

	for ( int i = 0; i < aliens.size(); i++ )
	{
		std::cout << "Health: " << aliens.at( i ).health << std::endl;
		std::cout << "Strength: " << aliens.at( i ).strength << std::endl;
		std::cout << "Intelligence: " << aliens.at( i ).intelligence << std::endl;
                std::cout << "Species: " << aliens.at( i ).species << std::endl;
		std::cout << "Color: " << aliens.at( i ).color << std::endl;
		std::cout << "Height: " << std::fixed << std::setprecision(1) << aliens.at( i ).height << std::endl;
		std::cout << "Weight: " << std::fixed << std::setprecision(1) << aliens.at( i ).weight << std::endl;
		std::cout << "DNA Sequence: " << aliens.at( i ).dna_sequence << std::endl << std::endl;

		if ( int super_gene{ alien::super_gene_carrier( aliens.at( i ) ) } )
		{
				std::cout << "[+] Genetic Super Carrier; Gene " << super_gene << std::endl << std::endl;
				getchar();
		}
	}

	getchar();
}
