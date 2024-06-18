#pragma once

#include <map>
#include <assert.h>

namespace Factory
{
	template <typename ID, typename Class>
	class ComponentFactory
	{
	private:
		ComponentFactory() = default;
		virtual ~ComponentFactory() = default;

	private:
		static  void   assign(const ID&, const Class*);
	public:
		static  Class* create(const ID&);

	private:
		typedef std::map<ID, const Class*> FactoryMap;

		static  FactoryMap& getMap();

	private:
		friend Class;
	};

#include "ComponentFactory.hpp"
}