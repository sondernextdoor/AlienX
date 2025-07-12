#include "disease.h"
#include "physics.h"
#include <iomanip>
#include "disease.h"
#include "physics.h"
#include <iomanip>

int main()
{	
	auto aliens = alien::create( 1000 );

        photon light{550.0f, 1.0f};
        phonon sound{2.0f, 1.0f};
        odoron scent{5.0f, 1.0f};
        for ( int i = 0; i < aliens.size(); i++ )
        {
                std::cout << aliens.at(i).representation();
                std::cout << "Health: " << aliens.at( i ).health << std::endl;
		std::cout << "Strength: " << aliens.at( i ).strength << std::endl;
		std::cout << "Intelligence: " << aliens.at( i ).intelligence << std::endl;
                std::cout << "Species: " << aliens.at( i ).species << std::endl;
        photon light{550.0f, 1.0f};
        phonon sound{2.0f, 1.0f};
        odoron scent{5.0f, 1.0f};

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

                for (const auto& org : aliens.at(i).anatomy.organs)
                {
                        if (auto ey = dynamic_cast<eye*>(org.get()))
                        {
                                auto signal = ey->see(light);
                                std::cout << "Vision signal: " << signal[0] << ", " << signal[1] << std::endl;
                        }
                        if (auto ea = dynamic_cast<ear*>(org.get()))
                        {
                                auto audio = ea->hear(sound);
                                std::cout << "Audio signal: " << audio[0] << ", " << audio[1] << std::endl;
                        }
                        if (auto no = dynamic_cast<nose*>(org.get()))
                        {
                                auto smell = no->smell(scent);
                                std::cout << "Olfactory signal: " << smell[0] << ", " << smell[1] << std::endl;
                        }
                }
        }

	getchar();
}
                if ( int super_gene{ alien::super_gene_carrier( aliens.at( i ) ) } )
                {
                                std::cout << "[+] Genetic Super Carrier; Gene " << super_gene << std::endl << std::endl;
                                getchar();
                }

                for (const auto& org : aliens.at(i).anatomy.organs)
                {
                        if (auto ey = dynamic_cast<eye*>(org.get()))
                        {
                                auto signal = ey->see(light);
                                std::cout << "Vision signal: " << signal[0] << ", " << signal[1] << std::endl;
                        }
                        if (auto ea = dynamic_cast<ear*>(org.get()))
                        {
                                auto audio = ea->hear(sound);
                                std::cout << "Audio signal: " << audio[0] << ", " << audio[1] << std::endl;
                        }
                        if (auto no = dynamic_cast<nose*>(org.get()))
                        {
                                auto smell = no->smell(scent);
                                std::cout << "Olfactory signal: " << smell[0] << ", " << smell[1] << std::endl;
                                break;
                        }
                }
        }

	getchar();
}
