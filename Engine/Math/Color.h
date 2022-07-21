#pragma once
#include <cstdint>

namespace Solas
{
	struct Color
	{
		uint8_t r, g, b, a;

		friend std::istream& operator >> (std::istream& stream, Color& color);
	};

	inline std::istream& operator >> (std::istream& stream, Color& Color)
	{
		std::string line;
		std::getline(stream, line);
		std::string str;

		// line: { Color.r, Color.g, Color.b ;}


		// Red
		str = line.substr(line.find("{") + 1, line.find(",") - (line.find("{") + 1)); // Fixed Wren's Havoc
		Color.r = (uint8_t)(std::stof(str) * 255); 

		// setting line to another sub section of the string to read green and blue 
		line = line.substr(line.find(",") + 1);
		// line: #g, #b } 

		// Green 
		str = line.substr(line.find(" ") + 1, line.find(",") - (line.find(" ") + 1)); // Fixed Wren's Havoc
		Color.g = (uint8_t)(std::stof(str) * 255);

		line = line.substr(line.find(",") + 1);

		// Blue 
		str = line.substr(line.find(" ") + 1, line.find("}") - (line.find(" ") + 1)); // Fixed Wren's Havoc
		Color.b = (uint8_t)(std::stof(str) * 255);

		// default alpha to 255 
		Color.a = 255;

		return stream;
	}
}
