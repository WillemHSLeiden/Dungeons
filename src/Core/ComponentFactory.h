#pragma once
#include <string>
#include <unordered_map>

#ifdef BUILD_DLL
#define DLL_INTERFACE __declspec(dllexport)
#else
#define DLL_INTERFACE __declspec(dllimport)
#endif

class Component;

typedef Component* (*componentInstanceGenerator)();

class ComponentFactory {
public:
	DLL_INTERFACE static ComponentFactory& get();

	DLL_INTERFACE const char** getPrefabs(int& count);
	DLL_INTERFACE Component* getPrefab(std::string typeName);
	DLL_INTERFACE bool registerGenerator(const char* typeName, const componentInstanceGenerator& funcCreate);

private:
	ComponentFactory() {};
	ComponentFactory(const ComponentFactory&);
	~ComponentFactory() {};

	std::unordered_map<std::string, componentInstanceGenerator> m_generators;
};

