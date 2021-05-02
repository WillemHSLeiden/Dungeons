#pragma once

#include <fstream>
#include <string>
#include "json.hpp"

using json = nlohmann::json;

class JsonManager {
public:
	static json LoadJson(std::string jsonFile) {
		std::ifstream ifs(jsonFile, std::ifstream::in);
		json j = json::parse(ifs);

		return j;
	}
};
