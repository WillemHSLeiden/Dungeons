#include "ComponentFactory.h"

ComponentFactory& ComponentFactory::get() {
	static ComponentFactory instance;
	return instance;
}

const char** ComponentFactory::getPrefabs(int& count) {
	count = m_generators.size();
	const char** arrayHead = new const char* [count];

	int i = 0;
	for (auto g : m_generators) {
		size_t bufferSize = g.first.length() + 1;
		char* generatorIdBuffer = new char[bufferSize];
		strncpy_s(generatorIdBuffer, bufferSize, g.first.c_str(), g.first.length());
		arrayHead[i++] = generatorIdBuffer;
	}

	return arrayHead;
}

Component* ComponentFactory::getPrefab(std::string typeName) {
	auto it = m_generators.find(typeName);
	if (it != m_generators.end()) {
		return it->second();
	}
	return nullptr;
}

bool ComponentFactory::registerGenerator(const char* typeName, const componentInstanceGenerator& funcCreate) {
	return m_generators.insert(std::make_pair(typeName, funcCreate)).second;
}