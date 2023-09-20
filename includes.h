#pragma once

#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <random>
#include <thread>
#include <chrono>
#include <string_view>


using std::string;
using std::vector;


__inline int random_integer( int min = 0, int max = 100 ) 
{
	std::random_device random_device{};
	std::mt19937 rng( random_device() );
	std::uniform_int_distribution<> dist( min, max );

	return dist( rng );
}


__inline vector <int> random_integer_array( int length, int min = 0, int max = 100 )
{
	vector <int> integer_array{};

	for ( int i = 0; i < length; i++ )
	{
		integer_array.push_back( random_integer( min, max ) );
	}

	return integer_array;
}


__inline float random_float( float min = 0.0f, float max = 100.0f ) 
{
	std::random_device random_device{};
	std::mt19937 rng( random_device() );
	std::uniform_real_distribution<> dist( min, max );

	return dist( rng );
}


__inline vector <float> random_float_array( int length, float min = 0.0f, float max = 100.0f )
{
	vector <float> float_array{};

	for ( int i = 0; i < length; i++ )
	{
		float_array.push_back( random_float( min, max ) );
	}

	return float_array;
}